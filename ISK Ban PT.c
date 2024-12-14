#include <stdio.h>

double calculateDosenTetap(int NDTPS){
    if (NDTPS >= 6){
        return 4;
    } else if (NDTPS >= 3){
        return (2.0 * NDTPS) / 3.0;
    } else{
        return 0;
    }
}

double calculateJabatanAkademik(int NDGB, int NDLK, int NDTPS){
    double PGBLK = ((NDGB + NDLK) * 100.0) / NDTPS;
    if (PGBLK >= 70){
        return 4;
    } else{
        return 2 + ((20.0 * PGBLK) / 7.0);
    }
}

double calculateKurikulum(int keterlibatan, int kesesuaian, int ketepatan){
    return (keterlibatan + (2 * kesesuaian) + (2 * ketepatan)) / 5.0;
}

double calculatePenjaminanMutu(int aspek){
    if (aspek >= 5){
        return 4;
    } else if (aspek >= 4){
        return 3;
    } else if (aspek >= 3){
        return 2;
    } else if (aspek >= 2){
        return 1;
    } else{
        return 0;
    }
}

double calculateTracerStudy(int pelaksanaan, int kesesuaian, int kepuasan){
    return (pelaksanaan + kesesuaian + kepuasan) / 3.0;
}

double calculatePublication(int RI, int RN, int RL){
    if (RI >= 2){
        return 4;
    } else if (RI < 2 && RN >= 20){
        return 3 + (RI / 2.0);
    } else if (RI == 0 && RN == 0 && RL >= 70){
        return 2;
    } else{
        return 0;
    }
}

int main(){
    double totalScore = 0;

    int NDTPS;
    printf("Masukkan jumlah Dosen Tetap (NDTPS): ");
    scanf("%d", &NDTPS);
    totalScore += calculateDosenTetap(NDTPS);

    int NDGB, NDLK;
    printf("Masukkan jumlah Dosen dengan Jabatan Guru Besar (NDGB): ");
    scanf("%d", &NDGB);
    printf("Masukkan jumlah Dosen dengan Jabatan Lektor Kepala (NDLK): ");
    scanf("%d", &NDLK);
    totalScore += calculateJabatanAkademik(NDGB, NDLK, NDTPS);

    int keterlibatan, kesesuaian, ketepatan;
    printf("Masukkan skor keterlibatan pemangku kepentingan (1-4): ");
    scanf("%d", &keterlibatan);
    printf("Masukkan skor kesesuaian capaian pembelajaran (1-4): ");
    scanf("%d", &kesesuaian);
    printf("Masukkan skor ketepatan struktur kurikulum (1-4): ");
    scanf("%d", &ketepatan);
    totalScore += calculateKurikulum(keterlibatan, kesesuaian, ketepatan);

    int aspek;
    printf("Masukkan jumlah aspek yang dipenuhi dalam Penjaminan Mutu (1-5): ");
    scanf("%d", &aspek);
    totalScore += calculatePenjaminanMutu(aspek);

    int pelaksanaan, kesesuaianTracer, kepuasan;
    printf("Masukkan skor pelaksanaan tracer study (1-4): ");
    scanf("%d", &pelaksanaan);
    printf("Masukkan skor kesesuaian bidang kerja lulusan (1-4): ");
    scanf("%d", &kesesuaianTracer);
    printf("Masukkan skor kepuasan pengguna (1-4): ");
    scanf("%d", &kepuasan);
    totalScore += calculateTracerStudy(pelaksanaan, kesesuaianTracer, kepuasan);

    int RI, RN, RL;
    printf("Masukkan jumlah publikasi ilmiah (RI): ");
    scanf("%d", &RI);
    printf("Masukkan jumlah publikasi lain (RN): ");
    scanf("%d", &RN);
    printf("Masukkan skor relevansi publikasi (RL): ");
    scanf("%d", &RL);
    totalScore += calculatePublication(RI, RN, RL);

    printf("Total ISK Ban PT untuk Program Magister: %.2f\n", totalScore);

    return 0;
}
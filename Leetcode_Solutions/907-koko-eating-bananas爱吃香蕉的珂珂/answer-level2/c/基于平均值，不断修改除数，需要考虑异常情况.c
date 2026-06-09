int cmp(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}
int EatingHours(int* piles, int pilesSize, int spped) {
    int num = 0;
    int i;
    if (spped == 0) {
        return 0xfffffff;
    }
    for (i = (pilesSize - 1); i >=0; i--) {
        if (piles[i] <= spped) {
            num += (i + 1);
            break;
        }
        num += ((piles[i] + spped - 1) / spped);
    }
    return num;
}

int minEatingSpeed(int* piles, int pilesSize, int H) {
    int i;
    long long sum = 0;
    int avs;
    int hours;
    if (pilesSize == 0 || piles == NULL || H == 0) {
        return 0;
    }
    qsort(piles, pilesSize, sizeof(int), cmp);
    if (H == pilesSize) {
        return piles[pilesSize - 1];
    }
    for (i = 0; i < pilesSize; i++) {
        sum += piles[i];
    }
    if (sum <= H) {
        return 1;
    } 
    avs = sum / H;
    hours = EatingHours(piles, pilesSize, avs);
    if (hours > H) {
        while (hours > H) {
            avs++;
            hours = EatingHours(piles, pilesSize, avs);
            //printf("avs:%d,hours:%d\n", avs, hours);
        }
        return avs;
    }
    if (hours < H) {
        while (hours < H) {
            avs--;
            hours = EatingHours(piles, pilesSize, avs);
            //printf("avs:%d,hours:%d\n", avs, hours);
        }
    }
    while (hours == H) {
        avs--;
        hours = EatingHours(piles, pilesSize, avs);
    }
    return (avs + 1);
}
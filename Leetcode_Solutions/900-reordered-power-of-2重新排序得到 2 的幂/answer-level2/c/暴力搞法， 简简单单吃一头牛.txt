```
bool Check(int a, int b)
{
    int nums1[10] = {0};
    int nums2[10] = {0};

    while (a) {
        nums1[a % 10]++;
        a /= 10;
    }
    while (b) {
        nums2[b % 10]++;
        b /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (nums1[i] != nums2[i]) {
            return false;
        }
    }
    return true;
}

bool reorderedPowerOf2(int N)
{
    int mi[100 * 1024] = {0};
    int tag = 1;
    int total = 0;

    while (tag < 10 * 10000 * 10000) {
        mi[total] = tag;
        tag *= 2;
        total++;
    }
    for (int i = 0; i < total; i++) {
        if (Check(N, mi[i])) {
            return true;
        }
    }
    return false;
}
```

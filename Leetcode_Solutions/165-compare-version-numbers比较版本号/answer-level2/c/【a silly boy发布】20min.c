![BC0F9914-E72D-441B-8D67-8328C6A20CF0.jpeg](https://pic.leetcode-cn.com/4a2ebbeb4c0e43b62c23cddf03902366e7632806faeca1f2b12709ebf8f608b8-BC0F9914-E72D-441B-8D67-8328C6A20CF0.jpeg)

```
int compareVersion(char * version1, char * version2){
    int lenVersion1 = strlen(version1);
    int lenVersion2 = strlen(version2);
    int numDot = 0;
    long long int nums1_1 = 0;
    long long int nums1_2 = 0;
    long long int nums1_3 = 0;
    long long int nums1_4 = 0;
    long long int nums2_1 = 0;
    long long int nums2_2 = 0;
    long long int nums2_3 = 0;
    long long int nums2_4 = 0;
    int i;
    for (i = 0; i < lenVersion1; i++) {
        if (version1[i] == '.') {
            numDot++;
            continue;
        }
        switch (numDot) {
            case 0: 
                nums1_1 = nums1_1 * 10 + version1[i] - '0';
                break;
            case 1:
                nums1_2 = nums1_2 * 10 + version1[i] - '0';
                break;
            case 2:
                nums1_3 = nums1_3 * 10 + version1[i] - '0';
                break;
            case 3:
                nums1_4 = nums1_4 * 10 + version1[i] - '0';
                break;
        }
    }
    numDot = 0;
    for (i = 0; i < lenVersion2; i++) {
        if (version2[i] == '.') {
            numDot++;
            continue;
        }
        switch (numDot) {
            case 0: 
                nums2_1 = nums2_1 * 10 + version2[i] - '0';
                break;
            case 1:
                nums2_2 = nums2_2 * 10 + version2[i] - '0';
                break;
            case 2:
                nums2_3 = nums2_3 * 10 + version2[i] - '0';
                break;
            case 3:
                nums2_4 = nums2_4 * 10 + version2[i] - '0';
                break;
        }
    }
    printf("nums1_1: %lld, nums1_2: %lld, nums1_3: %lld, nums1_4: %lld\n", nums1_1, nums1_2, nums1_3, nums1_4);
    printf("nums2_1: %lld, nums2_2: %lld, nums2_3: %lld, nums2_4: %lld\n", nums2_1, nums2_2, nums2_3, nums2_4);
    if (nums1_1 < nums2_1) {
        return -1;
    }
    if ((nums1_1 == nums2_1) && (nums1_2 < nums2_2)) {
        return -1;
    }
    if ((nums1_1 == nums2_1) && (nums1_2 == nums2_2) && (nums1_3 < nums2_3)) {
        return -1;
    }
   if ((nums1_1 == nums2_1) && (nums1_2 == nums2_2) && (nums1_3 == nums2_3) && (nums1_4 < nums2_4)) {
        return -1;
    }
    if ((nums1_1 == nums2_1) && (nums1_2 == nums2_2) && (nums1_3 == nums2_3) && (nums1_4 == nums2_4)){
        return 0;
    }
    return 1; 
}
```

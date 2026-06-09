```
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    if ((nums1Size + nums2Size) % 2 == 0) {
        int fig = (nums1Size + nums2Size) / 2;
        long f1 = 0, f2 = 0;
        int num1;
        int num2;
        while (1) {
            if (f1 == nums1Size) {
                if (f1 + f2 == fig - 1) {
                    num1 = nums2[f2];
                }
                if (f1 + f2 == fig) {
                    num2 = nums2[f2];
                    break;
                }
            } else if (f2 == nums2Size) {
                if (f1 + f2 == fig - 1) {
                    num1 = nums1[f1];
                }
                if (f1 + f2 == fig) {
                    num2 = nums1[f1];
                    break;
                }
            } else {
                if (f1 + f2 == fig - 1) {
                    num1 = nums1[f1] > nums2[f2] ? nums2[f2] : nums1[f1];
                }
                if (f1 + f2 == fig) {
                    num2 = nums1[f1] > nums2[f2] ? nums2[f2] : nums1[f1];
                    break;
                }
            }

            if (f1 == nums1Size) {
                f2++;
            } else if (f2 == nums2Size) {
                f1++;
            } else if (nums1[f1] > nums2[f2]) {
                f2++;
            } else {
                f1++;
            }
        }
        return ((double) num1 + num2) / 2;
    } else {
        int fig = (nums1Size + nums2Size - 1) / 2;
        long f1 = 0, f2 = 0;
        int num2;
        while (1) {
            if (f1 == nums1Size) {
                if (f1 + f2 == fig) {
                    num2 = nums2[f2];
                    break;
                }
            } else if (f2 == nums2Size) {
                if (f1 + f2 == fig) {
                    num2 = nums1[f1];
                    break;
                }
            } else {
                if (f1 + f2 == fig) {
                    num2 = nums1[f1] > nums2[f2] ? nums2[f2] : nums1[f1];
                    break;
                }
            }

            if (f1 == nums1Size) {
                f2++;
            } else if (f2 == nums2Size) {
                f1++;
            } else if (nums1[f1] > nums2[f2]) {
                f2++;
            } else {
                f1++;
            }
        }
        return num2;
    }
}
```

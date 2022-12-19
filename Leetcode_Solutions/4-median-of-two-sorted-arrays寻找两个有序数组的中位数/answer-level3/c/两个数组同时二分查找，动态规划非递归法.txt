
![寻找两个有序数组的中位数.PNG](https://pic.leetcode-cn.com/7212b924f04186c754e414f551afc6140b6ec50bbb8691a24fa5ada6260f32da-%E5%AF%BB%E6%89%BE%E4%B8%A4%E4%B8%AA%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E4%B8%AD%E4%BD%8D%E6%95%B0.PNG)
    
```
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int mididx[2] = {0};
    int mid[2] = {0};
    int odd = (nums1Size + nums2Size) % 2;
    int tmpmid1 = 0;
    int tmpmid2 = 0;

    if (odd == 0) {
        mididx[0] = (nums1Size + nums2Size) / 2 - 1;
        mididx[1] = mididx[0] + 1;
    } else {
        mididx[0] = (nums1Size + nums2Size) / 2;
        mididx[1] = mididx[0];
    }
    
    while  (true) {
        if (nums1Size == 0) {
            mid[0] = nums2[mididx[0]];
            mid[1] = nums2[mididx[1]];
            break;
        }

        if (nums2Size == 0) {
            mid[0] = nums1[mididx[0]];
            mid[1] = nums1[mididx[1]];
            break;
        } 

        if (nums1[0] < nums2[0]) {
            tmpmid1 = nums1Size - 1;
            while (nums1[tmpmid1] > nums2[0]) {
                tmpmid1 /= 2;
            }
            if (mididx[0] <= tmpmid1) {
                mid[0] = nums1[mididx[0]];
                if (mididx[1] <= tmpmid1) {
                    mid[1] = nums1[mididx[1]];
                } else {
                    if (mididx[1] <= nums1Size - 1 && nums1[mididx[1]] < nums2[0]) {
                        mid[1] = nums1[mididx[1]];
                    } else {
                        mid[1] = nums2[0];
                    }
                }
                break;
            } else {
                nums1Size -= (tmpmid1 + 1);
                nums1 += (tmpmid1 + 1);
                mididx[0] -= (tmpmid1 + 1);
                mididx[1] -= (tmpmid1 + 1);
            }
        } else {
            tmpmid2 = nums2Size - 1;
            while (nums2[tmpmid2] > nums1[0]) {
                tmpmid2 /= 2;
            }
            if (mididx[0] <= tmpmid2) {
                mid[0] = nums2[mididx[0]];
                if (mididx[1] <= tmpmid2) {
                    mid[1] = nums2[mididx[1]];
                } else {
                    if (mididx[1] <= nums2Size - 1 && nums2[mididx[1]] < nums1[0]) {
                        mid[1] = nums2[mididx[1]];
                    } else {
                        mid[1] = nums1[0];
                    }
                }
                break;
            } else {
                nums2Size -= (tmpmid2 + 1);
                nums2 += (tmpmid2 + 1);
                mididx[0] -= (tmpmid2 + 1);
                mididx[1] -= (tmpmid2 + 1);
            }
        }
        
    }
```

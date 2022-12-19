### 解题思路
先把两个数组有序合并，然后取中位数。

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int allLen = nums1.length + nums2.length;
        int[] allNums = new int[allLen];

        // 两个数据为空，或者两个数组只有一个数
        if ((nums1.length + nums2.length) == 0) {
            return 0.0;
        }

        // 合并数组
        int curPos1 = 0;
        int curPos2 = 0;
        for (int i = 0; i < allLen; i++) {
            // 为allNums[i]赋值
            if ((curPos1 < nums1.length) && (curPos2 < nums2.length)) {
                if (nums1[curPos1] < nums2[curPos2]) {
                    allNums[i] = nums1[curPos1];
                    curPos1++;
                } else {
                    allNums[i] = nums2[curPos2];
                    curPos2++;
                }
            }
            // 有一个数据已经复制完了
            else if (curPos1 >= nums1.length) {
                // 复制数组2
                for (int j = 0; curPos2 < nums2.length; curPos2++, j++) {
                    allNums[i + j] = nums2[curPos2];
                }
                break;
            }
            else {
                // 复制数组1
                for (int j = 0; curPos1 < nums1.length; curPos1++, j++) {
                    allNums[i + j] = nums1[curPos1];
                }
                break;
            }
        }

        int singleFlag = allLen % 2;
        if (singleFlag == 1) {
            return allNums[allLen / 2];
        } else {
            return (allNums[allLen / 2] + allNums[(allLen / 2) - 1]) / 2.0;
        }

    }
}
```
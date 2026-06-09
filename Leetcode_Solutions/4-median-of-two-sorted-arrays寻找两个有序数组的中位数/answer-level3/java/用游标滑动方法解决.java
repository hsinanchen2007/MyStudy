
![image.png](https://pic.leetcode-cn.com/adf77c3a4d99e1924602958891be470553bc88e9d0057a805601c36b9c6cadf9-image.png)

直接上代码
```
public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        double result = 0;
        int cursor1 = 0;
        int cursor2 = 0;
        int[] newList = new int[nums1.length + nums2.length];
        int resCur = 0;
        while (cursor1 != nums1.length || cursor2 != nums2.length) {
            if(cursor1 == nums1.length){
                newList[resCur++] = nums2[cursor2];
                cursor2++;
                continue;
            }
            if(cursor2 == nums2.length){
                newList[resCur++] = nums1[cursor1];
                cursor1++;
                continue;
            }
            if(nums1[cursor1] > nums2[cursor2]){
                newList[resCur++] = nums2[cursor2];
                cursor2++;
            } else if(nums1[cursor1] < nums2[cursor2]){
                newList[resCur++] = nums1[cursor1];
                cursor1++;
            } else {
                newList[resCur++] = nums2[cursor2];
                newList[resCur++] = nums2[cursor2];
                cursor1++;
                cursor2++;
            }
        }

        if(newList.length % 2 == 1){
            result = newList[newList.length / 2];
        } else {
            result = (newList[newList.length / 2 - 1] + newList[newList.length / 2]) / 2.0;
        }
        return result;
    }
```

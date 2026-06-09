### 解题思路
归并排序在排序时 合并时顺便计个数
当left 和right 都已经排序好时
拷贝两半的数据时，当leftarr[i] > rightarr[j] 则构成了 j-ristart+1对逆序对
 因为leftarr[i] 一定比rightarr[j]左边的都大

### 代码

```java
class Solution {
    public int reversePairs(int[] nums) {
        if (nums.length==0) return 0;
        int left = 0, right = nums.length-1;
        int[] copy = Arrays.copyOf(nums, nums.length); //辅助空间
        return reversePairs(nums, copy, left, right); // 入口nums和copy是一致的，两个数组来回倒腾

    }
    int reversePairs(int[] nums, int[] copy, int left, int right) {
        if (left>= right) { //空或者单元素
            return 0;
        }
        int mid = left+(right-left)/2;
        int lpairs = reversePairs(copy, nums, left, mid); //排序nums
        int rpairs = reversePairs(copy, nums, mid+1, right);
        int li = mid,ri = right,ci=right;
        int count = 0;
        while (li>=left && ri>mid) {
            // 拷贝两边的较大值，仅当左边大于右边时计算两边之间的逆序对
            if (nums[li]>nums[ri]) {
                count += ri-mid;  //当前左边li可以构成 ri-mid个逆序对 比ri前面的都大
                copy[ci--] = nums[li--];
            } else {
                copy[ci--] = nums[ri--];
            }
        }
        while (li>=left) { //剩余小值都在左边，无需增加对数
            copy[ci--] = nums[li--];
        }
        while (ri>mid) { //说明左边所有值都比当前右边的大，每个右边的小值都有mid-left+1对,
            copy[ci--] = nums[ri--];
//            count += mid-left+1; //已经在left比较时加过了
        }
        return lpairs+rpairs+count;
    }
}
```
![image.png](https://pic.leetcode-cn.com/212a9782c67d55fa6f27a0a75ebe98a2b2629357f65bb0972a853f0fe311e0ba-image.png)

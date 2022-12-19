### 解题思路
此处撰写解题思路
采用二分法划分数字1~n，将其划分为1~m，和 m+1~n, 每次二分计算区间前半部分区间的数字在数组中出现的次数，若大于区间数字个数，则表示重复元素在此区间，继续二分，直到仅剩最后一个元素，即为重复元素
### 代码

```java
class Solution {
    public int findDuplicate(int[] nums) {
        int mid = 0; //求出1-n的中位数
        int start = 1;
        int end = nums.length - 1;
        while (start <= end) {
            mid = (end - start) / 2 + start;
            // 计算start-mid在数组出现的次数
            int count = countByRange(nums, start, mid); 
            if (start == end) { // 二分至一个元素
                if (count > 1) { // 次数>1表示重复元素即为该元素
                    return start;
                } else {
                    break;
                }
            }
            // 次数>元素个数表示重复元素在该区间
            if (count > (mid - start + 1)) { 
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
    
    private int countByRange(int[] nums, int start, int mid) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] >= start && nums[i] <= mid) {
                count++;
            }        
        }
        return count;
    }
}
```
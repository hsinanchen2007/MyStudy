基本思路和许多人的一样：排序后用左右两个索引检测在正确位置的元素数目，
然后将右边第一次发生不匹配的位置j - 左边第一次发生不匹配的位置i + 1，这就是最短无序连续子数组的长度。
时间复杂度O(n)，空间复杂度O(n)。
左右两个索引分开进行遍历，当原数组就是有序的情况下，一个从左边的遍历就可以完成本题的要求。
```
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int len = nums.length;
        int minLen = 0;
        int[] newNums = new int[len];
        System.arraycopy(nums, 0, newNums, 0, len);
        Arrays.sort(nums);
        int i = 0,j = len-1;
        while(i < len){
            if(nums[i] != newNums[i])
                break;
            else
                i ++;
        }
        if(i == len)//数组有序，返回结果
            return 0;
        while(j >= 0){
            if(nums[j] != newNums[j])
                break;
            else
                j --;
        }
        if(j == -1) //可以不用，因为如果有序，在左边遍历的过程中就已经返回了结果。
            return 0;
        else
            return j - i + 1;
    }
}

```
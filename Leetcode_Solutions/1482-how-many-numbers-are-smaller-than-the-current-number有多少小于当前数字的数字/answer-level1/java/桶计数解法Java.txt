![image.png](https://pic.leetcode-cn.com/d7894ab57669fccd668abb9b6501b61f41de2a71083ed3a7aeafeaab07ebc975-image.png)
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] arr=new int[101];
        int[] result=new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            arr[nums[i]]++;
        }
        for (int i = 1; i < arr.length; i++) {
            arr[i]+=arr[i-1];
        }
        for (int i = 0; i < nums.length; i++) {
            result[i]=nums[i]==0?0:arr[--nums[i]];
        }
        return result;
    }
}
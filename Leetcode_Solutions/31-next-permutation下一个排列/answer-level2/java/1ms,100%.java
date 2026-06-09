```
/*
大致思路：从右往左寻找第一个非单调递增的数组,下标记为k,然后在从后往前找第一个比k对应数大的数的下标记为i,然后交换i,k对应下标的数,再把k+1和nums.length - 1（下标）之间的数翻转即可.

*/
class Solution {
    public void nextPermutation(int[] nums) {
        int i = nums.length - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]) i--;
        int k = i;
        if(k < 0) { //k < 0 表示从右往左单调递减,则翻转数组,使其成为最小
            reverse(nums, 0, nums.length - 1);
            return;
        }
        int num = nums[k];
        i = nums.length - 1;
        while(i >= 0 && nums[i] <= num) i--;    //从右往左找到第一个大于下标k对应的数字下标
        swap(nums, k, i);   //交换
        reverse(nums, k + 1, nums.length - 1);  //后面的再翻转
    }
    void reverse(int [] nums, int i, int j){
        while(i < j){
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    void swap(int[] nums, int i, int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

}
```

一个指针用来遍历数组，一个指针用来指向0元素（或跟随遍历指针）。遇到非0元素则交换，最终会将所有非0元素交换到最前，而0元素在最后。
```

class Solution {
    public void moveZeroes(int[] nums) {
        int k = 0;
        for(int i = 0;i < nums.length;i++){
            if(nums[i] != 0){
                swapArrays(nums,i,k++);
            }
        }
    }
    private void swapArrays(int[] nums,int first,int second){
        if(first == second){
            return;
        }
        int temp = nums[first];
        nums[first] = nums[second];
        nums[second] = temp;
    }
}
```

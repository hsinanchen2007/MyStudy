![test.jpg](https://pic.leetcode-cn.com/b7132921c876afe64880e28840ac23c5812994c4d8e7339c01cb6312d54d85ce-test.jpg)

```
class Solution {
    public void moveZeroes(int[] nums) {
        int curNum = 0; //表示当前遍历到的零元素的个数，
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 0){
                curNum++;
            }
            if(nums[i] != 0 && curNum > 0){
                //当前元素需要移动到遍历到的所有零元素的前面。
                nums[i-curNum] = nums[i];
                nums[i] = 0;
            }
        }
    }
}
```

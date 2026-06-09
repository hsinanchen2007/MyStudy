```
class Solution {
    public int singleNumber(int[] nums) {
        int init = nums[0];
        for (int i = 1; i < nums.length; i++) {
            init = init ^ nums[i];
        }
        return init;
    }
}
```
假如输入数组是 [5,3,9,3,9,4,5] ,那么异或本应该是 5^3^9^3^9^4^5。(这也是循环所做的事，debug的话不太好理解每一步的结果)

但是从数学角度就好理解多了： 异或运算满足交换定律，所以可写成 (5^5)^(3^3)^(9^9)^4 

挺厉害的解题思路！！！


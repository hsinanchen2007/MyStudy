解题思路：
left表示左边元素，right表示右边元素，如果左边元素的奇数，则跟最右边的偶数调换顺序。

```
class Solution {
    public int[] exchange(int[] nums) {
        if (nums.length == 0) return new int[0];
        int letf = 0, right = nums.length - 1;
        while (letf < right) {
            //左边是奇数
            if (nums[letf] % 2 == 0) {
                if (nums[right] % 2 == 1){
                    int temp = nums[letf];
                    nums[letf] = nums[right];
                    nums[right] = temp;
                } else {
                    right--;
                }
            } else {
                letf++;
            }
            
        }
        return nums;
    }
}
```

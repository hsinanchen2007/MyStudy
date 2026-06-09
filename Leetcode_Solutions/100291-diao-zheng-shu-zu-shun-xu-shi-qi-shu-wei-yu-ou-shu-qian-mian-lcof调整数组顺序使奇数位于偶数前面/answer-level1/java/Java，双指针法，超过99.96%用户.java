### 解题思路
【双指针解法】
1、从左边开始找偶数，记录偶数位置
2、从右边开始找奇数，记录奇数位置
3、交换奇数和偶数
4、直到left>right则说明left左边全是奇数，right右边全是偶数

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        int left = 0;
        int right = nums.length-1;
        while(true) {
            while(left < nums.length && nums[left]%2!=0) {
                left++; //从左边开始，找偶数
            }
            while(right >=0 && nums[right]%2==0) {
                right--; //从右边开始找奇数
            }
            if(left>right)
                break;
            int n = nums[left];
            nums[left] = nums[right];
            nums[right] = n;
        }
        return nums;
    }
}
```
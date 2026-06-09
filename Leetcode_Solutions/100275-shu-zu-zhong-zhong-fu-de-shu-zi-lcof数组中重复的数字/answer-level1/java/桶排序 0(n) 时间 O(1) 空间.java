### 解题思路
题目既然给定数字都出现在 0 ～ n-1 之间，那么我可以视每个下标为一个桶。

遍历一遍元素，判断当前 i 存放的数据值 n 是否为 i，如果不为，就与它值对应的那个下标交换。

交换之前判断一下，被交换的下标 n 是否已经存放了 n，如果存放了说明已经重复了，返回即可。

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        for(int i = 0; i < nums.length; i++){
            int n = nums[i];
            while(n != i){
                if(nums[n] == n) return n;
                int temp = nums[i];
                nums[i] = nums[n];
                nums[n] = temp;
            }
        }
        return 0;
    }
}
```
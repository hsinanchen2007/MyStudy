### 解题思路
使用双指针，分别从左右开始寻找，左边的找到一个偶数暂停寻找，当右边找到一个奇数时候两个交换值，然后继续寻找，当指针相遇的时候就可以结束了。

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        int even = 0, odd = nums.length-1;
        while(even < odd){
            if (nums[even] % 2 !=  0){ //找到第一个偶数
                even ++;
            }
            else if(nums[odd] % 2 != 1){ // 找到一个奇数
                odd --;
            }
            else{ // 奇偶交换
                int temp = nums[even];
                nums[even] = nums[odd];
                nums[odd] = temp;
            }
        }
        return nums;
    }
}
```

![搜索框传播样式-标准色版.png](https://pic.leetcode-cn.com/c00611a00af978e7e173491ae2bb6d3bf1deebefd2ec22d840b2854cee08d22a-%E6%90%9C%E7%B4%A2%E6%A1%86%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)

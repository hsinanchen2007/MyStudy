### 解题思路
从王道上得来的思路，使用一个记录位记录下重复的元素个数
从前往后遍历时，如果前后两个元素相同就记录位加一
如果不相同，就把后面的元素往前移动n个位置，记录位不变
最后数组的长度就是原长度减n
就是官方答案的双指针的另一种形式

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length == 0) return 0;
        int n = 0;
        for(int i = 0; i < nums.length - 1; i ++){
            if(nums[i] == nums[i + 1]){
                n++;
            }else{
                nums[i - n + 1] = nums[i + 1];
            }
        }
        return nums.length - n;
    }
}
```
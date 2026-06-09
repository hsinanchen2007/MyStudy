### 解题思路
1.定义变量保存当前元素之前的元素存在多少个0元素
2.遍历数组，如果当前元素为0，则zeroes ++；否则将元素前移 i-zeroes 个位置
3.完成非0元素前移之后，再对数组进行遍历，将nums.length -zeroes之后的元素置为0

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        // 遍历 当前元素前 0元素存在的次数
        int zeroes = 0;
        for (int i = 0; i < nums.length; i++) {
            if(nums[i] == 0){
                zeroes ++;
            }else{
                nums[i-zeroes] = nums[i];
            }
        }

        for (int i = nums.length -zeroes ; i < nums.length; i++) {
            nums[i] = 0;
        }
    }
}
```
### 解题思路
此处撰写解题思路
一个数和0异或还是自己，一个数和自己值相同的数异或是0，最后单出来的数会和0（相同的数异或为0，0和0异或为0）异或得到结果
### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        int result = 0;
        for(int i=0;i<nums.length;i++){
            result = result^nums[i];
        }
        return result;
    }
}
```

- 遍历数组，所以元素进行异或运算，输出结果
```java
class Solution {
    public int singleNumber(int[] nums) {
        int result = 0;
        for(int num:nums){
            result = result^ num;
        }
        
        return result;
    }
}
```
### 解题思路
for each 和迭代器的效率略低,处理需要4ms,追求速度还是普通for循环,2ms足矣.
使用三目运算链式编程可以简化代码.

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
    int Temp=0;
        for(int i=0;i<nums.length;i++){
        Temp=((String.valueOf(nums[i])).length()%2)==0 ? ++Temp:Temp;
    }return Temp;
}
}
```
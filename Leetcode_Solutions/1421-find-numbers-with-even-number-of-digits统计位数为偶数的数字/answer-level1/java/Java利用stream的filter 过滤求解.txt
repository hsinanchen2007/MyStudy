### 解题思路
先转换为stream再利用filter方法，此处参数为IntPredicate，返回值为布尔值（因为最近总是在学java的函数式编程所以优先考虑用流的方法处理）

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
      return (int)Arrays.stream(nums).filter(num->{
            int count=0;
            while (num!=0){
                num/=10;
                count++;
            }
            return count%2==0?true:false;
        }).count();
    }
}
```
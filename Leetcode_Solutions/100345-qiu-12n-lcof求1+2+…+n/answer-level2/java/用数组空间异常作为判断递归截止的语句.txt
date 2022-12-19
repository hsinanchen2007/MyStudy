### 解题思路
数组空间设置为-1时，会触发负数组空间异常

### 代码

```java
class Solution {
    
    public int sumNums(int n) {
          try{
              int nums[]=new int[n];
          }
          catch (Exception e){
              return n+1;
          }

          return n+sumNums(n-1);
    }
}
```
所以递归到n=-1时会抛出异常，此时就返回n+1也就是0
则相当于将原式变为(-1+1)+0+1+2+...+n
### 解题思路
转化为long类型再循环取模，然后对结果判断是否超出整形范围

### 代码

```java
class Solution {
    public int reverse(int x) {
        long xl=x;
        long ans=0;
        while(xl!=0){
           ans=ans*10+(xl%10);
           xl=xl/10;
        }
        if(ans>Integer.MAX_VALUE||ans<Integer.MIN_VALUE){
            return 0;
        }
        return (int)ans;
    }
}
```
### 解题思路
题目说需要对100000007取模运算，是每一项都需要取模，一开始我只对结果取模了
另外，我对前两项进行了单独处理，最后用时0ms，击败了100%的用户。

### 代码

```java
class Solution {
    public int fib(int n) {
        int fn = 0;
        int fm = 1;
        int sum = 0;
        if ( n == 0){
            return 0;
        }else if(n == 1){
            return 1;
        }else{
            for( int i = 2; i<=n;i++){
                sum = (fm + fn)%1000000007;  //取模
                fn = fm;
                fm = sum;
            }
        }
        return fm;    
    }
}
```
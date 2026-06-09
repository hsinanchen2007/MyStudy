Java 要显示声明一个 boolean 变量并赋值，才能执行条件表达式 
```
class Solution {
    public int sumNums(int n) {
        int ans =  n;
        boolean condition = n > 0 && (ans += sumNums(n - 1)) > 0;
        return ans;
    }
}
```

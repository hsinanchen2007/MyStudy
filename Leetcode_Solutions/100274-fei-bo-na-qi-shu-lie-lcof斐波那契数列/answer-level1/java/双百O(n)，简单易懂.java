### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int fib(int n) {
        if(n <= 1)return n;
        int first = 0;
        int second = 1;
        int  third = 0;
        for(int i = 0; i < n - 1; i++){
            third = (first + second)%1000000007;
            first = second;
            second = third;
        }
        return third;
    }
}
```
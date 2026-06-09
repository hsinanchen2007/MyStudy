### 解题思路
这个题需要考虑的是，我们需要取余，整除抹零这个概念。只要明白这两个概念就行

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0 || x != 0 && x % 10 == 0){
            return false;
        }
        int res = 0;
        int a = x;
        while(x > 0){
            res = res * 10 + x %10;
            x /= 10;
        }
        return a == res;
    }
}
```
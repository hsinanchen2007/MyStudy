### 解题思路
我就按题目意思一行一行放，看放到第几行就返回
### 代码

```java
class Solution {
    public int arrangeCoins(int n) {
        int i=1;
        while(n>=i){
            n-=i++;
        }
        return i-1;
    }
}
```
### 解题思路
这是我水经验的题

### 代码

```java
class Solution {
    public int arrangeCoins(int n) {
        int index=0,sum=0;
        for(int i=1;;i++){
            if(i>n)
                return i-1;
            n-=i;
        }
    }
}
```
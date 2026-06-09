### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean hasAlternatingBits(int n) {
        int ans = n & 1;
        while(n > 0){
            n = n >>> 1;
            int temp = n & 1;
            if(ans + temp == 1){
                ans = temp;
            }else
                return false;
        }
        return true;
    }
}
```
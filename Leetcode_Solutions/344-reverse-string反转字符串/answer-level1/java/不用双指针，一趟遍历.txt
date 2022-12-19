### 解题思路
利用下标控制

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        if(s == null || s.length == 0){
            return;
        }
        int n = s.length;
        for(int i=0; i < n /2; i++){
            char temp = s[i];
            s[i] = s[n-1-i];
            s[n-1-i] = temp;
        }

    }
}
```
### 解题思路
这题应该大家都会的。

### 代码

```java
class Solution {
    public String convertToTitle(int n) {
        StringBuilder sb = new StringBuilder();
        char[] chars = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        
        while(n != 0){
            int index = (n-1) % 26;
            sb.append(chars[index]);
            n = (n-1) / 26;
        }
        return sb.reverse().toString();
    }
}
```
### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int strStr(String source, String target) {
        // Write your code here
        if(source == null || target == null) {
            return -1;
        }
        if(target.length() == 0) {
            return 0;
        }
        
        for(int i = 0; i < source.length() - target.length() + 1; i++) {
            int j;
            for(j = 0; j < target.length(); j++) {
                if(source.charAt(i + j) != target.charAt(j)) {
                    break;
                }
            }
            
            if(j == target.length()) {
                return i;
            }
        }
        
        return -1;
    }
}
```
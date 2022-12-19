### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int compress(char[] chars) {
        if(chars == null || chars.length == 0) {
            return 0;
        }
        int pre = 0;
        int size = 0;
        for(int cur = 0; cur <= chars.length; cur++) {
            if(cur == chars.length || chars[pre] != chars[cur]) {
                chars[size] = chars[pre];
                size++;
                if(cur - pre > 1) {
                    for(char c : String.valueOf(cur - pre).toCharArray()) {
                        chars[size++] = c;
                    }
                }
                pre = cur;
            }
        
        }
        return size; 
    }
}

```
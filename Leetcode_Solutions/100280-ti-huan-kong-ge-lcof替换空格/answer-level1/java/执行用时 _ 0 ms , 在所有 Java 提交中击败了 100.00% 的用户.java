### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        // return s.replaceAll(" ", "%20"); // 投机取巧
        if(s == null || s.length() == 0)
            return s;
        int len = s.length();
        char[] tmpc = new char[len * 3];
        char[] strc = s.toCharArray();
        int size = 0;
        for(int i = 0; i < len; i++){
            if(strc[i] == ' '){
                tmpc[size++] = '%';
                tmpc[size++] = '2';
                tmpc[size++] = '0';
            } else {
                tmpc[size++] = strc[i];
            }
        } 
        return new String(tmpc, 0, size);
    }
}
```
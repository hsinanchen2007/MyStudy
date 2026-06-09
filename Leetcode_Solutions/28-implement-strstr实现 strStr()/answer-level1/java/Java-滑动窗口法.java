### 解题思路
Java-滑动窗口法

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        char[] haystacks = haystack.toCharArray();
        char[] needles = needle.toCharArray();

        int i = 0;
        int j = 0;

        while (i<haystack.length() && j<needle.length()){
            if(haystacks[i] == needles[j]){
                i++;
                j++;
            }else{
                i = i-j+1;
                j=0;
            }
        }
        if(j==needle.length()){
            return i-j;
        }
        return -1;
    }
}
```
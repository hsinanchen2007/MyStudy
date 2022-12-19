### 解题思路
简单的双指针法。注意指示haystack指针需要回退。
时间复杂度：
空间复杂度：O（1）

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.length()==0)
            return 0;
        
        int j=0;
        for(int i=0;i<haystack.length();i++){
            if(haystack.charAt(i)==needle.charAt(j)){
                j++;
                if(j==needle.length())
                    return i-j+1;
            }else{
                i-=j;
                j=0;
            }
        }

        return -1;
    }
}
```
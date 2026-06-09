### 解题思路
有问题欢迎留言

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        if(haystack.equals(needle)||needle.equals("")){
            return 0;
        }
        int hava = 0;
        int len = haystack.length(),need_len = needle.length();
        if(need_len>len){
            return -1;
        }
        for(int i=0;i<len;i++){
            if(haystack.charAt(i)==needle.charAt(0)){
                hava = len - i;
                if(hava>=need_len&&haystack.substring(i,i+need_len).equals(needle)){
                    return i;
                }
            }
        }
        return -1;
    }
}
```
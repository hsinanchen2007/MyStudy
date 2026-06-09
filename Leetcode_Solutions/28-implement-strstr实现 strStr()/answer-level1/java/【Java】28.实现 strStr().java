### 解题思路
第二道不看答案做对的，虽然自己写的很复杂，但是也通过啦。

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.equals("")){
            return 0;
        }else {
            int j = 0;
            for (int i = 0;i < haystack.length();i++){
                if (haystack.charAt(i) == needle.charAt(j) && haystack.substring(i,haystack.length()).length() >= needle.length()){
                    String heyStacksub = haystack.substring(i,i + needle.length());
                    if (heyStacksub.equals(needle)){
                        return i;
                    }
                }
            }
        }
        return -1;
    }
}
```
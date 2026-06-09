### 解题思路
for(int i = 0; i < haystack.length() - needle.length() + 1; i++)
指针在haystack上移动的距离为haystack.length() - needle.length() + 1，如果为haystack.length()会报错超过长度
haystack.charAt(i + j) != needle.charAt(j)
在对比时不能改变i的值，要不在needle为子串时没法返回标记点i

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        if(needle == null || needle.length() == 0){
            return 0;
        }

        if(needle.length() > haystack.length()){
            return -1;
        }

        for(int i = 0; i < haystack.length() - needle.length() + 1; i++){
            int j = 0;
            for(j = 0; j < needle.length(); j++){
                if(haystack.charAt(i + j) != needle.charAt(j)){
                    break;
                }
            }

            if(j == needle.length()){
                return i;
            }
        }
        return -1;
    }
}
```
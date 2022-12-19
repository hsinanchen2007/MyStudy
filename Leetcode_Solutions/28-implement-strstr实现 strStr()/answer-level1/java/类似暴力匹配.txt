### 解题思路
循环haystack数组，使用needle匹配，如果匹配不成功，到退needleIndex继续匹配。
击败25.5% 垃圾 

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        
        //空字符串 返回0
        if (haystack.length() >= 0 &&
            needle.length() <= 0) {
            return 0;
        } 

        if (haystack.length() <= 0) {
            return -1;
        }

        //设置一个变量needle索引值
        int needleIndex = 0;

        //循环遍历字符串数组
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack.charAt(i) == needle.charAt(needleIndex)){
                //找到了这个值
                if (needleIndex == needle.length() - 1) {
                    return i - needleIndex;
                }
                needleIndex++;
                
            } else {//重新计算值
                i = i - needleIndex;
                needleIndex = 0;
            }
        }

        return -1;
    }
}
```
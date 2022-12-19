### 解题思路
此处撰写解题思路
这一题我用最简单的方法来解决的，for循环和下标
第一步：将字符串转化为字符数组，用两个for循环来判断，第二个for循环初始值自定义的一个数值（因为在判断相同时需要更改下一次循环的开始位置），定义了maxlen来存储出现相同前的最大长度。
第二步：判断是否相同，是则更改maxlen值和left值同时跳出第二个for循环break，最后返回的数值要和字符相同之后的长度比较，得出最大。
以上是我的个人见解，如有不对还望大佬指点，这也是我第一次做的题和第一次写题解不是很懂。如果有优化的还望指点一下。谢谢
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxlen = 0;
        int left = 0;
        char[] chars = s.toCharArray();
        for(int i=0;i<chars.length;i++){
            for(int in = left ;in<i ; in++){
                if(chars[in]==chars[i]){
                    maxlen = Math.max(maxlen,i-left);
                    left = in+1;
                    break;
                }
            }
        }
        return Math.max(chars.length-left,maxlen);
    }
    
}
```
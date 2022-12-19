![反转字符串.jpg](https://pic.leetcode-cn.com/38206f63acef12a7e05bf63562db571dff60e65a32c1580d2e8b6560e7d18a31-%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.jpg)

双指针，只要后面的大于前面的，就代表还没有替换完

```
class Solution {
    public void reverseString(char[] s) {
        int start = 0;
        int end = s.length - 1;
        char temp;
        while(end > start){
            temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            end--;
            start++;
        }
    }
}
```

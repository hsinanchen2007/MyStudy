![微信图片_20200329140526.png](https://pic.leetcode-cn.com/151172d4b677f541371abe566fd600d82f07b8b594a9176c0df92cedef3381f4-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200329140526.png)

```
class Solution {
    public void reverseString(char[] s) {
        int left = 0;
        int right = s.length-1;
        while(left<right){
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
}
```
简单说，就是两个字符相互交换就好。
容易出错的地方在于忘记移动指针left、right。
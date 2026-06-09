### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int start = 0, maxLen = 0;
    public String longestPalindrome(String s) {
        if(s.length() < 1) return s;


    for(int i=0; i<s.length(); i++){

        // 回文子串为奇数时，查找最长回文子串

        extendPalindrome(s, i, i);

        // 回文子串为偶数时，查找最长回文子串

        extendPalindrome(s, i, i+1);

    }


        return s.substring(start, start + maxLen);

    }


private void extendPalindrome(String s, int left, int right){

    // 判断是否为回文子串，若是，则左指针向左移动，右指针向右移动

    while(left>=0 && right<s.length() && s.charAt(left) == s.charAt(right)){

    left--;

    right++;

}


// 回文子串查找完成后，判断刚刚查找的回文子串是否为最长回文子串，若是，则更新起始位置和最长长度

    if(maxLen < right-left-1){

        start = left + 1;

        maxLen = right -left - 1;

    }
}
}
```
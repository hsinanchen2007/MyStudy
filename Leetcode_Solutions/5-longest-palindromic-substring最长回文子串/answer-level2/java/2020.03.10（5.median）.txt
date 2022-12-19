### 解题思路
本题使用**中心扩展思路**，定义i为字符串中心点，l和r分别为回文字段左右两端

分为奇数和偶数两种字符串，len1是奇数个字符串查找方法，len2是偶数个字符串查找方法

找到回文字段后，想清楚l和r的位置，不要多或少字符。

（b站“程序员刀刀”也有讲解）

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if(s == null || s.length() < 1){//判空
            return "";
        }
        int l=0;//回文起点位置
        int r=0;//回文终点位置
        for(int i = 0; i < s.length(); i++){
            int len1 = expandAroundCenter(s, i - 1, i + 1);//奇数，中心点左右两边
            int len2 = expandAroundCenter(s, i, i + 1);//偶数，中心点左右两边
            int len = Math.max(len1,len2);
            if(len > r - l){
                l = i - (len - 1 )/2;//中心点减去回文长度的一半（奇数偶数通用）
                r = i + len/2;//中心点加上回文长度的一半
            }
        }
        return s.substring(l, r + 1);//左闭右开
    }
    
    private int expandAroundCenter(String s, int left, int right){
        int L = left;
        int R = right;
        while(L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)){
            L--;
            R++;
        }
        return R - L - 1;//保证传进来的时候的长度
    }
}

```
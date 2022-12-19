### 解题思路
回文串 就是一个正读和反读都一样的字符串。所以相同字母必然对称。
回文字符串的普通的两个钟情况：      abcba    aabb 。
所以偶数个字符将加进回文中；字符串中间允许存在一个任意字符。

特殊情况：  aaa  和 ababababa则特殊处理

思路：1、使用哈希表存储字符个数
      2、遍历哈希表，计算回文长度。（使用四个if来处理两种普通情况，两种特殊情况）

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> chars_cnt;
        unordered_map<char, int> :: iterator it;
        int num=0,len=0;
        bool mid_solo=false;    //表示 放在汇文 中的单个字母是否已有

        len=s.length();
        if(len==0)
            return 0;

        for (char c:s)
            ++chars_cnt[c];        //存储每个字符的个数

        it = chars_cnt.begin();
        while(it != chars_cnt.end())
	    {
            if(len == it->second )      //字符串都是同一个字符，本身长度即回文长度  处理特殊情况
                return len ;

            if( it->second%2==0)        //该字符的个数为偶数时，全部字符皆能放进回文中
                num=num+it->second;

            if(it->second==1 &&  mid_solo==false)    //字符为奇数的，最多只需要一个放在中间
            {
                num=num+1;
                mid_solo=true;
            }

            if(it->second!=1 && it->second%2 == 1 )  //超过一个，且个数为奇数的字母
            {
                num = num+(it->second-1);
                if(mid_solo==false)        //处理特殊情况  ababababa，此时 mid_solo用 用'a'
                {
                    num = num +1;
                    mid_solo=true;
                }                  
            }

		++it;
	    }

        return num;
    }
};
```
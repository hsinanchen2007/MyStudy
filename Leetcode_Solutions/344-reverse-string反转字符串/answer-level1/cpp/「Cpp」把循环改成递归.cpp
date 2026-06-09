### 解题思路

这道题目有两种做法，一种是递归，一种不是递归。

我的循环代码如下

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        if ( s.size() == 0 ) return ; 
        for (int i = 0; i < s.size() / 2; i++){
            char tmp = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size()- i - 1] = tmp;
        }
        return;

    }
};
```

几乎所有的循环都可以改成递归形式。主要问题是如何改？

终止条件：从`for`循环中我们可以知道递归的终止条件是`i >= s.size() / 2`, 当字符串长度为3，当i=1的时候，就可以停止了。

处理逻辑：每一次循环的关键语句是交换，第i个字符和s.size() - i - 1位置的字符。

因此代码可以改写成

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        
        helper(s, 0, s.size());

    }
    
    void helper(vector<char>& s, int pos, int s_len){
        if ( pos >= s_len / 2) return;
        char tmp = s[pos];
        s[pos] = s[s_len - 1 - pos];
        s[s_len - 1 - pos ] = tmp;
        
        helper(s, pos+1, s_len);
    }
};
```

如果用双指针的话，每次就需要更新left和right两个参数，最终的结束条件是left>=right
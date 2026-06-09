### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/64ba9b791fec4d9d6c0152f6fff88927498b1c166ca83ed1079f233245f9e81d-image.png)

### 代码

```cpp
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s)
    {
        // 从后向前寻找 遇到非空格全部弹出 
        if(s.length()==1&&s!=" ")// 传入的串为一个空格
            return 1;
        while(!s.empty()&&s.back()==' ')// 弹出所有到空格
            s.pop_back();

        int sum=s.length();// 记录总长度
        // 弹出所有空格才能开始寻找 单词
        if(!s.empty()&&s.back()!=' '&&s.length()>1)// 可能存在一个单词情况
        while(!s.empty()&&s.back()!=' ')// 弹出直达遇到空格
            s.pop_back();
        else // 剩余一个非空格字母情况
        return s.length();
       
        return sum-s.length();// 找到单词
    }
};
```
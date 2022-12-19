## 问题描述
给定一个仅包含小写字母的字符串，去除字符串中重复的字母，使得每个字母只出现一次。需保证返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

![](https://pic.leetcode-cn.com/879505b394e3898121553f3792aa6e1a1496f9894eb0d5df08957680f728f5e0.png)

[去除重复字母](https://leetcode-cn.com/problems/remove-duplicate-letters/ "去除重复字母")

## 解决方法

### 栈

- 记录每个字符出现的最后位置（用来保证字典序）

- 判断当前字符是否已经存在于栈中，如果存在，则继续向后遍历

- 如果当前字符比栈顶元素小且栈顶元素最后出现的索引大于当前循环字符索引，则舍弃栈顶元素，而选择后出现的那个字符，这样得到的字典序更小。

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int size=s.size();
        unordered_map<char,int>m;//记录元素出现的最后位置
        unordered_map<char,bool>used;//记录元素是否在栈中
        stack<char>st;
        string res;//返回结果
        for(int i=0;i<size;i++){
            m[s[i]]=i;
        }
        for(int i=0;i<size;i++){
            if(used[s[i]])continue;
            while(!st.empty() && st.top()>s[i] && m[st.top()]>=i){
                used[st.top()]=false;//抛出栈顶元素的时候记得清除使用记录
                st.pop();
            }
            used[s[i]]=true;//添加使用记录
            st.push(s[i]);
        }
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};

int main(){
    Solution solution;
    string s="bcabc";
    string res=solution.removeDuplicateLetters(s);
    cout<<res;
    return 0;
}
```

my site:[https://liyiping.cn/](https://liyiping.cn/)
![image.png](https://pic.leetcode-cn.com/f65c1254506944e73f0398bbf716419681bfaebb19cc8aa14f8f2f0cdfc7f5aa-image.png)

### 解题思路
用stringstream就能直接用>>操作符获得每个以空格结尾的单词，再借助一个栈反转就行了。

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        stack<string> st;
        string temp, ans;
        while(ss>>temp)
            st.push(temp);
        while(!st.empty())
        {
            ans += st.top() + " ";
            st.pop();
        }
        ans = ans.substr(0, ans.find_last_not_of(' ')+1);
        return ans;
    }
};
```
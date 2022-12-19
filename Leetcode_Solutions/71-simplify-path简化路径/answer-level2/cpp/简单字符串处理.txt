### 解题思路


### 代码

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        string ans = "/";
        path += "/";
        if(path[0] != '/')
            path = "/" + path;
        for(int i = 1 ; i < path.size() - 1; ++i)
        {
            if(path[i - 1] == '/' && path[i] == '/')    //去掉连续/
                continue;
            if(path[i - 1] == '/' && path[i] == '.' && path[i + 1] == '/')  //去掉/./
            {
                i++;
                continue;
            }
            ans += path[i];
        }
        if(ans.back() != '/') //为了之后循环方便
            ans += "/";
        stack<string> st;
        int index = 1, pre = 1;
        while((index = ans.find("/", index)) != string::npos)
        {
            string temp = ans.substr(pre, index - pre);
            if(temp == ".." && !st.empty()) //如果碰到/.. 那么就回退
                st.pop();
            else if(temp != "..")
                st.push(temp);
            index++;
            pre = index;
        }
        ans = "";
        if(st.empty())
            return "/";
        while(!st.empty())
        {
            ans = st.top() + ans;
            ans = "/" + ans;
            st.pop();
        }
        return ans;
    }
};
```
### 解题思路
核心就在于判断当前字符是不是/，若不是则去找/，若找不到/则已到末尾，找到了就push

### 代码

```cpp
class Solution {
public:
    stack<string> st;
    string simplifyPath(string path) {
        int i=0,length;
        while(i<path.size())
        {
            if(path[i]=='/')
                ++i;
            else
            {
                if(path.find('/',i+1)==path.npos)
                    length=path.size()-i;
                else
                    length=path.find('/',i+1)-i;
                if(path[i]=='.'&&length==2&&st.size())
                    st.pop();
                else if(length>2||path[i]!='.')
                    st.push(path.substr(i,length));
                i+=length;
            }
        }
        string res="";
        while(st.size())
        {
            res="/"+st.top()+res;
            st.pop();
        }
        if(res.size()==0)
            return "/";
        return res;
    }
};

```
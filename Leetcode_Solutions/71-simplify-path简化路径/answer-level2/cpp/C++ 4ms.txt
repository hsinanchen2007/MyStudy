### 解题思路
这道题要利用栈，我的思路和其他人可能有些差别。
实际上只需要用/分割字符串得到所有文件(夹)，将文件(夹)入栈(要注意.和..也是文件夹)，如果遇到..时抛弃上一个文件(夹)，遇到.忽略，最后输出时在每个文件(夹)之前加上/即可。

1. 遇到/忽略不处理
2. 否则开始分离文件(夹)，分情况处理，最后索引跳到文件(夹)后。
    1. 如果是.忽略不处理。
    2. 如果是..出栈。
    3. 其他入栈。

### 代码

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> can;
        string ans="";
        for(int i=0; i<path.size(); i++)
        {
            char ch = path.at(i);
            if(ch=='/') continue;
            else 
            {
                int j=i;
                while(j<path.size() && path.at(j)!='/') j++;
                if(j-i==1 && path.at(i)=='.') continue;
                else if(j-i==2 && path.at(i+1)=='.') 
                {
                    i=j;
                    if(!can.empty()) can.pop();
                }
                else
                {
                    can.push(path.substr(i, j-i));
                    i=j;
                }
            }
        }
        if(can.empty()) return "/";
        while(!can.empty())
        {
            ans= "/" + can.top() + ans;
            can.pop();
        }
        return ans;
    }
};
```



We use Stack to solve this problom, and maybe my train of thought is different from other ones somehow.
First we split the path by '/' to get all of the directory, then push them into the Stack, throw the last directory when we meet "..", and ignore "."， at last we print a '/' before each directory.
1. ignore '/'
2. split directory by '/'
    1. ingore "."
    2. pop when ".." turn out
    3. in other cases push
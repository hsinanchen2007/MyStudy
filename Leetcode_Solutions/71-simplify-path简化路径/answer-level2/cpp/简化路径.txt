## 问题描述

以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径

请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。

![2020-01-16-11-56-10屏幕截图.png](https://pic.leetcode-cn.com/92cfcbdf19fb45891897b550cb67057d5794d2944427889eadfbade367a962f3-2020-01-16-11-56-10%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)


[https://leetcode-cn.com/problems/simplify-path/](https://leetcode-cn.com/problems/simplify-path/)

## 解决方法
### 辅助栈
- 用栈来存储路径名字

- 遇到`..`抛出栈顶元素

- 最后用`/`将栈中元素连接成路径

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        stack<string>s;
        int size=path.size();
        int count=0;
        string temp;
        string res;
        while(count<size){
            if(path[count]=='/'){
                if(temp==".."){
                    if(!s.empty())s.pop();
                }else if(temp!="" && temp!="."){
                    s.push(temp);
                }
                temp.clear();
            }else{
                temp+=path[count];
            }
            count++;
        }
        if(temp==".." && !s.empty())s.pop();
        /* "/..." 什么破用例 */
        if(temp!="." && temp!=".." && temp!="")s.push(temp);
        while(!s.empty()){
            res='/'+s.top()+res;
            s.pop();
        }
        return (int)res.size()==0?"/":res;
    }
};

```

个人网站：[https://liyiping.cn](https://liyiping.cn)
### 解题思路
此处撰写解题思路
![捕获.PNG](https://pic.leetcode-cn.com/2ebfb54f848e10fff8bb7fde6491677bd1ff43993a28c89e64d7d969cd8db93b-%E6%8D%95%E8%8E%B7.PNG)

其实这是一个简单的堆栈问题 建立两个堆栈 一个用来保存复制次数 一个用来保存需要复制的字符串
### 代码

```cpp

class Solution {
public:
    int Times(int restime, int t)
    {
        restime = restime * 10 + t;
        return restime;
    }
    //将字符串str重复times次
    string repeat(const string& str, int times) {
        if (times == 0)
            return "";
        string retString = "";
        for (int i = 0; i < times; ++i) retString += str;
        return retString;
    }
    string decodeString(string s) {
        if (s.empty())
            return "";

        //保存的栈
        stack<int> num;
        stack<string> str;
        string temp;
        int times = 0;

        for (auto i : s)
        {
            //如果是数字
            //计算时间
            if (i >= '0' && i <= '9')
                times = Times(times, i - '0');
            else if (i == '[') {
                //保存当前值
                str.push(temp);
                num.push(times);

                //清零
                times = 0;
                temp.clear();
            }
            //弹出来进行计算
            else if (i == ']')
            {
                //弹出保存的
                int t = num.top();
                num.pop();
                string j = str.top();
                str.pop();

                temp = j + repeat(temp, t);
            }
            else
                temp += i;
        }

        return temp;
    }
};
```
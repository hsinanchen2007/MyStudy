### 解题思路
首先吐槽出题人，表示题目读起来很绕口
理解题意后，不难想到需要用递归的思想，其中第一项特殊处理

### 代码

```cpp
class Solution 
{
public:
    string countAndSay(int n) 
    {
        if(n > 2) return say(countAndSay(n-1));
        else if(n==2) return "11";
        else return "1";
    }
    
    string say(string str)
    {
        int count = 1;
        char tmp = str[0];
        string result = "";
        for(int i = 1; i < str.length(); i++)
        {
            if(str[i] != tmp)
            {
                result += to_string(count) + tmp;
                tmp = str[i];
                count = 1;
            }
            else count++;
        }
        result += to_string(count) + tmp;
        return result;
    }
};
```
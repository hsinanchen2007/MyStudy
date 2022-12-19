### 解题思路
用查找替换更新字符串

### 代码

```cpp
class Solution
{
public:
    string replaceSpace(string s)
    {
        string str(s);
        int pos = 0;
        do
        {
            pos = str.find(' ', pos);
            if(pos==-1)
                break;
            str.replace(pos, 1, "%20");
            //cout<<"pos:"<<pos<<" str:"<<str<<endl;
            pos++;
        } while (1);
        return str;
    }
};
```
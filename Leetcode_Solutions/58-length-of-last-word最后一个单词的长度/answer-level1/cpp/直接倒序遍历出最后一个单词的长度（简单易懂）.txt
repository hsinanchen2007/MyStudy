### 

### 代码

```cpp
class Solution {
public:
int lengthOfLastWord(string s)
{
    if(s.size() == 0)
        return 0;
    int result = 0;
    int i = s.size()-1;
    for(;i >= 0;--i)//跳过字符串结尾的空格
        if(s[i] != ' ')
            break;
    for(;i >= 0;--i)
        if(s[i] == ' ')//遇到空格，遍历结束
           break;
        else    //否则，计数器递增
            ++result;
    return result;
}
};
```
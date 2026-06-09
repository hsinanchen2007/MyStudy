### 解题思路
暴力寻找abc存在就删！！！
### 代码

```cpp
class Solution {
public:
    bool isValid(string S) {
        //判断有无abc
        while(S.size())
        {
            if(S.find("abc")!=S.npos)
            {
                int temp=S.find("abc");
                S=S.substr(0,temp)+S.substr(temp+3);
            }
            else
            break;
        }
        if(S.size()==0)
        return 1;
        else
        return 0;
    }
};
```
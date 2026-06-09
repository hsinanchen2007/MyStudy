### 解题思路
原地操作需要注意两点：
1 从末尾开始执行。
2 截掉多余的前置。


### 代码

```cpp
class Solution {
public:
    string replaceSpaces(string S, int length) {
        int _size = S.size();
        //cout<<_size<<' '<<length<<endl;
        while(length--)
        {
            if(S[length] == ' ')
            {
                S[--_size] = '0';
                S[--_size] = '2';
                S[--_size] = '%';
            }else
            {
                S[--_size] = S[length];
            }
        }
        return S.substr(_size);
    }
};
```
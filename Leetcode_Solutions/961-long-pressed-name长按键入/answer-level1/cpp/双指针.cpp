### 解题思路

### 代码

```cpp
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int cnt = 0;
        if(name[0] != typed[0])
            return false;
        for(int i = 0 ; i < typed.length() ; ++i)
        {
            if(typed[i] != name[cnt])
            {
                cnt++;
                if(typed[i] != name[cnt])
                    break;
            }
            else
            {
                if(name[cnt + 1] == name[cnt])
                    cnt++;
            }
        }
        if(cnt == name.length() - 1)
            return true;
        else
            return false;
    }
};
```
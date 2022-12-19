### 解题思路
直接看代码
### 代码

```cpp
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        if(cont.size()==1)
        {
            vector<int> result = {cont[0],1};

            return result;
        }
        int a = cont[0];
        vector<int>::iterator k = cont.begin();
        cont.erase(k);
        vector<int> flag = fraction(cont);
        int tem = flag[0];
        flag[0] = a*tem+flag[1];
        flag[1] = tem;
        return flag;
    }
};
```
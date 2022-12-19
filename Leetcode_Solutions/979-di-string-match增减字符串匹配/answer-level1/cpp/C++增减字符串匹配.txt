### 解题思路
碰到I选取集合中当前最小的，D选取当前最大的
### 代码

```cpp
class Solution {
public:
    vector<int> diStringMatch(string S) {

        //碰到I选取集合中当前最小的，D选取当前最大的
        vector<int> res;
        int min = 0;
        int max = S.size();
        for(int i=0;i<S.size();i++)
        {
            if(S[i] == 'I') 
            {
                res.push_back(min);
                min++;
            }
             else if(S[i] == 'D') 
            {
                res.push_back(max);
                max--;
            }
        }
        //如果min == max 证明此时只有一个元素没有插入
        //当然这也是显然的
        if(min == max)
            res.push_back(min);
        return res;
    }
};
```
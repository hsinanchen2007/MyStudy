### 解题思路
用数组res存结果，分为两种情况
* longer等于shorter，则直接将k* shorter存入res，跳出循环即可。
* longer不等于shorter，则循环k+1次，逐次增加长木板的个数，将结果存到res中。

没想出来递归怎么解...求一个递归解法

### 代码

```cpp
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        if(k==0)    return res;
        
        for(int i=0;i<=k;i++)
        {
            if(shorter==longer)
            {
                res.push_back(k*shorter);
                break;
            }
            else
                res.push_back(i*longer + (k-i)*shorter);
        }    
        return res;
    }
};
```
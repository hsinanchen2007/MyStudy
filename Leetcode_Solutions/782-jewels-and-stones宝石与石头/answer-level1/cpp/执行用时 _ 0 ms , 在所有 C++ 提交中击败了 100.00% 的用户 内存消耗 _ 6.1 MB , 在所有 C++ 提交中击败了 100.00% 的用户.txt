### 解题思路
count(begin,end,val)函数功能：查找容器里从begin开始到end结束中元素val的个数。

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        int num=0;
        
        for(auto v:J)
        {
            num+=count(S.begin(),S.end(),v);
        }
        
        return num;

    }
};
```
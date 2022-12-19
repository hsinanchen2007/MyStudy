### 解题思路
核心要点：计数deck中不同数出现的次数，存在count[10000]中，利用库函数gcd迭代计算这10000个数的最大公约数，若不小于2则返回true
执行用时 :32 ms, 在所有 C++ 提交中击败了10.74%的用户
内存消耗 :16.7 MB, 在所有 C++ 提交中击败了5.71%的用户
### 代码

```cpp
class Solution {
    int count[10000];
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        for(auto i:deck)count[i]++;
        int flag=0;
        for(int i=0;i<10000;i++){
            if(flag!=0)flag=gcd(flag,count[i]);
            else flag=count[i];
        }
        return flag>=2?true:false;
    }
};
```
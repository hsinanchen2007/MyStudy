### 解题思路
动态规划的思路
从剩余的数里取k个，有两种选择：
1、取当前这个数，然后从后面的数里取k - 1个
2、不取这个数，则从后面的数里取k个
而当k已经为0了，则表示可以添加了。
如果不可以添加，且剩下的也无法继续添加，则直接返回

### 代码

```cpp
class Solution {
public:

    //总共有n个，需要取k个  当前的下标是nowIndex，最多是需要取maxK个，
    void Resort(int n,int nowIndex,int maxK,int k,vector<vector<int>> &res,vector<int> &tempVec)
    {
        if(k == 0)//满了
        {
            res.push_back(tempVec);
            return;
        }
        //如果剩下的没有k个了或者是当前的下标大于n了 或者不需要取了
        if(k > n - nowIndex || nowIndex >= n || k < 0)
            return ;
        //如果这个取,那么写进去，再从后面的里面取k-1个
        tempVec[maxK - k] = nowIndex + 1;//把这个数加进去，然后调用下一个
        Resort(n,nowIndex + 1,maxK,k - 1,res,tempVec);
        //不取这个数，则从后面读k个
        Resort(n,nowIndex + 1,maxK,k,res,tempVec);
    }

    vector<vector<int>> combine(int n, int k) {
        //取这个数，再从后面去k-1个。或者不取这个数，从后面去k个
        //如果k - 1 == 0 那么把这个加进去。如果后面没有k-1 个了，则终止
        vector<vector<int>> res;
        vector<int> tempVec;
        if(n < k)
            return res;
        for(int i = 0;i < k;++i)
            tempVec.push_back(i + 1);
        Resort(n,0,k,k,res,tempVec);
        return res;
    }
};
```
### 解题思路
基本的思路是深度度优先算法。先从最大面值的硬币开始，这些都很简单，但是有很关键的一点，就是每一次从大到小遍历都要有一个判断语句
判断什么呢，就是比如遍历到面值为x的硬币，判断当前还需的硬币全部兑换成面值为x的硬币的数量加上已经有的数量会不会大于结果，如果会的话，那么表明后面无论怎么兑换，都会比现在的结果差，那么还兑换什么呢？直接break就行啦。
这一点很关键，直接将我的结果从几百ms提升到4ms。
![image.png](https://pic.leetcode-cn.com/cdfcf841f73d2e660b67e1958721c8bf6482cba6a09e4be5255c7f1e927b0668-image.png)

### 代码

```cpp
class Solution {
private:
    int len;
    int am;
    int res;
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        len=coins.size();
        am=amount;
        res=INT_MAX;
        DFS(coins,len-1,0,0);
        return res==INT_MAX?-1:res;
    }
    bool DFS(vector<int>& coins,int index,int TmpAmount,int CoinNum)
    {
        if(TmpAmount==am)
        {
            res=res>CoinNum?CoinNum:res;
            return true;
        }
        for(int i=index;i>=0 ;i--)
        {
            if(TmpAmount+coins[i]>am) continue;
            if(res!=INT_MAX && (am-TmpAmount)/coins[i]>=res-CoinNum) break;//关键的判断语句
            TmpAmount+=coins[i];
            if(DFS(coins,i,TmpAmount,CoinNum+1) && CoinNum!=0) break;//这个也是基于贪心算法的思想的判断语句
            TmpAmount-=coins[i];
        }
        return false;
    }
};
```
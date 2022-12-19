### 解题思路
  一看到这题，就很明显是要从硬币大的数值开始下手。递归的方法是最简单，最方便的。但是要注意剪一下枝，不然就会超时了。
  注意，首先把这个数组排一下序，因为没排序，wrong了两次，以为是自己哪里搞错了。还有我这里用了long来保存最少硬币数是因为考虑到，{[1] , INT_MAX}情况，我比较喜欢用最大值加一最为最小值的最大值。所以使用了long。
  从大到小找，每次遍历剩余金额amount对于当前的最大硬币数的倍数，也就是使用个数k。从k到0遍历，这里0是为保证这个硬币没用的情况下，还能接着从下面的硬币中凑。知道amount为0时去判断，最小的硬币数。
  而amount为0的情况不一定时最优的，所有需要找到所有的情况。但是所有的情况都找就会导致超时，因此只去找当前情况下，硬币总和数比最小的硬币数要小的情况。剪枝就减在这里。

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //最少硬币数的最大值
        long minn = amount + 1;
        //排个序
        sort(coins.begin() , coins.end());
        dfs(coins , coins.size() - 1 , minn , 0 , amount);
        return minn == amount + 1?-1:minn;
    }

    void dfs(vector<int>& coins , int index , long& minn , long gs , int amount){
        if(amount == 0){
            //比较最少硬币数
            minn = min(minn , gs);
        }
        if(index < 0)return ;
        //当前硬币的最大使用次数
        int k = amount / coins[index];
        //i + gs < minn 剪枝，只有比minn小的情况时可以去寻找的
        for(int i = k ; i >= 0 && i + gs < minn; i--){
            dfs(coins , index - 1 , minn , gs+ i , amount - i * coins[index]);
        }
    }
};
```
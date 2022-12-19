### 解题思路

思路：
1、筛选当前special列表中不满足条件的项干掉
    > 礼包单个商品数量超过需求的
    > 礼包总价超过单买价格的
2、DFS遍历所有的礼包，通过需求剩余的方式进行回溯
3、记录当前成功购买的最小消费，每次遍历过程中超过消费时停止遍历，需求满足时也停止遍历，计算最小消费值
4、遍历过程中如果当次循环结束礼包也不足以达标时，采用单买，同样也刷新消费结果

0ms 12.5M
--- wangtao HW-2020/3/2

### 代码

```cpp
class Solution {
public:

    bool IsCurBagValid(vector<int>& needs, vector<int>& cur)
    {
        for (int i = 0; i < needs.size(); i++) {
            if (needs[i] < cur[i]) return false;
        }
        return true;
    }

    void shoppingDFS(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost, int& ans)
    {
        if (cost >= ans) return;
        if (0 == accumulate(needs.begin(), needs.end(), 0)) {
            ans = min(ans, cost);
            return;
        }
        int enough = 0;
        for (int i = 0; i < special.size(); i++) {
            if (IsCurBagValid(needs, special[i])) {
                enough = 1;
                for (int j = 0; j < needs.size(); j++) {
                    needs[j] -= special[i][j];
                }
                int last = special[i].size()-1;
                shoppingDFS(price, special, needs, cost + special[i][last], ans);
                for (int j = 0; j < needs.size(); j++) {
                    needs[j] += special[i][j];
                }
            }
        }
        // 单次遍历完所有礼包已经不能满足的时候，采用单买
        if (enough == 0) {
            for (int i = 0; i < needs.size(); i++) {
                cost += needs[i] * price[i];
            }
            ans = min(ans, cost);
        }
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // 1、筛选礼包
        vector<vector<int>> specafter;
        int ans = INT_MAX;
        int cost = 0;

        for (int i = 0; i < special.size(); i++) {
            int bagprice = special[i][special[i].size()-1];
            int singleprice = 0;
            int j = 0;
            for (j = 0; j < special[i].size() - 1; j++) {
                if (special[i][j] > needs[j]) break;
                singleprice += special[i][j] * price[j];
            }
            if (j != special[i].size()-1 || singleprice < bagprice) continue;
            specafter.push_back(special[i]);
        }
        shoppingDFS(price, specafter, needs, cost, ans);
        
        return ans;
    }
};
```
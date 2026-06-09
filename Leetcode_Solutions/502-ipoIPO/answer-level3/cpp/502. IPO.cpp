### 解题思路
贪心策略： 在所有能做的项目里，选做收益最大的项目

### 代码

```cpp
class Solution {
public:
    struct Program
    {
        int capital;
        int profit;

        Program(int c, int p) : capital(c), profit(p) {}
    };


    //注意: priority_queue 小根堆 使用大于比较符  参考greater
    struct capital_min_cmp
    {
        bool operator()(const Program& p1, const Program& p2)
        {
            return p1.capital > p2.capital;
        }
    };

    //注意: priority_queue 大根堆 使用小于比较符  参考less
    struct profit_max_cmp
    {
        bool operator()(const Program& p1, const Program& p2)
        {
            return p1.profit < p2.profit;
        }
    };

    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital)
    {
        int max_capital = *max_element(Capital.begin(), Capital.end());
        if (W >= max_capital) //都能做 选做前k个最大利润的项目
        {
            priority_queue<Program, vector<Program>, profit_max_cmp> q_tmp;
            for (int i = 0; i < Profits.size(); ++i)
            {
                q_tmp.emplace(Capital.at(i), Profits.at(i));
            }

            int count = 0;
            while (!q_tmp.empty() && count < k)
            {
                W += q_tmp.top().profit;
                q_tmp.pop();
                ++count;
            }
            return W;
        }


        priority_queue<Program, vector<Program>, capital_min_cmp> q_min_cost;
        priority_queue<Program, vector<Program>, profit_max_cmp> q_max_profit;

        for (int i = 0; i < Capital.size(); ++i)
        {
            q_min_cost.emplace(Capital.at(i), Profits.at(i));
        }

        for (int i = 0; i < k; ++i)
        {
            while (!q_min_cost.empty() && q_min_cost.top().capital <= W)
            {
                q_max_profit.push(q_min_cost.top());
                q_min_cost.pop();
            }

            if (!q_max_profit.empty())
            {
                W += q_max_profit.top().profit;
                q_max_profit.pop();
            }
            else
            {
                return W;
            }
        }

        return W;
    }
};
```
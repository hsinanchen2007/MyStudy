### 解题思路
此处撰写解题思路
自己写排序算法对profit排序会超时，还是调用系统的sort算法好。
### 代码

```cpp
bool cmp(pair<int,int>a, pair<int,int>b){
    return a.first > b.first;
}

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        if (difficulty.size() == 0 || profit.size() == 0 || worker.size() == 0){
            return 0;
        }
        vector<pair<int,int>>vec;
        for(int i=0;i<profit.size();i++){
            vec.push_back({profit[i],difficulty[i]});
        }
        sort(vec.begin(),vec.end(),cmp);
        // for (auto it = vec.begin();it != vec.end();it++)
        // {
        //     cout << "(" << it->first << "," << it->second << ")" << endl;
        // }
        sort(worker.rbegin(),worker.rend());
        int profit_total = 0;
        int begin = 0;
        for(auto w : worker){
            for(int i=begin;i< vec.size();i++){
                if (w >= vec[i].second){
                    begin = i;
                    profit_total += vec[i].first;
                    break;
                }
            }
        }
        return profit_total;
    }
};
```
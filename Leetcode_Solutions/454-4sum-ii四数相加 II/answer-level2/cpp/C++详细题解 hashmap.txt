### 思路
- 建立一个哈希映射，一个记录AB数组的组合和，和为key，出现的次数为value
- 计算CD数组的组合和，得到相反数，若该数存在于key中，即符合要求，将答案加上AB组合和中该数出现的次数(value)

```cpp
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        unordered_map<int,int> ab;
        for(auto a : A){
            for(auto b : B){
                int sum = a + b;
                if(!ab.count(sum))  ab[sum] = 1;
                else    ab[sum] += 1;
            }
        }
        for(auto c : C){
            for(auto d : D){
                int need = -(c + d);
                if(ab.count(need))  ans = ans + ab[need];
            }
        }
        return ans;
    }
};
```

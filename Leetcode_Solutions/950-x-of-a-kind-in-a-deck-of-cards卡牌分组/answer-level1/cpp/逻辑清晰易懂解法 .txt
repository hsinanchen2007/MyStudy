1. 借助于ordered_map统计各数字出现的次数；
2. 将出现次数压入数组并排序；
3. 尝试2到数据最小元素是否为最大公约数

```
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> counter_map;
        vector<int> counter_vec;
        for(auto n:deck) counter_map[n] += 1;
        for(auto n:counter_map) counter_vec.push_back(n.second);

        sort(counter_vec.begin(), counter_vec.end());

        for(int i=2; i<=counter_vec[0]; i++){
            int flag = 1;
            for(int j=0; j<counter_vec.size(); j++){
                if(counter_vec[j] % i != 0){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) return true;
        }
        return false;
    }
};
```


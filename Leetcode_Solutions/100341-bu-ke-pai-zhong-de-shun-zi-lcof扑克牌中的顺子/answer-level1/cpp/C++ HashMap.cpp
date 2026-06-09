![image.png](https://pic.leetcode-cn.com/95505c022e2c95d6f6a687c4a2942d4e3087c5bee278b7ccf2b5b8c096029472-image.png)
```
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        map<int, int> table;
        for(auto &num: nums){
            auto it = table.find(num);
            if(it==table.end())
                table.insert(make_pair(num, 1));
            else{
                if(num) return false;
            }
        }
        if(table.begin()->first)
            return ((--table.end())->first-table.begin()->first)<=4;
        return ((--table.end())->first-(++table.begin())->first)<=4;
    }
};
```

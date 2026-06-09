### 解题思路
![EC41DE88-4A64-45BD-AC60-B6DA6C987254.png](https://pic.leetcode-cn.com/0705ebbe1785d96d66349fe3093cf2ea6bba3332a4b713c96f8e39d37e037849-EC41DE88-4A64-45BD-AC60-B6DA6C987254.png)
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        re = 0;
        for(auto num: nums){
            vector<int> all = find_all(num);
            if(all.size() == 4){
                for(auto j: all){
                    re = re + j;
                }
            }
        }
        return re;
    }
    vector<int> find_all(int num){
        vector<int> res;
        if(num != 1){
            res.push_back(1);
            res.push_back(num);
        }
        else{
            res.push_back(1);
            return res;
        }
        int j = num;
        for(int i = 2; i < j; ++i){
            if(num%i == 0){
                res.push_back(i);
                if(num/i != i){
                    res.push_back(num/i);
                }
                j = num/i;
            }
        }
        return res;
    }
private:
    int re;
};
```
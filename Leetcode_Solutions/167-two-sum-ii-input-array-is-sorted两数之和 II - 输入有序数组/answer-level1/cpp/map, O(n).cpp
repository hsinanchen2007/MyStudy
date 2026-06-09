### 解题思路
map, O(n)

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        map<int,int> res;
        vector<int> sum;
        for(int i=0; i<size; i++){
            if(res.find(target-numbers[i]) == res.end()) res[numbers[i]] = i;
            else{
                sum.push_back(res[target-numbers[i]]+1);
                sum.push_back(i+1);
                break;
            }
        }
        return sum;
    }
};
```
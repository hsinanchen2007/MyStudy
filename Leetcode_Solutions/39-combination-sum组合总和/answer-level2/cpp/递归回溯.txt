### 解题思路
为了避免重复，选择从大到小进行操作，递归表达式可以认为是包含1个最后的元素，和为target-这个值的解集并上不包含最后一个元素的解集。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.size()==0)return result;
        else if(candidates.back()>target){
            vector<int> subSet(candidates.begin(),candidates.end()-1);
            return combinationSum(subSet, target);
        }
        else if(candidates.back()==target){
            vector<int> subSet(candidates.begin(),candidates.end()-1);
            vector<int> item{candidates.back()};
            result.push_back(item);
            vector<vector<int>> otherPart = combinationSum(subSet, target);
            if(otherPart.size()!=0){
                result.insert(result.end(), otherPart.begin(),otherPart.end());
            }
            return result;
        }
        else{
            vector<int> subSet(candidates.begin(),candidates.end()-1);
            vector<vector<int>> resultPart_1 = combinationSum(candidates, target-candidates.back());
            vector<vector<int>> resultPart_2 = combinationSum(subSet, target);
            result.insert(result.end(), resultPart_2.begin(),resultPart_2.end());
            for(auto it : resultPart_1){
                it.push_back(candidates.back());
                result.push_back(it);
            }
        }
        return result;
    }
};
```
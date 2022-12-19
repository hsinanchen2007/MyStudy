### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low=0,high=numbers.size()-1;
        vector<int> ans;
        while(low<high){
            if(numbers[low]+numbers[high]==target){
                ans.push_back(low+1);
                ans.push_back(high+1);
                break;
            }
            else if(numbers[low]+numbers[high]<target){
                low++;
            }
            else{
                high--;
            }
        }
        return ans;
    }
};
```
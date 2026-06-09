```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j){
            int tmp = numbers[i] + numbers[j];
            if(tmp > target){
                j --;
            }else if(tmp < target){
                i ++;
            }else{
                return {i+1, j+1};
            }
        }
        return {};
    }
};
```

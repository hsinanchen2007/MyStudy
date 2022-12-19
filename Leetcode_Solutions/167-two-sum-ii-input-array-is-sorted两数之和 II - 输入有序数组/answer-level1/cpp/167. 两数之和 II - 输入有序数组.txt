感觉挺简单的，应该不用多解释，打败95%+，我也不知道为啥……
```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int low=0;
        int high=numbers.size()-1;
        while(low<high)
        {
            if(numbers[low]+numbers[high]<target)low++;
            else if(numbers[low]+numbers[high]>target)high--;
            else
            {
                vector<int> res(2);
                res[0]=low+1;
                res[1]=high+1;
                return res;
            }
        }
        return vector<int>(0);
    }
};
```

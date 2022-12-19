```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int i = 0;
        int j = numbers.size()-1;
        int n = 0;
        while(i<j)
        {
            n = numbers[i]+numbers[j];
            if(n == target)
            {
                break;
            }
            else if(n>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        ret = {i+1,j+1};
        return ret;
    }
};
```

用数组，其实和双指针一个概念
```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> re;
        for(int i = 0 ; i < numbers.size() ; i++)
        {
            for(int j = i + 1 ; j < numbers.size() ; j++)
            {
                if((numbers[i] + numbers[j]) == target)
                {
                    re.push_back(i+1);
                    re.push_back(j+1);
                    return re;
                }else if((numbers[i] + numbers[j]) > target)
                {
                    break;
                }
                if(numbers[j] == 0)
                {
                    i = j;
                }
            }
        }
        return re;
    }
};
```

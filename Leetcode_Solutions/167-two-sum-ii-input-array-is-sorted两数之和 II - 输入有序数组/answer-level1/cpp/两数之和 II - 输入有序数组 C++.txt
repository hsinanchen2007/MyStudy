```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int left = 0;
        int right = size-1;
        while(left < right)
        {
            if(target == numbers[left] + numbers[right])
                return {left+1, right+1};
            else 
            {
                target > (numbers[left] + numbers[right]) ?  left++ : right--;
            }
        }
        return {};
    }
};
因为输入的是有序数组，通过运用双指针（i是较小数的位置，j是较大数的位置），求头尾两个元素的sum，若sum与target相比太小，i增大，若sum太大，j减小
```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> ans;
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j) //双指针，若sum太小，i增大，若sum太大，j减小
        {
            int sum = numbers[i] + numbers[j];
            if(sum == target)
            {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                return ans;
            }
            else if(sum < target)
                ++ i;
            else
                -- j;
        }
        return ans;
    }
};
```
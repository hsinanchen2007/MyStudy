class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> monotic_stack;
        vector<int> res(nums.size(), -1);
        if (!res.size())
        {
            return res;
        }

        for (auto i = 0; i < nums.size() * 2 - 1; i++)
        {
            while (!monotic_stack.empty() && nums[i % nums.size()] > nums[monotic_stack.top()])
            {
                res[monotic_stack.top()] = nums[i % nums.size()];
                monotic_stack.pop();
            }
            // res[i % nums.size()] = monotic_stack.empty() ? -1 : nums[monotic_stack.top()];
            // * push index rather than value
            monotic_stack.push(i % nums.size());
            // std::cout << nums[monotic_stack.top()] << res[i % nums.size()] << std::endl;
        }
        return res;
    }
};
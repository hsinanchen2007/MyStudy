class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major;//元素
        int counter = 0;

        for (auto c : nums)
        {
            if (counter == 0)
            {
                major = c;
                counter++;
                continue;

            }
            if (c == major)
                counter++;
            else
                counter--;
        }

        return major;
    }
};

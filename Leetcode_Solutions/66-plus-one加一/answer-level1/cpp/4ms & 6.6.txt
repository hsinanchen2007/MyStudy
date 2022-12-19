class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int len = digits.size();
        vector<int> nums(len+1);
        while((len-1>=0) && ((digits[len-1]+1)%10 == 0))
        {
            len--;
        }
        if(0 == len) // 数组全是9
        {
            nums[0] = 1;
            for(int i = 1; i < (len+1); i++)
            {
                nums[i] = 0;
            }
            return nums;
        }
        len = digits.size();
        while(1)
        {
            digits[len-1] = (digits[len-1]+1) % 10; // 末位+1
            if(0 == digits[len-1]) // 判断进位
            {
                len--;
            }
            else
            {
                return digits;
            }
        }
        return digits;
    }
};
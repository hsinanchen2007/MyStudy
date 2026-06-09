```C++ []
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res;
        if(nums.size() == 0)
            return res;
        // 得到两个不同的数的异或结果
        int tmp = 0;
        for(int i=0; i<nums.size(); i++)
            tmp = tmp ^ nums[i];
        // 设置标志位，找到异或结果的最右边一个1
        unsigned int flag = 1;
        int nums1 = 0;
        int nums2 = 0;
        while(flag)
        {
            if(tmp & flag)
                break;
            else
                flag = flag<<1;
        }

        // 以flag将数分为两组，则该两组分别只有一个数只出现一次
        for(int i=0; i<nums.size();i++)
        {
            if(nums[i] & flag)
                nums1 = nums1^nums[i];
            else
                nums2 = nums2^nums[i];
        }
        res.push_back(nums1);
        res.push_back(nums2);
        return res;
    }
};
```


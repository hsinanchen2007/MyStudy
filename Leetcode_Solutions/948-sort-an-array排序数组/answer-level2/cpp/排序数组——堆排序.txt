```C++ []
class Solution {
public:
    void HeapSort(vector<int>& nums, int n)
    {
        for(int i=(n-1)/2; i>=0; i--)
            Sift(nums, i, n-1);
        for(int i=0; i<n-1; i++)
        {
            int tmp = nums[0];
            nums[0] = nums[n-1-i];
            nums[n-1-i] = tmp;
            Sift(nums, 0, n-2-i);
        }
    }

    void Sift(vector<int>& nums, int start, int end)
    {
        int i=start;
        int j = 2*i+1;
        while(j<=end)
        {
            if(j<end && nums[j]<nums[j+1]) j++;
            if(nums[i] > nums[j]) break;
            else
            {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i = j;
                j = 2*i+1;
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        HeapSort(nums, n);
        return nums;
    }
};
```


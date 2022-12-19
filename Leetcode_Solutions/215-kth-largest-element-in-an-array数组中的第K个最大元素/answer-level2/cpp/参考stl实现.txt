`
```c++ []

int findKthLargest(vector<int> &nums, int k)
    {
        //Kth Largest Element in an Array
        int n=nums.size()-k;
        int last=nums.size(),first=0;
        
        while(last-first>3)
        {
            int val=median(nums[first],nums[first+(last-first)/2],nums[last-1]);
            int cut=partition(nums,first,last,val);
            if(cut<=n)
                first=cut;
            else
                last=cut;
        }
        sort(nums.begin()+first,nums.begin()+last);
        return nums[n];
    }
    int median(int num1,int num2,int num3)
    {
        if(num1>num2)
        {
            if(num1>num3)
                return num1;
            else
                return num3;
        }
        else
        {
            if(num2>num3)
                return num2;
            else
                return num3;
        }
    }
    int partition(vector<int>&nums,int first,int last,int val)
    {
        while(true)
        {
            while(nums[first]<val)
                ++first;
            --last;
            while(val<nums[last])
                --last;
            if(!(first<last))
                return first;
            swap(nums[first],nums[last]);
            ++first;
        }
    }
```
`



### 解题思路
利用一个堆来实现一个优先队列。
build_max函数来建堆
heapify函数用来维护堆
max函数用来返回头元素之后，调用heapify函数

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        build_max(nums);
        int result=nums[0];
        while(--k)
        {
            max(nums);
            result=nums[0];
        }
        return result;
    }
    void build_max(vector<int>& nums)
    {
        for(int i=nums.size()/2-1;i>=0;i--)
            heapify(nums,i);
    }
    void heapify(vector<int>& nums,int i)
    {
        int largest;
        int left=i*2+1;
        int right=i*2+2;
        if(left<nums.size()&&nums[left]>nums[i])
            largest=left;
        else 
            largest=i;
        if(right<nums.size()&&nums[right]>nums[largest])
            largest=right;
        if(largest!=i)
        {
            int mid=nums[i];
            nums[i]=nums[largest];
            nums[largest]=mid;
            heapify(nums,largest);
        }
    }
    void max(vector<int>& nums)
    {
        nums[0]=nums[nums.size()-1];
        nums.pop_back();
        heapify(nums,0);
    }
};

```
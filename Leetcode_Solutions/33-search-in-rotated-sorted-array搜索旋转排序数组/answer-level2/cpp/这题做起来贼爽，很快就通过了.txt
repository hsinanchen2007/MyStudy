下面是我的C++代码，仅供参考。
首先找到分界处，然后对两边分别用二分查找，考虑到递归加大了空间复杂度，直接用迭代实现二分就行：
```
int search(vector<int>& nums, int target) {
        int s=nums.size();
        if(s==0)
            return -1;
        int i;
        for(i=0;i<s-1;i++)
        {
            if(nums[i]>nums[i+1])
                break;
        }
        int l=0,h=i;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                l=mid+1;
            else if(nums[mid]>target)
                h=mid-1;
        }
        l=i+1;
        h=s-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                l=mid+1;
            else if(nums[mid]>target)
                h=mid-1;
        }
        return -1;
    }
```

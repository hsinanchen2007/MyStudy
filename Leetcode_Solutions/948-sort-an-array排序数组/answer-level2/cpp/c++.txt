### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        MergeSort(nums,0,nums.size()-1);
        return nums;
    }
    //归并排序
    void merge(vector<int> &arr,int L,int mid,int R)
    {
        int *help = new int[R-L+1];
        int p1=L,p2=mid+1,i=0;
        while(p1<=mid && p2<=R)
        {
            help[i++] = arr[p1]>arr[p2] ? arr[p2++] : arr[p1++];
        }
        while(p1<=mid)
            help[i++] = arr[p1++];
        while(p2<=R)
            help[i++] = arr[p2++];
    
        for (int i=0;i<R-L+1;i++)
        {
            arr[L+i] = help[i];
        }
    }
    void MergeSort(vector<int> &arr,int L,int R)
    {
        if (L < R)
        {
            int mid = L + ((R-L)>>2);  //  (L+R)/2
            MergeSort(arr,L,mid);
            MergeSort(arr,mid+1,R);
            merge(arr,L,mid,R);
        }
    }

    //选择
    void SelectSort(vector<int>& nums)
    {
        for(int i=0;i<nums.size()-1;++i)
        {
            int min =i;
            for(int j=i+1;j<nums.size();++j)
            {
                if(nums[j]<nums[min])  min = j;
            }
            if(min!=i) swap(nums[i],nums[min]);
        }
    }
    //冒泡  超时
    void BubbleSort(vector<int>& nums)
    {
        for(int i=0;i<nums.size()-1;++i)
        {
            bool isswap = false;
            for(int j=0;j<nums.size()-i-1;++j)
            {
                if(nums[j]>nums[j+1])
                {
                    swap(nums[j],nums[j+1]);
                    isswap = true;
                }
            }
            if(!isswap) break;
        }
    }

    //快排
    void QuickSort(vector<int>& nums,int left,int right)
    {
        if(left>=right) return;
        int pivot = nums[left];
        int l = left;
        int r = right;
        while(left<right)
        {
            while(left<right&&nums[right]>=pivot)--right;
            nums[left] = nums[right];
            while(left<right&&nums[left]<=pivot)++left;
            nums[right] = nums[left];

        }
        if(left>=right) nums[left]=pivot;
        QuickSort(nums,l,left-1);
        QuickSort(nums,right+1,r);
    }
};
```
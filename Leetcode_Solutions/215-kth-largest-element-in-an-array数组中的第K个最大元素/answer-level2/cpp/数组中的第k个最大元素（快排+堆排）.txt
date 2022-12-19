### 解题思路
#### 思路一（快排）
借助快排（降序）的思想。
每次分区partition，将分区得到的位置pos与k-1比较。
如果pos>k-1，则下一步应该在区间[left,po-1]中寻找；
如果pos<k-1,则在[pos+1,right]区间寻找，直至pos=k-1。

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()<=1)
            return nums[0];
        int left = 0;
        int right = nums.size()-1;
        
        while(left<=right)
        {
            int povitPos = partition(nums,left,right);
            if(povitPos == k-1) 
                return nums[povitPos];
            else if(povitPos < k-1)
                left = povitPos+1;
            else
                right = povitPos-1;
        }
        return -1;
    }
    int mediumPovit(vector<int>& nums, int left,int mid,int right)
    {
        if(nums[left] < nums[mid])
        {
            swap(nums[left],nums[mid]);
        }
        if(nums[left] < nums[right])
        {
            swap(nums[left],nums[right]);
        }
        if(nums[mid] < nums[right])
        {
            swap(nums[mid],nums[right]);
        }
        return nums[mid];
    }
    int partition(vector<int>& nums, int left,int right)
    {
        if(left == right)
            return left;
        int mid = (left + right)/2;
        int povit = mediumPovit(nums,left,mid,right);
        nums[mid] = nums[right-1];
        nums[right-1] = povit;
        int i = left;
        int j = right-1;
        while(i<j)
        {
            if(nums[i] > povit)
            {
                i++;
            }
            else if(nums[j] <= povit)
            {
                j--;
            }
            else
            {
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i],nums[right-1]);
        return i;
    }
};
```
#### 思路二（堆排序）
堆排序
步骤：
1、将数组转化为一个堆（此题为大根堆）；
2、取出堆顶元素，放到数组末尾，对剩下的数组进行调整，使其满足堆的特性；
3、重复上述步骤k次，找到第k个最大的元素。
```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()<=1)
            return nums[0];
        buildHeap(nums);
        int first = 0;
        int last = nums.size()-1;
        while(k--)
        {
            swap(nums[first],nums[last]);
            last--;
            adjustHeap(nums,first,last);
        }
        return nums[last+1];
    }
    //调整堆，first和last分别是堆顶和堆底在array中的索引
    void adjustHeap(vector<int> &nums,int first,int last)
    {
        //first节点的左子节点
        int curIndex = 2*first+1;
        while(curIndex <= last)
        {
            if(curIndex < last && nums[curIndex] < nums[curIndex+1]) //如果first有两个子节点，选最大的那个交换
            {
                curIndex++;
            }
            if(nums[first] < nums[curIndex])
            {
                swap(nums[first],nums[curIndex]);
                first = curIndex;
                curIndex = 2*first+1;
            }
            else
            {
                break;
            }
        }
        
    }
    //用数组实现堆
    void buildHeap(vector<int> &nums)
    {
        int i = nums.size()/2-1;//第一个非叶子节点
        while(i>=0)
        {
            adjustHeap(nums,i,nums.size()-1);
            i--;
        }
    }
};
```

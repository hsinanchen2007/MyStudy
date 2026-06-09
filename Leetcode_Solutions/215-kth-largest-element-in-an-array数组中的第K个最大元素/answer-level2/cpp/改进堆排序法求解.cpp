1. 注意，因为数组下标是从0开始的；
    所以某个节点i的左孩子：i*2+1；
    某个节点i的右孩子：i * 2+2;
    某个节点i的父亲节点：(i-1)/2;
2. 我比较了系统的sort()函数跟这种改进堆排序求解，发现效率是差不多的。
   说明系统的sort()函数效率还是很高的。

3. 3.该方法利用堆排序只求出了前k个最大值；

```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        HeapSort(nums,k);
        return nums[nums.size()-k];
    }

    //建堆函数
    void Sift(vector<int>& nums,int preToOrder,int n )   //preToOrder是待筛选节点的编号
    {
        int leftChild=2*preToOrder+1;               //待筛选节点编号的左孩子，数组下标从0开始不是1
        while(leftChild<=n)
        {
            if(leftChild<n && nums[leftChild+1]>nums[leftChild]) leftChild++;
            if(nums[preToOrder]>=nums[leftChild])
                    break;
            else
            {
                int temp=nums[leftChild];
                nums[leftChild]=nums[preToOrder];
                nums[preToOrder]=temp;

                preToOrder=leftChild;    //待比较节点下移
                leftChild=2*preToOrder+1;
            }
        }
    }

    //改进堆排序，只找出前k个最大的值
    void HeapSort(vector<int>&nums,int k)
    {
        int n=nums.size()-1;   //最后一个元素节点编号
        for(int i=(n-1)/2;i>=0;i--)
            Sift(nums,i,n);
        for(int i=n;i>=n-k+1;i--)
        {
            int temp=nums[0];nums[0]=nums[i];nums[i]=temp;
            Sift(nums,0,i-1);
        }
    }
};
```

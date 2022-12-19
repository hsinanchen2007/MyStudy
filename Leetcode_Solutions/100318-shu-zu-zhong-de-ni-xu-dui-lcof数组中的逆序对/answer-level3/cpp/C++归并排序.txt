### 解题思路
归并排序，假设左串为A,右串为B，A与B均为已排序好的序列，如果B串中下标为right的数比A串中下标为left的数要小，那么A串中下标为left之后的数均比B串中的这个数要大，那么就出现了len(A)-left+1个逆序数。

### 代码

```cpp
#include<numeric>
class Solution {
    int count=0;
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int n = nums.size();
        merge_sort(nums,0,n-1);
        return count;
    }

    void merge_sort(vector<int>& nums,int start,int end){
        int mid = (start+end)/2;
        if(start==end){
            return;
        }
        else{
            merge_sort(nums,start,mid);
            merge_sort(nums,mid+1,end);
            merge(nums,start,mid,mid+1,end);
        }
    }

    void merge(vector<int>& nums,int Astart, int Aend, int Bstart, int Bend){
        int left=Astart,right=Bstart;
        int k=0;
        vector<int> tem (Bend-Astart+1,0);
        while(left<=Aend && right<=Bend){
            if (nums[left] <= nums[right]){
                tem[k++] = nums[left++];
            }
            else{
                tem[k++] = nums[right++];
                count += Aend-left+1;
            }
        }
        if(left>Aend){
            while(right<=Bend)
                tem[k++] = nums[right++];
        }
        else if(right>Bend){
            while(left<=Aend)
                tem[k++] = nums[left++];
        }
        int i=Astart,j=0;
        while(i<=Bend && j<tem.size()){
            nums[i++] = tem[j++];
        }
    }
};
```
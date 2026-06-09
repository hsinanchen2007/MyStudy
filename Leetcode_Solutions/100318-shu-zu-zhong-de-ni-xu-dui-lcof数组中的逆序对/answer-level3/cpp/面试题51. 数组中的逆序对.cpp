### 暴力解法
直接遍历，求每一个元素后面位置比当前元素小的个数。
### 时间/空间复杂度
时间复杂度：O(n2)
空间复杂度：O（1）
### 代码
```
```
### 归并排序法
见剑指offer
### 时间/空间复杂度
时间复杂度：O(nlogn)
空间复杂度：O（n）
### 代码

```cpp
class Solution {
public:
    int count=0;
    int reversePairs(vector<int>& nums) {
        int sz=nums.size();
        if(sz<2) return 0;
        mergeSort(nums,0,sz-1);
        return count;
    }

    void merge(vector<int> &nums,int left,int mid,int right){
        int p1=left,p2=mid+1;
        vector<int> tmp(right-left+1);
        int k=0;
        while(p1<=mid&&p2<=right){
            if(nums[p1]<=nums[p2]){
                tmp[k++]=nums[p1++];
            }else{
                tmp[k++]=nums[p2++];
                count+=mid-p1+1;
            }
        }
        while(p1<=mid) tmp[k++]=nums[p1++];
        while(p2<=right) tmp[k++]=nums[p2++];
        k=0;
        for(int i=left;i<=right;++i){
            nums[i]=tmp[k++];
        }
    }
    void mergeSort(vector<int>& nums,int left,int right){
        if(left==right) return;
        int mid=left+((right-left)>>1);
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
};
```
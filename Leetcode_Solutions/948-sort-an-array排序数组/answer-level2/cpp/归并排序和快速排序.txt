```cpp
class Solution {
public:
    int helpFunction(vector<int>&nums,int start,int end){
        int p = nums[start];
        while(start<end){
            while(nums[end]>p&&start<end) end--;
            nums[start] = nums[end];
            while(nums[start]<=p&&start<end) start++;
            nums[end] = nums[start];
        }
        nums[start] = p;
        return start;
    }
    void quickSort(vector<int>& nums,int start,int end){
        if(start>=end) return;
        int mid = helpFunction(nums,start,end);
        quickSort(nums,start,mid-1);
        quickSort(nums,mid+1,end);
    }
    void merge(vector<int>&nums,int start,int mid,int end){
        // mid 属于前一数组
        // 该种方法会超时
        // for(int i=start;i<=mid;i++){
        //     // 遍历前半段 和后半段进行合并
        //     if(nums[i]>nums[mid+1]){
        //         swap(nums[i],nums[mid+1]); // 交换较大值到后半段起点位置
        //         for(int j=mid+1;j<end;j++){
        //             if(nums[j]>nums[j+1]) {
        //                 swap(nums[j],nums[j+1]);
        //                 }
        //             else break; 
        //         }
        //     }
        // }
        int dp[end-start+1]; // 空间换时间，临时存储合并
        int a = start;
        int b = mid+1;
        int i = 0;
        while(a<=mid&&b<=end){
            dp[i++] = nums[a]<=nums[b]?nums[a++]:nums[b++];
        }
        while(a<=mid) dp[i++] = nums[a++];
        while(b<=mid) dp[i++] = nums[b++];
        for(int j=0;j<i;j++){
            nums[start+j] = dp[j];
        }
    }
    void mergeSort(vector<int>&nums,int start,int end){
        if(start>=end) return;
        int mid = (start+end)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,end); // 合并两段有序数组
    }
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        // 快速排序
        // quickSort(nums,0,len-1);
        // 归并排序
        mergeSort(nums,0,len-1);
        return nums;
    }
};
```
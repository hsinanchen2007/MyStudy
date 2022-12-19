### 解题思路
不借助辅助数组，采用归并排序前统计两个升序数组的逆序对，这种方法会超时。
这种方法步骤是：
在每次归并排序的过程中实现两步：
1、统计两个升序数组之间的有序对对数；
2、合并两个升序数组，为上层提供一个有序的数组。
我们需要利用空间换时间，将上述两个步骤一次完成：边查找有序对数，边构造有序数组。
两个步骤之所以不能同时进行，举例如下：
数组左侧：[start,start+1,start+2...,mid] 右侧：[mid+1,mid+2,...,end]。 两数组之间的有序对数量初始化为merge = 0;
```
int merge = 0; // 初始化两个有序数组之间的逆序对数
int l = mid; // 从后往前查找有序对数 左侧遍历指针
int r = end; // 右侧遍历指针
while(l>=start&&r>=mid+1){
    if(nums[l]>nums[r]){
        merge += r - mid; // [mid+1,r] 这个区间内的值都可以和nums[l] 构成逆序对
        // 很显然的是，该步骤已经知道nums[l]是当前遍历到的最大值，他应该放在nums[r]的位置，但我们不能放。因为nums[l-1]也可能与nums[r]构成逆序对，换了之后肯定就不是逆序对了。因此合并有序数组和统计逆序对不能同时在原数组内进行。但我们在该处可以将nums[l]暂存到另外一个数组中，也就是用一个辅助数组保存排序后的结果（时刻记得，我们的上层是需要一个排序后的结果的，因此我们必须要进行排序过程。）
        l--;
    }
    else{
        r--;//nums[l]已经是最大值了，他都不能和nums[r] 构成逆序对，别的肯定也不行，直接剔除掉nums[r]
    }
}
```
因此我们借助辅助数组。辅助数组引入的初衷是为了将获得两个有序数组之间的逆序对数和将两个有序数组合并为一个有序数组这个两个步骤同时进行，降低时间复杂度。
另一个需要注意的点是 我们需要交换copy和nums数组的位置。原因是我们递归的上层需要一个排序好的数组，很显然，我们是根据nums将排序后的部分存放在copy数组中。因此我们给上层一个排序后的数组时，给到的应该是copy数组。
### 代码

```cpp
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        // 归并排序。
        int len = nums.size();
        if(len<2) return 0;
        vector<int> copy(nums.begin(),nums.end());//复制数组
        int res = helpFunction(nums,copy,0,len-1);
        // for(auto c:nums) cout<<c<<" ";
        return res;
    }
    int helpFunction(vector<int>& nums,vector<int>& copy,int start,int end){
        if(start==end) return 0;
        int mid = (start+end)/2;
        // 重点关注区域：一定要思考清楚辅助数组的作用，他并不是单纯用来存储排序好的数组的。
        // 当在本层统计好数目后 排序好后，copy数组部分有序，然而nums数组仍无序。而我们在上层需要排序好的结果，因此 上层需要使用本层的copy数组。因此要发生交换。
        // 可以理解为，第二个参数的返回结果，是部分有序的，要在本层用来本层的有序列表合并。
        int left = helpFunction(copy,nums,start,mid); // 左侧逆序对数
        int right = helpFunction(copy,nums,mid+1,end); // 右侧逆序对数
        
        // 统计两个升序数组相比，逆序对的对数
        // int merge = 0;
        // int i = mid,j = end;
        // while(i>=start&&j>=mid+1){//从后向前比较
        //     if(nums[i]>nums[j]){merge+=j-mid;i--;}
        //     else j--;
        // }
        // 原地合并两个有序数组
        // [0,mid] [mid+1,end]
        // i = start;
        // while(i<=mid){
        //     while((nums[i]<=nums[mid+1])&&i<=mid) i++;// 找到交换点
        //     if(i>mid) break;
        //     swap(nums[i],nums[mid+1]);// 把较大值传递给nums[mid+1] 然后寻找该值在mid+1到end中的位置
        //     int j = mid+2;
        //     while(j<=end&&nums[j]<nums[j-1]) {swap(nums[j],nums[j-1]);j++;}
        // }
        
        // 借助辅助数组 
        // 思考 你需要把nums的前后两部分分别做到有序 
        int i = mid,j = end, merge = 0; // 两段有序序列遍历指针
        int t = end; // 在 copy 序列中的放置指针
        while(i>=start&&j>=mid+1){
            if(nums[i]>nums[j]){
                copy[t] = nums[i];
                merge += j-mid; 
                i--;
            }
            else{
                copy[t] = nums[j];
                j--;
            }
            t--;
        }
        for(;i>=start;i--,t--) copy[t] = nums[i];
        for(;j>=mid+1;j--,t--) copy[t] = nums[j];
        int count = left + right + merge;
        // cout<<start<<" "<<end<<" :"<<left<<" "<<right<<" "<<merge<<" "<<endl;
        return count;
    }
};
```
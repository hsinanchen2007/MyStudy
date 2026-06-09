### 解题思路
找bug找了一晚上加一早上，我太难了。。。
一直提交一直溢出！
下面的切分代码在快排中是没问题的，因为快排中会有一句if(lo>=hi) return ;
所以这里的quickSelect里也要加一句限制if(lo == hi) return v[lo];
### 代码

```cpp
class Solution {
    int partition(vector<int>& v, int lo, int hi) {
        int p = v[lo];
        int i = lo, j = hi + 1;
        while (true) {
            while (v[--j] < p);
            //注意这里，当输入只有一个的时候，v[++i]溢出！！！！！我终于找到你了！！！
            while (v[++i] > p) if (i == hi) break;
            if (i >= j) break;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
        v[lo] = v[j];
        v[j] = p;
        return j;
    }
int  quick_select(vector<int>& v, int lo, int hi, int k) {
    //
    if(lo ==hi) return v[lo];
    int index = partition(v, lo, hi);
    if (index == k-1 ) return v[index];
    else if (index < k-1) return quick_select(v, index+1, hi, k);
    else return quick_select(v,lo, index - 1, k);

}   
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums,0 ,nums.size()-1,k);
    }

};
//  public int findKthLargest(int[] nums, int k){
//         // k是要求的第几大(从1开始计数),k-1即是数组中的序号(0开始计数)
//         return findKthLargest(nums,0,nums.length-1,k-1);
//     }
//     public int findKthLargest(int[] nums,int low,int high,int k){
//         int index = partition(nums,low,high,k);
//         if (index == k)
//             return nums[index];
//         else if (index>k)
//             return findKthLargest(nums,low,index-1,k);
//         else
//             return findKthLargest(nums,index+1,high,k);
//     }

//     // 同快排的partation,每次确定一个枢轴的位置,并返回其index
//     // 找第k 大 的数就把数组按大->小排列
//     private int partition(int[] nums,int low,int high,int k){
//         int pivot = nums[low];

//         while (low<high){
//             while (low<high && nums[high]<=pivot) // nums[high]<=pivot 体现出把数组按大->小排列
//                 high--;
//             nums[low] = nums[high];

//             while (low< high && nums[low]>=pivot)
//                 low++;
//             nums[high] = nums[low];
//         }

//         nums[low] = pivot;
//         return low;
//     } 

```
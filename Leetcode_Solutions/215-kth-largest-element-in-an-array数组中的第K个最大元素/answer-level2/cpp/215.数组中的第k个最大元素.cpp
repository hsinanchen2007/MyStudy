### 解题思路
一种解法是构建一固定长度的堆，遍历之后堆首就是第k大元素
另一种是快速排序的分区函数。

### 代码

```cpp
#include <queue>
using namespace std;
class Solution {
public:
    // // 构建一个固定长度的小顶堆，遍历之后堆首就是第 k 大元素。
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int,vector<int>,greater<int> > q;
    //     for(int i=0;i<nums.size();++i){
    //         q.push(nums[i]);
    //         if(q.size() > k){
    //             q.pop();
    //         }
    //     }
    //     return q.top();
    // }
    int partion(vector<int>& nums,int begin,int end){
        int p = nums[end];
        int i = begin;
        for(int j=begin;j<end;++j){
            if(nums[j] < p){
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                i++;
            }
        }
        nums[end] = nums[i];
        nums[i] = p;
        return i;
    }
    // 快速选择里面的分区方法
    int findKthLargest(vector<int>& nums, int k) {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end){
            int p = partion(nums,begin,end);
            if(nums.size()-p == k){
                return nums[p];
            }else if(nums.size()-p < k){
                end = p - 1;
            }else{
                begin = p + 1;
            }
        }
        return -1;
    }
};
```
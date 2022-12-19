### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/7de5ead98ff5d3cfa17bccca02c23dec910d84f94642d908c223554ba083610b-%E6%8D%95%E8%8E%B7.PNG)
此处撰写解题思路

暴力解法先对数组排序，再遍历，复杂度k*LogN,当N远大于K时效果较差。
如果维护一个小根堆，只保存数组中最大的K个数，那么堆顶元素即为第K大的数。
遍历数组元素，在堆不空的情况下，如果当前数组元素小于堆顶元素，则肯定不在前K个最大元素之列，什么也不做。
如果当前元素大于堆顶元素，则堆顶元素被“挑战者”PK掉了，将其pop()，然后将“挑战者”push进堆中。
这样一来只需维护K个元素的堆即可，时间复杂度：遍历数组用O（n），堆的维护用logK，共NlogK



### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //创建一个小根堆，用于存储目前数组中最大的K个数,且堆顶元素在K个元素中最小
        priority_queue< int, vector<int>, greater<int> > smallRootHeap;
        for(int i = 0; i < nums.size(); i++){
            if(smallRootHeap.size() < k){
                smallRootHeap.push(nums[i]);
            }else if(smallRootHeap.top() < nums[i]){
                smallRootHeap.pop();
                smallRootHeap.push(nums[i]);
            }
        }
        return smallRootHeap.top();
    }
};
```
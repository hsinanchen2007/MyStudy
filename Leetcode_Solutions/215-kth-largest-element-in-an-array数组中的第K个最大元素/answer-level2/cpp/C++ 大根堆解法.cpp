1. 首先考虑在大根堆中，堆顶为该堆的最大值。应此包含N-K个元素的大根堆的堆顶元素为该N-K个元素中的最大值。
2. 应此我们考虑在将原数组构建堆之后删除k-1次堆顶，得到的堆的堆顶即是我们所需要求取的第K大的元素。
3. 应为建立一次堆的复杂度为log(n),应此整个算法的复杂度为klog(n).
4. 代码如下：
5. ```
int findKthLargest(vector<int>& nums, int k) {
        int length = nums.size();
        make_heap(nums.begin(),nums.end());
        for(int i = 0; i < k-1; i++){
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return nums[0];
    }
```

其中make_heap和pop_heap函数是c++头文件<algorithm>中提供的构建堆的函数和删除堆顶的函数。
而pop_heap()函数默认将堆顶元素放在vector的最末尾，应此为了真正删除该元素还需要调用vector的pop_back()函数。

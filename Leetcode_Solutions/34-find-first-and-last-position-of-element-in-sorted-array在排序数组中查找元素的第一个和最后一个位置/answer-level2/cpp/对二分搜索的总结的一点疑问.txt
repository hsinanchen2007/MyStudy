1.看了博客或者lc中的解题，发现其中貌似有误，比如这个博客[二分查找详解](https://www.cnblogs.com/kyoner/p/11080078.html)
作者阐述循环条件为left < right，即采用小于作为循环条件时，说要打上一个补丁，原文如下：
“while(left < right)的终止条件是 left == right，写成区间的形式就是 [right, right]，或者带个具体的数字进去 [2, 2]，这时候搜索区间非空，还有一个数 2，但此时 while 循环终止了。也就是说这区间 [2, 2] 被漏掉了，索引 2 没有被搜索，如果这时候直接返回 -1 就可能出现错误。”

我认为这是不对的，实际上最终这个区间中的数已经被搜索过了。具体分析如下：
循环终止的条件是left == right，假设为2，最后一次搜索的区间一定是[2,3]或者[1,2]或者[1,2)中的一种
1.假设为[1,2]，那么2不是数组的最后一个元素，之所以现在right为2，是因为前几次2已经作为middle与targe进行了比较，所以最终区间变为[2,2]时， 2已被搜索
2.假设为[1,2), 那么最终的区间其实是(2,2)，索引2已经越界，不存在元素，不需要搜索
3.假设为[2,3]，在这最后一次循环中middle = left+(right-left)/2 = 2+(3-2)/2=2, 2仍然会被搜索

综上，当循环条件为left<right时，无需在最后打上补丁。对于搜索边界的题目而言，只需要考虑left是否为nums.size()即可。
下面是我对本道题的解法：
`    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret{-1, -1};
        if(nums.empty())
        {
            return ret;
        }
        
        int left = 0;
        int right = nums.size();

        while(left < right)
        {
            int middle = left + (right - left) / 2;
            if(nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }

        if(left == nums.size() || nums[left] != target)
        {
            return ret;
        }

        ret[0] = ret[1] = left;

        // 由于左侧边界已找到，下面要找的右边界一定位于left的右边，因此left无需初始化为0
        // 只需将right重新设置为nums.size()即可
        right = nums.size();
        
        while(left < right)
        {
            int middle = left + (right - left) / 2;
            if(nums[middle] <= target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }

        // 由于目标数存在，因此右边界必然存在，且最后循环终止时left和right相等且位于有边界的下个位置，因此无需再做任何判断，直接赋值
        ret[1] = right - 1;
        
        return ret;
    }`
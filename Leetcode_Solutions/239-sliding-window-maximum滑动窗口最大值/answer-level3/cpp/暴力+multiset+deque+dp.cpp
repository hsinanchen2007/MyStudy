1. 暴力
```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int nums_size=nums.size();
        if (nums_size==0)
            return {};
        vector<int> answer(nums_size-k+1);
        for (int i=0;i<=nums_size-k;++i)
        {
            int max=INT_MIN;
            for (int j=0;j<k;++j)
                if (nums.at(i+j)>max)
                    max=nums.at(i+j);
            answer.at(i)=max;
        }
        return answer;
    }
};
```

2. mutltiset
* [multiset介绍](https://www.cnblogs.com/ChinaHook/p/6985444.html)
直接利用multiset自动排序的特性
```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int nums_size=nums.size();
        if (nums_size==0)
            return {};
        multiset<int,greater<int>> window;
        for (int i=0;i<k;++i)
            window.insert(nums.at(i));
        vector<int> answer;
        answer.push_back(*window.begin());
        for (int i=k;i<nums_size;++i)
        {
            window.insert(nums.at(i));
            window.erase(window.find(nums.at(i-k)));
            answer.push_back(*window.begin());
        }
        return answer;
    }
};
```

3. deque双端队列
* [deque介绍](https://www.cnblogs.com/linuxAndMcu/p/10260124.html)
维护一个窗口
它内部是按从大到小排好序的
可以理解为进入一个元素，就可以把前面比它小的元素全部从尾部出队
保证了降序的同时，排除了过小的元素
* [推荐详细题解](https://leetcode-cn.com/problems/sliding-window-maximum/solution/dan-diao-dui-lie-by-labuladong/)

```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        int nums_size=nums.size();
        if (nums_size==0)
            return {};
        for (int i=0;i<k;++i)
        {
            while (!window.empty() && nums.at(i)>window.back())
                window.pop_back();
            window.push_back(nums.at(i));
        }
        vector<int> answer(nums_size-k+1);
        answer.at(0)=window.front();
        int index=1;
        for (int i=k;i<nums_size;++i)
        {
            if (nums.at(i-k)==window.front())
                window.pop_front();
            while (!window.empty() && nums.at(i)>window.back())
                window.pop_back();
            window.push_back(nums.at(i));
            answer.at(index)=window.front();
            ++index;
        }
        return answer;
    }
};
```

4. 动态规划
有点奇思妙想
官方题解讲得比较详细了，可以直接看[官方题解](https://leetcode-cn.com/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetcode-3/)
将数组划分成k个块
left数组为对应块中从左到右最大的数字
right数组为对应块中从右到左最大的数字
那么answer.at(index)=max(left.at(i+k-1),right.at(i))
举个例子
[1,3,-1][-3,5,3][6,7] k=3
当遍历到i=1即窗口是(3,-1,-3)时
窗口这时涉及到两个块了
所以只需right.at(1)和left.at(3)比较即可

```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int nums_size=nums.size();
        if (nums_size==0)
            return {};
        vector<int> left(nums_size);
        for (int i=0;i<nums_size;i=i+k)
        {
            left.at(i)=nums.at(i);
            for (int j=i+1;j<nums_size && j-i<k;++j)
                left.at(j)=max(left.at(j-1),nums.at(j));
        }
        vector<int> right(nums_size);
        for (int i=0;i<nums_size;i=i+k)
        {
            int j;
            if (i+k-1<nums_size)
                j=i+k-1;
            else
                j=nums_size-1;
            right.at(j)=nums.at(j);
            for (--j;j>=i;--j)
                right.at(j)=max(right.at(j+1),nums.at(j));
        }
        vector<int> answer(nums_size-k+1);
        int index=0;
        for (int i=0;i+k-1<nums_size;++i)
        {
            answer.at(index)=max(left.at(i+k-1),right.at(i));
            ++index;
        }
        return answer;
    }
};
```




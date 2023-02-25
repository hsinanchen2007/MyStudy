/*

https://leetcode.cn/problems/meeting-scheduler/

1229. 安排会议日程

提示
中等
63
company
谷歌 Google
company
亚马逊
company
彭博 Bloomberg

给定两个人的空闲时间表：slots1 和 slots2，以及会议的预计持续时间 duration，请你为他们安排 时间段最早 且合适的会议时间。
如果没有满足要求的会议时间，就请返回一个空数组。

「空闲时间」的格式是 [start, end]，由开始时间 start 和结束时间 end 组成，表示从 start 开始，到 end 结束。 

题目保证数据有效：同一个人的空闲时间不会出现交叠的情况，也就是说，对于同一个人的两个空闲时间 [start1, end1] 和 [start2, end2]
，要么 start1 > end2，要么 start2 > end1。 

示例 1：

输入：slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 8
输出：[60,68]

示例 2：

输入：slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 12
输出：[]
 
提示：

1 <= slots1.length, slots2.length <= 104
slots1[i].length, slots2[i].length == 2
slots1[i][0] < slots1[i][1]
slots2[i][0] < slots2[i][1]
0 <= slots1[i][j], slots2[i][j] <= 109
1 <= duration <= 106

*/

class Solution100 {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(begin(slots1), end(slots1));
        sort(begin(slots2), end(slots2));

        int i = 0;  // slots1's index
        int j = 0;  // slots2's index

        while (i < slots1.size() && j < slots2.size()) {
        const int start = max(slots1[i][0], slots2[j][0]);
        const int end = min(slots1[i][1], slots2[j][1]);
        if (start + duration <= end)
            return {start, start + duration};
        if (slots1[i][1] < slots2[j][1])
            ++i;
        else
            ++j;
        }

        return {};
    }
};


class Solution99 {
public:
    // 2023.2.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/meeting-scheduler.cpp
    // Time:  O(n) ~ O(nlogn)
    // Space: O(n)
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<pair<int, int>> min_heap;
        for (const auto& slot : slots1) {
            if (slot[1] - slot[0] >= duration) {
                min_heap.emplace_back(slot[0], slot[1]);
            }
        }
        for (const auto& slot : slots2) {
            if (slot[1] - slot[0] >= duration) {
                min_heap.emplace_back(slot[0], slot[1]);
            }
        }
        make_heap(min_heap.begin(), min_heap.end(), greater<>());  // Time: O(n)
        while (min_heap.size() > 1) {
            pop_heap(min_heap.begin(), min_heap.end(), greater<>());  // Time: O(logn)
            const auto left = min_heap.back();
            min_heap.pop_back();
            pop_heap(min_heap.begin(), min_heap.end(), greater<>());
            const auto right = min_heap.back();
            min_heap.pop_back();
            min_heap.emplace_back(right);
            push_heap(min_heap.begin(), min_heap.end(), greater<>());
            if (left.second - right.first >= duration) {
                return {right.first, right.first + duration};
            }
        }
        return {};
    }
};


class Solution98 {
public:
    // 2023.2.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/meeting-scheduler.cpp
    // Time:  O(nlogn)
    // Space: O(n)
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (const auto& slot : slots1) {
            if (slot[1] - slot[0] >= duration) {
                min_heap.emplace(slot[0], slot[1]);
            }
        }
        for (const auto& slot : slots2) {
            if (slot[1] - slot[0] >= duration) {
                min_heap.emplace(slot[0], slot[1]);
            }
        }
        while (min_heap.size() > 1) {
            const auto left = min_heap.top();
            min_heap.pop();
            const auto right = min_heap.top();
            if (left.second - right.first >= duration) {
                return {right.first, right.first + duration};
            }
        }
        return {};
    }
};


class Solution97 {
public:
    // 2023.2.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/meeting-scheduler.cpp
    // Time:  O(nlogn)
    // Space: O(n)
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int i = 0, j = 0;
        while (i < slots1.size() && j < slots2.size()) {
            const auto& left = max(slots1[i][0], slots2[j][0]);
            const auto& right = min(slots1[i][1], slots2[j][1]);
            if (left + duration <= right) {
                return {left, left + duration};
            }
            if (slots1[i][1] < slots2[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return {};
    }
};


class Solution96 {
public:
    // 2023.2.24, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/1229.Meeting-Scheduler/1229.Meeting-Scheduler_2_pointers.cpp
    /*
        解法1：
        常规的扫描线方法。当某个时刻的计数器由1变成2时，说明是两人都有空的起点；当某个时候的计数器有2变成1时，说明是两人都有空的终点。
        查看这两个时刻的差是否大于duration。    
    */
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) 
    {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int i=0, j=0;
        while (i<slots1.size() && j<slots2.size())
        {
            int start = max(slots1[i][0], slots2[j][0]);
            int end = min(slots1[i][1], slots2[j][1]);
            if (end-start >= duration)
                return {start, start+duration};
            
            if (slots1[i][1] < slots2[j][1])
                i++;
            else
                j++;
        }
        return {};
    }
};


class Solution {
    static bool cmp(pair<int,int>a, pair<int,int>b)
    {
        if (a.first==b.first)
            return a.second > b.second;
        else
            return a.first<b.first;
    }
public:
    // 2023.2.24, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/1229.Meeting-Scheduler/1229.Meeting-Scheduler_diff_array.cpp
    /*
        解法2：
        因为每个人的slots都是互不相交的，所以将两个人的slots先预排序。然后用双指针来逐个考察两个人的队首window。如果两个人的
        window相交，就判断相交长度是否大于等于duration。其他情况（不相交，或者相交时间不够）就舍弃较早结束的window，并移动那
        个人的指针。    
    */
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) 
    {
        vector<pair<int,int>>p;
        for (auto x: slots1)
        {
            p.push_back({x[0],1});
            p.push_back({x[1],-1});
        }
        for (auto x: slots2)
        {
            p.push_back({x[0],1});
            p.push_back({x[1],-1});
        }
        sort(p.begin(),p.end(),cmp);
        
        int count = 0;
        int start;
        vector<int>ret;
        for (int i=0; i<p.size(); i++)
        {
            count += p[i].second;
            if (p[i].second==1 && count==2)
            {
                start = p[i].first;
            }
            else if (p[i].second==-1 && count==1 && p[i].first-start>=duration)
            {
                ret={start,start+duration};
                return ret;
            }
        }
        return {};
            
    }
};

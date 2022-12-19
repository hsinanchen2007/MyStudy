### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 结果数组
        vector<vector<int>> res;
        // 数组没有元素
        if (intervals.size()==0) {
            return res;
        }
        // cmp迭代器，参数为对vector<int>数组的排序，以数组首元素升序排
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b) {
            return a[0]<b[0];
        });
        // 结果数组添加首元素
        res.push_back(intervals[0]);
        // 遍历排序好的原数组
        for (int i=1;i<intervals.size();i++) {
            // 如果与res的最后一个区间不能合并，就直接插入
            if (intervals[i][0] > res.back()[1]) {
                res.push_back(intervals[i]);
            }
            // 否则与res最后一个区间合并
            else {
                res.back()[0] = min(res.back()[0],intervals[i][0]);
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            }
        }
        return res;
    }
    
    // 插入排序
    void insertSort(vector<vector<int>>& intervals, int intervalsSize) {
        for (int i = 1; i < intervalsSize; i++) {
            for(int j=0; j<i; j++) {
                if (intervals[j][0] > intervals[i][0]) {
                    vector<int> tmp = intervals[j];
                    intervals[j] = intervals[i];
                    intervals[i] = tmp;
                }
            }
        }
    }
    
    // 选择排序
    void selectsort(vector<vector<int>>& intervals, int intervalsSize) {
        int k;
        for (int i = 0; i < intervalsSize-1; i++) {
            k=i;
            for (int j = k + 1; j < intervalsSize; j++) {
                if (intervals[j][0] < intervals[k][0]) {
                    k = j;
                }
            }
            if (i!=k) {
                vector<int> tmp = intervals[i];
                intervals[i] = intervals[k];
                intervals[k] = tmp;
            }
        }
    }
    
    // 快速排序
    void quicksort(vector<vector<int>>& intervals, int start, int end) {
        int i, j;
        vector<int> temp;
        if (start > end) {
            return;
        }
        temp = intervals[start];
        i = start;
        j = end;
        while (i != j) {
            while (i < j && intervals[j][0] >= temp[0]) {
                j--;
            }
            while (i < j && intervals[i][0] <= temp[0]) {
                i++;
            }
            if (i < j) {
                vector<int> tmp = intervals[i];
                intervals[i] = intervals[j];
                intervals[j] = tmp;
            }
        }
        intervals[start] = intervals[i];
        intervals[i] = temp;
        // 递归调用，对分割点
        quicksort(intervals, start, i - 1);
        quicksort(intervals, i + 1, end);
    }
};



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    if (intervals.size()==0) {
        return res;
    }
    sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b) {
        return a[0]<b[0];
    });
    res.push_back(intervals[0]);
    for (int i=1; i<intervals.size(); i++) {
        if (intervals[i][0] > res.back()[1]) {
            res.push_back(intervals[i]);
        }
        else {
            res.back()[0] = min(res.back()[0],intervals[i][0]);
            res.back()[1] = max(res.back()[1],intervals[i][1]);
        }
    }
    return res;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = merge(intervals);
    for (int i=0; i<res.size(); i++) {
        vector<int> temp = res[i];
        for (int j=0; j<temp.size(); j++) {
            cout << temp[j] << ',';
        }
        cout << endl;
    }
}


```
```C++
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 1.直接插入排序
vector<int> sortArray1(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        int var = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > var)
            nums[j+1] = nums[j], j--;;
        nums[j+1] = var;
    }
    return nums;
}

// 2.冒泡排序
vector<int> sortArray2(vector<int> &nums) {
    int n = nums.size();
    // 优化版本，用一个flag记录上一轮迭代是否发生交换
    for (int i = n - 1; i >= 1; i--) {
        bool flag = true;
        for (int j = 1; j <= i; j++) {
            // 若nums[j] < nums[j-1]，则交换
            if (nums[j] < nums[j-1]) {
                int temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
                flag = false;
            };
        }
        if (flag) break;
    } 
    return nums;
}

// 3.归并排序
void merge(vector<int> &nums, int left, int mid, int right) {
    if (left == right) return;
    vector<int> lefthalf(nums.begin()+left, nums.begin()+mid+1);
    vector<int> righthalf(nums.begin()+mid+1, nums.begin()+right+1);
    int idx = left;
    int i = 0, j = 0;
    for (; i < lefthalf.size() && j < righthalf.size();) {
        if (lefthalf[i] < righthalf[j])
            nums[idx] = lefthalf[i], i++, idx++;
        else
            nums[idx] = righthalf[j], j++, idx++;
    }
    if (i < lefthalf.size()) 
        while (i < lefthalf.size()) nums[idx++] = lefthalf[i++];
    if (j < righthalf.size())
        while (j < righthalf.size()) nums[idx++] = righthalf[j++];
}

void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid+1, right);
    merge(nums, left, mid, right);
}

vector<int> sortArray3(vector<int> &nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}

// 4.快速排序
int partition(vector<int> &nums, int left, int right) {
    int pivot = nums[left];
    int i = left, j = right;
    // 将< pivot部分放在左侧，> pivot部分放在右侧
    while (i <= j) {
        while (i <= j && nums[i] <= pivot) i++;
        while (i <= j && nums[j] >= pivot) j--;
        if (i <= j) {
            int temp = nums[i];
            nums[i] = nums[j], nums[j] = temp;
        }
    }
    nums[left] = nums[j];
    nums[j]= pivot;
    return j;
}

void quickSort(vector<int> &nums, int left, int right) {
    if (left >= right) return;
    int pos = partition(nums, left, right);
    quickSort(nums, left, pos-1);
    quickSort(nums, pos+1, right);
}

vector<int> sortArray4(vector<int> &nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
}

// 5.堆排序
// 主要两个操作：建堆(相当于元素插入) 调整(相当于元素删除)
// 堆排序的基本思路如下：
//      在数组中，原地建堆，从第一个元素开始，每个节点进行从根结点开始，自底向上的调整
//      这是因为每一个元素相当于往之前的堆中插入，并且都有成为最大元素的可能性
//      然后每次pop堆顶，为当前的最大元素，再把最后一个元素放入堆顶，进行自顶向下的调整
//      实际上可以直接将堆顶部元素和最后一个元素交换即可
//      因此，关键是自顶向下的调整的实现
void adjust(vector<int> &nums, int n) {
    if (n == 1) return;
    int parent = 0, child = 2 * parent + 1;
    while (child < n) {
        if (child + 1 < n && nums[child + 1] > nums[child]) child += 1;
        if (nums[child] > nums[parent]) {
            int var = nums[child];
            nums[child] = nums[parent], nums[parent] = var;
            parent = child;
            child = child * 2 + 1;
        } else {
            return;
        }
    }
}

void buildHeap(vector<int> &nums) {
    if (nums.size() <= 1) return;
    for (int i = 1; i < nums.size(); i++) {
        // 每个元素自底向上调整
        int parent = (i - 1) / 2;
        int child = i;
        while (parent >= 0 && nums[parent] < nums[child]) {
            int var = nums[child];
            nums[child] = nums[parent];
            nums[parent] = var;
            child = parent;
            parent = (parent - 1) / 2;
        }
    }
}

void heapSort(vector<int> &nums) {
    buildHeap(nums);
    for (int i = nums.size(); i >= 2; i--) {
        // 交换当前最大元素和最后一个元素
        int var = nums[i - 1];
        nums[i - 1] = nums[0];
        nums[0] = var;
        adjust(nums, i - 1);
    }
}

vector<int> sortArray5(vector<int> &nums) {
    heapSort(nums);
    return nums;
}


class Solution {
public:
    vector<int> sortArray(vector<int> &nums);
};

vector<int> Solution::sortArray(vector<int> &nums) {
    return sortArray5(nums);
}

// Test
int main(int argc, char *argv[]) {
    vector<int> nums;
    string line;
    Solution slu;
    while (getline(cin, line)) {
        istringstream input(line);
        int var;
        while (input >> var) nums.push_back(var);
        slu.sortArray(nums);
        for_each(nums.begin(), nums.end(), [](int a){cout << a << ' ';});
        cout << endl;
        nums.clear();
    }
    return 0;
}


```

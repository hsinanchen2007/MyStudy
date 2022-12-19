## 数组的快速排序

快速排序，是最常用的一种排序算法，在各种排序算法中，快排的速度基本上是最快的，但设计思维简洁而精巧。
一般分为三步。

1. 在数组中选定一个轴点pivot，一般选法包括，选最左边的点，最右边的点，中间点，和随机点。
2. 将数组中所以小于等于轴点pivot的数，放到pivot左边，大于等于pivot的数放到pivot右边。
3. 递归处理pivot左右两边的数组。

尽管思路简洁，但在算法的代码实现过程，各种边界条件还是很容易出错。在此，给出算法导论一书中，快速排序的两种实现。

## code 1
```cpp
#include <iostream>
using namespace std;

const int N = 100000;
int a[N] = {0};

void quick_sort(int a[], int l, int r)
{
    if (l >= r) return;
    
    int i = l - 1;
    int j = r + 1;
    int pivot = a[l + r >> 1];
    
    while (i < j) {
        do { ++i; } while (a[i] < pivot);
        do { --j; } while (a[j] > pivot);
        if (i < j) swap(a[i], a[j]);
    }
    
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    
    quick_sort(a, 0, n - 1);
    
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    return 0;
}
```

## code 2
```cpp
#include <iostream>
using namespace std;

const int N = 100000;
int a[N] = {0};

int partition(int a[], int l, int r)
{
    int k = l - 1;
    for (int i = l; i < r; ++i) {
        if (a[i] < a[r]) swap(a[++k], a[i]);
    }
    
    swap(a[++k], a[r]);
    return k;
}

void quick_sort(int a[], int l, int r)
{
    if (l >= r) return;
    
    int pivot_index = partition(a, l, r);
    quick_sort(a, l, pivot_index - 1);
    quick_sort(a, pivot_index + 1, r);
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    
    quick_sort(a, 0, n - 1);
    
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    return 0;
}
```
这两种实现方式，最主要的不同点在于partition函数，代码2明确表明，partition函数的返回值，正是轴点pivot所在的位置，但代码1并不做这种保证。可在OJ的某些极端数据，代码2会被卡TLE：）

---

## 链表的快速排序

说完了数组的快排实现，我们来看一下链表的快排。其实链表的快排实现，从想法上更加简单直接。

1. 建立3个辅助链表left，mid和right。
2. 将原始链表的头结点的值定为pivot，遍历原始链表，值等于pivot的节点插入mid末尾，小于pivot的插入left末尾，大于pivot的插入right末尾。
3. 递归处理left和right。
4. 将left，mid，right依次连接即可。

## code sort list
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getTail(ListNode* head)
    {
        while (head ->next != nullptr) head = head->next;
        return head;
    }
    
    ListNode* quickSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        auto left = new ListNode(-1);
        auto lTail = left;
        
        auto mid = new ListNode(-1);
        auto midTail = mid;
        
        auto right = new ListNode(-1);
        auto rTail = right;
        
        int val = head->val;
        for (auto cur = head; cur != nullptr; cur = cur->next) {
            if (cur->val < val) {
                lTail->next = cur;
                lTail = lTail->next;
            } else if (cur->val == val) {
                midTail->next = cur;
                midTail = midTail->next;
            } else {
                rTail->next = cur;
                rTail = rTail->next;
            }
        }
        
        lTail->next = nullptr;
        midTail->next = nullptr;
        rTail->next = nullptr;
        
        left->next = quickSortList(left->next);
        right->next = quickSortList(right->next);
        
        getTail(left)->next = mid->next;
        //getTail(left)->next = right->next;
        midTail->next = right->next;
        
        auto p = left->next;
        
        delete right;
        delete mid;
        delete left;
        
        return p;
    }
};
```
---

## 215. Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

> Input: [3,2,1,5,6,4] and k = 2  
Output: 5


Example 2:

> Input: [3,2,3,1,2,4,5,5,6] and k = 4  
Output: 4


Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

## 题解思路

本题要求从一个未排序的数组中，求一个第k大的数，最基本的想法自然时从大到小排个序，然后直接返回第k大的数即可，这样，算法的复杂度自然时O(nlogn)。

但如果我们利用快排模板2的partition的思想，并不把数组完全排序，而是每次检查partition的返回结果，如果正好是k，则pivot正是所求。否则递归处理左右两边，就可以将算法时间复杂度降为O(n)。

注意因为要求找第k大的数，所以partition稍作修改。代码如下

## code
```cpp
class Solution {
public:
    int partition(vector<int>& nums, int l, int r)
    {
        int k = l - 1;
        for (int i = l; i < r; ++i) {
            if (nums[i] > nums[r]) swap(nums[++k], nums[i]);
        }
        
        swap(nums[++k], nums[r]);
        
        return k;
    }
    
    int solve(vector<int>& nums, int l, int r, int k)
    {
        int pos = partition(nums, l, r);
        
        if (pos == k - 1) {
            return nums[pos];
        } else if (pos < k - 1) {
            return solve(nums, pos + 1, r, k);
        } else {
            return solve(nums, l, pos - 1, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return solve(nums, 0, n - 1, k);
    }
};
```

我们同样可以用快排模板1的形式去写本题，代码如下

## code
```cpp
class Solution {
public:
    int quick_select(vector<int>& a, int l, int r, int k)
    {
        if (l >= r) return a[l];
        
        int i = l - 1;
        int j = r + 1;
        int pivot = a[l + r >> 1];
        
        while (i < j) {
            do { ++i; } while (a[i] > pivot);
            do { --j; } while (a[j] < pivot);
            if (i < j) swap(a[i], a[j]);
        }
        
        if (j - l + 1 >= k) {
            return quick_select(a, l, j, k);
        } else {
            return quick_select(a, j + 1, r, k - (j - l + 1));
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quick_select(nums, 0, n - 1, k);
    }
};
```

通过OJ通过时间看，这种写法还是比上面的要快：）
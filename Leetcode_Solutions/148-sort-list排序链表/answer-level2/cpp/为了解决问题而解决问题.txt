算是投机取巧的一种办法吧。

这个方法总共分为三步：
    1. 遍历链表将值获取到数组中 O(n) S(n)
    2. 排序数组 O(nlogn) (快排)
    3. 将数组元素按顺序写回链表 O(n)

这样算下来时间复杂度为O(nlogn)，S(n)。

排序算法如果选择的好，就可以缩短时间，我这里使用了快排，使用归并或者其他的也是一样的，时间控制在O(nlogn)之内就可以。

这个方法的缺点就在于：
    1. 空间复杂度过高，为S(n)。
    2. 如果要求链表节点地址与值绑定，那么肯定不满足要求。（所以说这是一个投机取巧的方法）

```c++ []
class Solution {
public:
    void quickSort(vector<int> &arr, int front, int tail) {
        if (front < tail) {
            int l = front, r = tail, x = arr[front];
            while (l < r) {
                while (l < r && arr[r] > x) r--;
                if (l < r) arr[l++] = arr[r];
                while (l < r && arr[l] < x) l++;
                if (l < r) arr[r--] = arr[l];
            }
            arr[l] = x;
            quickSort(arr, front, l-1);
            quickSort(arr, l+1, tail);
        }
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return head;
        vector<int> arr;
        ListNode *p = head;
        while (p) {
            arr.push_back(p->val);
            p = p->next;
        }
        // sort(arr.begin(), arr.end()); // STL sort()
        quickSort(arr, 0, arr.size()-1);
        p = head;
        for (int i = 0; i < arr.size(); i++) {
            p->val = arr[i];
            p = p->next;
        }
        return head;
    }
};
```

速度不用说，连续三次提交都没有太大的时间变化。

> 执行用时 : 52 ms, 在所有 C++ 提交中击败了99.62%的用户
> 内存消耗 : 12.1 MB, 在所有 C++ 提交中击败了68.45%的用户

连续三次提交结果分别是 52ms，48ms，52ms。
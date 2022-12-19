### 解题思路
- 使用最大堆得到尚未排序的最大元素
- 每次从堆中弹中最大元素
- 在数组中找到当前最大元素的下标，进行局部翻转，将其翻转到第一位。再一次全局翻转，每次有一个元素被置于最终位置

给出一个例子：
给出待排序序列 `[3,2,4,1]`，将其全部入优先队列(大顶堆)，从堆顶弹出最大元素**4**，找到其下标，为**2**。那么就从下标**0**开始到**2**进行元素翻转（逆置）。翻转后的结果为[4,2,3,1]，此时最大元素被置于首位，再一次全局翻转为[1,3,2,4]，则将当前最大元素**4**置于最终位置！对所有待排元素进行上述操作，直到优先队列为空。

### 代码

```cpp
class Solution {
public:
    vector<int> result;
    priority_queue<int> pq;

    // 将元素进行翻转(逆置)
    void t_sort(vector<int>&A ,int left, int right){
        int mid = (left+right) >> 1;
        int i = 0;
        while(left+i<=mid){
            int temp = A[left+i];
            A[left+i] = A[right-i];
            A[right-i] = temp;
            i++;
        }
    }

    vector<int> pancakeSort(vector<int>& A) {
        for(auto n:A) pq.push(n);
        int i = A.size()-1;
        while(!pq.empty()){
            int top = pq.top(); pq.pop();
            int index = find(A.begin(), A.end(), top) - A.begin();
            result.emplace_back(index+1);
            t_sort(A, 0, index);
            t_sort(A, 0, i);
            result.emplace_back(i+1);
            i --;
        }
        return result;
    }
};
```
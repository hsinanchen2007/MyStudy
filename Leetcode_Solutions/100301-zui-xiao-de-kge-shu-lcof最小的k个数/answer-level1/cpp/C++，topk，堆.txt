### 解题思路
方法一：sort排序，再取出前k个；
### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) return {};
        priority_queue<int> que;
        for (int i = 0; i < k; i++) {
            que.push(arr[i]);
        }
        for (int i = k; i < arr.size(); i++) {
            if (arr[i] < que.top()) {
                que.pop();
                que.push(arr[i]);
            }
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(que.top());
            que.pop();
        }
        return res;

    }
};
```
方法二，利用堆，先将arr的k个数存入堆，然后将第k+1个及之后的数注意入堆比较，若比堆中的top(最大元素)小（C++大根堆，弹出最大值，维护的是小的top k），弹出最大值，将这个数入堆，最后就剩下了k个最小的数。
### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) return {};
        priority_queue<int> que;
        for (int i = 0; i < k; i++) {
            que.push(arr[i]);
        }
        for (int i = k; i < arr.size(); i++) {
            if (arr[i] < que.top()) {
                que.pop();
                que.push(arr[i]);
            }
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(que.top());
            que.pop();
        }
        return res;

    }
};
```
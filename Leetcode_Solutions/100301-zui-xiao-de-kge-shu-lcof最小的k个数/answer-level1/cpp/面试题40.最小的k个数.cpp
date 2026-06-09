### 解题思路
- 核心思路：设置一个大小为k的*优先队列*，**预存好数组的前k个数**，其中队首为k个数的最大值。从数组第k个数继续，**比较之后每个数与队首的大小**，如果小于队首，就将队首弹出，将该数压入队列。结束后返回优先队列中的k个数。
- 执行用时：108 ms, 在所有 C++ 提交中击败了9.81%的用户
- 内存消耗：20.1 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k==0)return {};
        priority_queue<int>pq;
        vector<int>result;
        for(int i=0;i<k;i++)pq.push(arr[i]);
        for(int i=k;i<arr.size();i++){
            if(pq.top()>arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for(int i=0;i<k;i++){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};
```
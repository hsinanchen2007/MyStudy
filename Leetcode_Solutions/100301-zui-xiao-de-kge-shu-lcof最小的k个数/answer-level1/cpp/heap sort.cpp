### 解题思路
heap sort

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> v(k);
        if(k==0) return v;
        priority_queue<int> q;
        for(int i=0;i<k;i++)
        {
            q.push(arr[i]);
        }
        for(int i=k;i<arr.size();i++)
        {
            if(q.top()>arr[i])
            {
                q.pop();
                q.push(arr[i]);
            }
        }
        for(int i=0;i<k;i++)
        {
            v[i]=q.top();
            q.pop();
        }
        return v;
    }
};
```
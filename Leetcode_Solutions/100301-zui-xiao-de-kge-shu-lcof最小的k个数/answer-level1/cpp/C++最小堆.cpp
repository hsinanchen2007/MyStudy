### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    struct cmp
    {
        bool operator()(int a,int b)
        {
            return a > b;
        }
    };

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,cmp> pq;
        for(int i:arr)
        {
            pq.push(i);
        }

        vector<int> res;
        for(int i=0; i<k; ++i)
        {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
```
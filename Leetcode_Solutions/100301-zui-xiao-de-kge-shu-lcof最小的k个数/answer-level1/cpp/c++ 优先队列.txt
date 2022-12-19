
### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int> > qu;
        vector<int> res;
        for(auto num : arr)
        {
            qu.push(num);
        }
        while(k>0)
        {
            res.push_back(qu.top());
            qu.pop();
            k--;
        }
        return res;
    }
};
```
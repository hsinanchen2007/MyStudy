### 解题思路
使用priority_queue<int, vector<int>, less<int> >

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if(k == 0){
            return res;
        }else{
            priority_queue<int, vector<int>, less<int> > q;
            for(int i = 0; i < k; i++){
                q.push(arr[i]);
            }
            int sz = arr.size();
            for(int i = k; i < sz; i++){
                q.push(arr[i]);
                q.pop();
            }
            while(!q.empty()){
                res.push_back(q.top());
                q.pop();
            }
            return res;
        }
    }
};
```
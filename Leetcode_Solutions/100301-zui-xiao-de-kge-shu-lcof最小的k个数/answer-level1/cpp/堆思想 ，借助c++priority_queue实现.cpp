### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k < 1)
            return vector<int> ();
        vector<int> res;
        priority_queue<int> q;
        //1.先将前k个元素入队
        for(int i = 0; i < k; ++i){
            q.push(arr[i]);
        }
        //2.判断后续的元素，如果小于队头元素，则将队头元素更新为该元素
        for(; k < arr.size(); ++k){
            if(arr[k] < q.top()){
                q.pop();
                q.push(arr[k]);
            }
        }
        //3.将队列中的元素存入vector
        while(!q.empty()){
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
```
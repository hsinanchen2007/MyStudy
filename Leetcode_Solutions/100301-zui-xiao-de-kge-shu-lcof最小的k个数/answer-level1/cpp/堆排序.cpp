### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
       priority_queue<int> q;
       vector<int> ans(k,0);
       if(k==0) return ans;
       for(int i=0;i<arr.size();++i){
           if(q.size()<k){
                q.push(arr[i]);
           }
           else if(arr[i]<q.top()){
                q.pop();
                q.push(arr[i]);
                

           }
       }
       for(int i=0;i<k;++i){
           ans[i]=q.top();
           q.pop();
       }
       return ans;
    }
};
```
### 解题思路
看所有数字，谁的总数==3就返回谁
![image.png](https://pic.leetcode-cn.com/21a752a3af23dc28034e99c55c274945713220401067ed008260bb984cd94e14-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        map<int,int> cnt;
        vector<int> res;
        for(int a:arr1) cnt[a]++;
        for(int a:arr2) cnt[a]++;
        for(int a:arr3) cnt[a]++;
        for(pair<int,int> m:cnt){
            if(m.second==3) res.push_back(m.first); 
        }
        return res;
    }
};
```
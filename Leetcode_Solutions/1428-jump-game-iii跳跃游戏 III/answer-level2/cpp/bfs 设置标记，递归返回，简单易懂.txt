### 解题思路
![批注 2020-01-14 102104.png](https://pic.leetcode-cn.com/559853199c54b092b592d557ba45bda2dfc63028ca3d45cfe96161bde140a5b7-%E6%89%B9%E6%B3%A8%202020-01-14%20102104.png)
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int>flags(arr.size(), 0);
        bool ans = bfs(arr, flags, start);
        return ans;
    }

    bool bfs(vector<int>& arr, vector<int>& flags, int start){
        if(start>=arr.size()||start<0) return false;
        if(flags[start]==1) return false;
        else if(arr[start]==0) return true;
        else {
            flags[start] = 1;
            return bfs(arr, flags, start-arr[start])||bfs(arr, flags, start+arr[start]);
        }
    }
};
```
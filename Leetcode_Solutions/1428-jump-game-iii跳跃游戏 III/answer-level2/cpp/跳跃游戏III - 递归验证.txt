### 解题思路
1. 如果当前位置的值就是**0**或者某次跳跃到达**0**的位置，直接返回`true`
2. 尝试往左跳`i-arr[i]`或者尝试往右跳`i+arr[i]`，这里要注意往左或者往右跳，得是合法的下标。
3. 如果往左或者往右跳到某个已经访问过的下标，说明该种跳法行不通，不然首次跳到该下标的时候就一定能跳到目的地
4. 因此要这里定义一个`visit`数组，用于记录该下标是否访问过

### 代码

```cpp
class Solution {
public:
    int n;
    bool helper(vector<int>& arr, vector<bool>& visit, int start){
        // 递归出口
        if(arr[start] == 0) return true;
        if(visit[start]) return false;
        // 此处是回溯
        visit[start] = true;
        if(start + arr[start] < n && helper(arr, visit, start+arr[start])) return true;
        if(start - arr[start] >= 0 && helper(arr, visit, start-arr[start])) return true;
        visit[start] = false;
        return false;
    }

    bool canReach(vector<int>& arr, int start) {    
        n = arr.size();
        if(arr[start] == 0) return true;
        vector<bool> visit(n, false);
        //  如果往左或者往右跳有一个方案可以成功，则返回true，否则返回false
        return ((start + arr[start] < n) && helper(arr, visit, start + arr[start])) || ((start - arr[start] >= 0) && helper(arr, visit, start - arr[start]));
    }
};
```
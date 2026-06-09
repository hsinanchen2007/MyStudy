递归的思路比较简单，但是最大的问题就是会出现在一个范围内重复搜索，炸栈的情况，因此对于已经搜索过的，如果出现 -1 的 flag 标志，则可以说明重复搜索，返回 false 即可，代码如下
```
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start >= arr.size() || start < 0 || arr[start] == -1)
            return false;
        if(arr[start] == 0)
            return true;
        int t = arr[start];
        arr[start] = -1;
        return canReach(arr, start + t) || canReach(arr, start - t);    
    }
};
```
另外，如果不用 flag 标志，也可以用一个数组 visit 记录是否已经访问过。

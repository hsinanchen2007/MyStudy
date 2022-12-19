### 解题思路
为什么vector做全局变量不能初始化？？？
fatal error: expected parameter declarator 报这样的错，看不懂啊

### 代码

```cpp
class Solution {
public:
vector<int> mark;      //为什么这里不能写成vector<int> mark(50001,0)？？？  
bool canReach(vector<int>& arr, int start){
    mark.resize(arr.size(),0);
    return func(arr,start);
}
    bool func(vector<int>& arr, int start) {
        if(start<0||start>=arr.size()||mark[start]==-1)return 0;
        if(mark[start])return arr[start];
        if(!arr[start])return 1;
        mark[start]=-1;
        arr[start]=func(arr,start-arr[start])||func(arr,start+arr[start]);
        mark[start]=1;
        return arr[start];
    }
};
```
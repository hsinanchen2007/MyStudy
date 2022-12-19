### 解题思路
queue记录当前所能到达的所有点
arrived[]记录该点是否到过
若某点已访问过，则该点+-arr[]必然已在队列中，无需再次添加计算，若扫描到queue队尾任未找到arr=0的点，则失败

### 代码

```cpp
class Solution {
public:e
    bool canReach(vector<int>& arr, int start) {
        bool *arrived=new bool[arr.size()]{false};
        vector<int> queue;
        queue.push_back(start);
        arrived[start]=true;
        int i=0;
        while (i<queue.size()){
            if (arr[queue[i]]==0) return true;
            if (queue[i]+arr[queue[i]]<arr.size() and arrived[queue[i]+arr[queue[i]]]==false){
                queue.push_back(queue[i]+arr[queue[i]]);
                arrived[queue[i]+arr[queue[i]]]=true;
            }
            if (queue[i]-arr[queue[i]]>=0 and arrived[queue[i]-arr[queue[i]]]==false){
                queue.push_back(queue[i]-arr[queue[i]]);
                arrived[queue[i]-arr[queue[i]]]=true;
            }
            i++;
        }
        return false;
    }
};
```
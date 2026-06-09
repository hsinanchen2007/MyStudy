### 解题思路
每次取出队列中最小的数，加入该数右边和下边的数，k次就能得出答案，这里的数是用结构体实现，因为要记录位置。还要注意不要重复

### 代码

```cpp
class Solution {
public:
struct node{
    int val,x,y;
    friend bool operator <(node p,node q) {
        return p.val>q.val; // >号代表从小到大排序
    }
};
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<node> que;
        vector<vector<bool>> used(matrix.size(),vector<bool>(matrix[0].size(),0));
        int i=0;
        que.push({matrix[0][0],0,0});
        while(++i){
            node tp=que.top();
            if(i==k)return tp.val;
            que.pop();
            if(tp.x+1<matrix.size()&&used[tp.x+1][tp.y]==0){
            que.push({matrix[tp.x+1][tp.y],tp.x+1,tp.y});
            used[tp.x+1][tp.y]=1;
            }
            if(tp.y+1<matrix[0].size()&&used[tp.x][tp.y+1]==0){
            que.push({matrix[tp.x][tp.y+1],tp.x,tp.y+1});
            used[tp.x][tp.y+1]=1;
            }
        }
        return 0;
    }
};
```
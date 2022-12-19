### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int DFS(int num,int target,int k,int step)//num代表当前已经完成A的数目，k代表当前复制的数目
    {
        if(num == target) return step;
        if(num > target) return INT_MAX;
        int res;
        if(k == 0) return DFS(num,target,num,step+1);
        else if(k < num) //下一步可以粘贴也可以复制
        {
            res = min(DFS(num+k,target,k,step+1),DFS(num,target,num,step+1));
        }
        else//如果k与num相等，说明只能粘贴了
        {
            res = DFS(num+k,target,k,step+1);
        }
        return res;
    }
    int minSteps(int n) {
        return DFS(1,n,0,0);
    }
};
```
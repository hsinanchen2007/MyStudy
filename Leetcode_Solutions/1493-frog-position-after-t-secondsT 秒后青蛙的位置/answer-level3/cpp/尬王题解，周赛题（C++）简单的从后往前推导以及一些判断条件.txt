### 解题思路
此处撰写解题思路
拿到数据先排序，如果目标结点还有子结点则需要注意，判断跳跃到目标结点的步数（time）是否小于给定的，如果是再结合前面判断的目标结点是否还有子结点的信息（flag）若flag==1且time<t那肯定不满足，如果flag==0且time<t，说明目标结点没有地方可以跳，只能一直留在原地，所以返回的结果sum是有效的。
![image.png](https://pic.leetcode-cn.com/601801f7b7018343686d1e87400d6d0f0ef0f79789f51205112b1f3b3ea9bb6c-image.png)

### 代码

```cpp
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        double sum = 1;int count;int temp;int time = 0;int flag = 0;
        for(int i = 0;i<edges.size();i++)
        {
            if(edges[i][0]>edges[i][1])
            {
                int m = edges[i][0];
                edges[i][0] = edges[i][1];
                edges[i][1] = m;
            }
            if(edges[i][0]==target)
            {
                flag = 1;
            }
        }
        while(target!=1)
        {
            temp = 0;count = 0;time++;if(time>t){break;}
            for(int i = 0;i<edges.size();i++)
            {
                if(edges[i][1]==target)
                {
                    temp = edges[i][0];
                    break;
                }
            }
            for(int i = 0;i<edges.size();i++)
            {
                if(edges[i][0]==temp)
                {
                    count++;
                }
            }
            sum *= 1.0/count;
            target = temp;
        }
        if(time == t){return sum;}
        if(time<t&&flag ==0)
        {
            return sum;
        }
        if(time<t&&flag==1)
        {
            return 0.0;
        }
        return 0;
    }
};
```
### 解题思路
创建一个存放图的邻接矩阵的数据结构。
然后从第1个花园开始循环到第N个花园。
对于第i个花园，从第一种花开始找，一直找到第四种花，在邻接矩阵中判断是否存在这种花。如果不存在则将此数字赋值给这个花园。
循环结束时返回花园。
![image.png](https://pic.leetcode-cn.com/f3085d11fe8bf7eaa64a9f42d987b127215c88c8db1c00f66734ada793528a26-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> answer(N,0);
        vector<vector<int>> map(N);
        for(int i=0;i<paths.size();i++)
        {
            map[paths[i][0]-1].push_back(paths[i][1]);
            map[paths[i][1]-1].push_back(paths[i][0]);
        }
        for(int i=0;i<N;i++)
        {
            vector<int> temp;
            for(int z=0;z<map[i].size();z++)
            {
                temp.push_back(answer[map[i][z]-1]);
            }
            for(int j=1;j<5;j++)
            {
                if(temp.end()==find(temp.begin(),temp.end(),j))
                {
                    answer[i]=j;
                    break;
                }
            }
            temp.clear();
        }
        return answer;
    }
};
```
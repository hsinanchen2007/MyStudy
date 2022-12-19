### 解题思路
先记录每个数字出现的次数及最小值；
然后从最小值开始，保证每个位置上只留至多一个数字，剩下的数字个数打包后移；
遇见当前位置为0时，就从打包的数字个数中，吐出来一个，剩下的继续后移。

### 代码

```cpp
class Solution {
private:
int vis[80000]={0};
public:
    int minIncrementForUnique(vector<int>& A) {
        int move = 0;
        int index = 80000;
        for(int i = 0; i < (int)A.size(); ++i)
        {
            index = min(index, A[i]);
            ++vis[A[i]];
        }

        for(int j = index; j < 79999; ++j)
        {
            if(vis[j] > 1)
            {
                int t = vis[j] - 1;
                move += t;
                vis[j+1] += t; 
            }    
        }
        return move;
    }
};
```
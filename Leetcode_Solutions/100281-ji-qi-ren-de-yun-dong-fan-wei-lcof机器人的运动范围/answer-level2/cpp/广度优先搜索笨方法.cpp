### 解题思路
由于之前每日一题出现的海陆距离问题，对地图遍历就想到了广度优先搜索。为了防止遍历格子计算数位之和麻烦就对格子先进行了赋值数位计算的结果，遍历过后就赋值为1。而且只用对每个格子进行横纵坐标的增加遍历即可。

### 代码

```cpp
class Solution {
public:
        struct container{
            int x;
            int y;
        };
    int movingCount(int m, int n, int k) {
        if(k == 0){
            return 1;
        }
        vector<vector<int>> map(m,vector<int>(n,0));
        int count;
        int x,y;
        int re1,re2;
        count = 1;
        re1=re2=0;

//对地图每个格子计算数位之和
        for(int i=0;i<m;i++){
            re1 = 0;
            x = i;
            while(x>0){
                re1 = x%10 + re1;
                x = (int)(x/10);
            }
            for(int j=0;j<n;j++){
                re2 = 0;
                y = j;
                while(y>0){
                    re2 = y%10 + re2;
                    y = (int)(y/10);
                }
                map[i][j] = re1 + re2;
            }
        }



        queue<container> list;
        list.push({0,0});
        int addx[2] = {0,1};
        int addy[2] = {1,0};

//广度优先搜索格子，小于k的数位格子count增加
        while(list.size()>0){
            x = list.front().x;
            y = list.front().y;
            for(int i=0;i<2;i++){
                if((x+addx[i]) < m && (y+addy[i]) < n){
                    if(map[x+addx[i]][y+addy[i]] <= k && map[x+addx[i]][y+addy[i]] != -1){
                        map[x+addx[i]][y+addy[i]] = -1;
                        list.push({x+addx[i],y+addy[i]});
                        count++;
                    }
                }
            }
            list.pop();
        }

        return count;
    }
};
```
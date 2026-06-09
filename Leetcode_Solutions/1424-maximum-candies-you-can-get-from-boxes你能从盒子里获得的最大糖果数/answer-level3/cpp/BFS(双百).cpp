### 解题思路
搜索题简单BFS即可
### 代码

```cpp
class Solution {
public:
    
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        bool keysign[1010]={false};//拥有的钥匙
        bool box[1010]={false};//拥有的盒子
        bool open[1010]={false};//打开过的盒子
        queue<int>q;//可探索的队列.
        int sum=0;
        for(auto x:initialBoxes)
        {
            box[x] = true;//记录拥有的盒子
            if(status[x]==1)q.push(x);//如果此盒子为打开的加入可探索队列.
        }
        while(q.size())
        {
            auto t = q.front();
            q.pop();
            if(open[t]==false)
            {
            open[t]=true;//标记已打开
            sum+=candies[t];//获得此盒子的糖果.
          //  candies[t]=0;//盒子内糖果清零.

           //打开此盒子t可以获得的盒子
            for(int i=0;i<containedBoxes[t].size();i++)
               { 
                   int z = containedBoxes[t][i];
                   box[z]=true;//标记此盒子已拥有
                //如果拥有此盒子的钥匙或者此盒子状态为打开(未被打开过)的入队.
                if(keysign[z]==true||status[z]==1)
                {
                    if(open[z]==false)q.push(z);
                }
               }  
            //打开此盒子t可以获得的钥匙
            for(int i=0;i<keys[t].size();i++)
            {
                int z =keys[t][i];
                keysign[z]=true;
                if(box[z]==true&&!open[z])q.push(z);
            }
            }

        }
        return sum;
    }
};
```
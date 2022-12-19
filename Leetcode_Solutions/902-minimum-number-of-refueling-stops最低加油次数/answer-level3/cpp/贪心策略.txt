### 解题思路

    贪心+最大堆
    
    1、既然要求加油次数最少，那么加油就加油最多的
    2、从左到右依次遍历，把油放入最大堆。油不够到达下一个点就从最大堆里取油，表示从那个油最多的加油站加了油
    3、油要是够到下一个站那就不加油，把下一个站的油放入最大堆

### 代码

```cpp
bool cmp(vector<int>& a,vector<int>& b)
{
    return a[0]<b[0];
}


class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> q;               //设置一个最大堆来存放油量，加油的时候先加最多的
        int result=0;                        //表示加过几次油

        vector<int> start(2,0);                //这个是起点
        vector<int> dest;                      //这个是终点
        dest.push_back(target);
        dest.push_back(0);
        stations.push_back(start);                               //把起点加入
        stations.push_back(dest);                                //把终点加入

        sort(stations.begin(),stations.end(),cmp);          //按照当前点距离起点从左到右排好

  
        int current=0;           //表示现在走到哪个点了，初始是起点

        for(int i=1;i<stations.size();i++)    //试探下一个点
        {
            int dis=stations[i][0]-current;                 //看看离下一个点还有多远
            while(!q.empty() && startFuel<dis)             //离下一个点油不够但是以前走过的点还有油没加，加油
            {
                startFuel+=q.top();
                q.pop();
                result++;
            }
            if(q.empty() && startFuel<dis)                  //离下一个点油不够没油，不可达
            {
                return -1;
            }
            startFuel=startFuel-dis;                        //油够，那么走到stations[i]点，油量减去路程
            current=stations[i][0];                         //当前位置更新
            if(current==target)                             //到达终点break
            {
                break;
            }
            q.push(stations[i][1]);                         //把这个点的油量放入最大堆，等下次不够了加

        }
       
        return result;
    }
};
```
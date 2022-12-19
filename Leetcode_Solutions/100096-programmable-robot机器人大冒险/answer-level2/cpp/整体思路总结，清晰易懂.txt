### 解题思路
1.存储循环一次需要经过的路径坐标，到达init[a，b]
2.判断在经过min（x/a，y/b）次循环后，能否到达终点，这是**第一个**判断条件
3.对<=x,<=y的obstacles[ob0,ob1]（大于的就不用考虑，节约时间，所以可以先排一次序），判断往回min（ob0/a，ob1/b）次循环后，这个点在不在路径上，这是**第二个**判断条件
# 实现方法
1.因为两个条件要判断是否经过路径，用set来储存循环一次经过的坐标，注意**[0,0]**点要存进去
2.第一个判断比较简单
3.判断回溯后的obstacles在不在集合里，方法是再开一个set，把倒退后范围在{ob0<=a ||ob1<=b}的点放到一个集合，记录这两个集合的大小，然后**合并**。如果合并之后的大小等于合并前的和，就说明不会遇到这些障碍，若小于，则他们有交集，机器人会碰到障碍物。

### 代码

```cpp
class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        int l=command.length();
        set<vector<int>> path;
        int a=0,b=0;
        vector<int> init;
        init.push_back(0);
        init.push_back(0);
        path.insert(init);
        vector<int> target;
        target.push_back(x);
        target.push_back(y);
        for(char c:command){
        if (c=='U') {
                init[1]++;
        }
        else init[0]++;
        path.insert(init);
        }
        int d=min(x/init[0],y/init[1]);
        vector<int> f={x-(d*init[0]),y-(d*init[1])};
        if(path.find(f)==path.end()) return false;//无法到达指定终点
        int tmp=path.size();
        set<vector<int>> obs;
        int j=obstacles.size();
        sort(obstacles.begin(),obstacles.end());
        for(int res=0;res<j;res++)
        {
            if(obstacles[res][0]<=x && obstacles[res][1]<=y)
            {
               int a=min(obstacles[res][0]/init[0],obstacles[res][1]/init[1]);
               obstacles[res][0]-=(a*init[0]);
               obstacles[res][1]-=(a*init[1]);//回退a次循环
                obs.insert(obstacles[res]);
                cout<<"obs "<<obstacles[res][0]<<obstacles[res][1];
            }
            else break;
        }
        int t=obs.size();
        path.insert(obs.begin(),obs.end());
        if(path.size()==tmp+t)
        return true;
        return false;
    }
};
```
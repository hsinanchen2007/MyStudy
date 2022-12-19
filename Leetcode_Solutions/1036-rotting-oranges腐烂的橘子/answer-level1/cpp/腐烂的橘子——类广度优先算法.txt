### 解题思路
思路为类广度优先算法。每层都是即将烂掉的橘子。如第0层是一个腐烂源，第1层是初始输入的腐烂橘子，第二层是即将被第一层感染腐烂的橘子，以此类推。思路如下：
- 1、遍历输入，获取i=1层
- 2、遍历第i层，获得第i+1层，并且将腐烂的橘子从0变1
- 3、重复步骤二，直到获取的下一层size为0
- 4、检测初始数组中是否还有1,
- 5、输出
详细解释见注释

### 代码

```cpp
class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int t=0;//花费的时间
        int size = (grid[0]).size();//每行的长度
        auto iter_x_begin=grid.begin();//存储行的开始
        auto iter_x_prev_end=prev(grid.end());//存储行的结束（是end的前一个）
        vector<pair<vector<vector<int>>::iterator,int>> fulan1,fulan2;//用于存储第i层和i+1层

        //获取第i=1层
        for(auto iter_i = grid.begin();iter_i != grid.end();iter_i++)
            for(int j=0;j<size;j++)
            {
                if((*iter_i)[j] == 2)
                    fulan1.push_back(make_pair(iter_i,j));
            }
        
        //广度遍历
        while(1){
            //i层遍历
            for(auto iter=fulan1.begin();iter!=fulan1.end();iter++){
                //下面是四个判断，区分四个边界情况
                if((*iter).first != iter_x_begin)
                    if((*(((*iter).first)-1))[(*iter).second] == 1){
                        (*(((*iter).first)-1))[(*iter).second]=2;
                        fulan2.push_back(make_pair((((*iter).first)-1),(*iter).second));
                    }
                if((*iter).first != iter_x_prev_end)
                    if((*(((*iter).first)+1))[(*iter).second] == 1){
                        (*(((*iter).first)+1))[(*iter).second]=2;
                        fulan2.push_back(make_pair((((*iter).first)+1),(*iter).second));
                    }
                if((*iter).second != 0)
                    if((*(((*iter).first)))[(*iter).second-1] == 1){
                        (*(((*iter).first)))[(*iter).second-1]=2;
                        fulan2.push_back(make_pair((((*iter).first)),(*iter).second-1));
                    }
                if((*iter).second != size-1)
                    if((*(((*iter).first)))[(*iter).second+1] == 1){
                        (*(((*iter).first)))[(*iter).second+1]=2;
                        fulan2.push_back(make_pair((((*iter).first)),(*iter).second+1));
                    }
            }
            fulan1.clear();//清空这一层
            //如果没有可感染的则跳出循环，否则时间+1
            if(fulan2.size()==0){
                break;
            }
            else
                t++;

            //同样的逻辑
            for(auto iter=fulan2.begin();iter!=fulan2.end();iter++){
                if((*iter).first != iter_x_begin)
                    if((*(((*iter).first)-1))[(*iter).second] == 1){
                        (*(((*iter).first)-1))[(*iter).second]=2;
                        fulan1.push_back(make_pair((((*iter).first)-1),(*iter).second));
                    }
                if((*iter).first != iter_x_prev_end)
                    if((*(((*iter).first)+1))[(*iter).second] == 1){
                        (*(((*iter).first)+1))[(*iter).second]=2;
                        fulan1.push_back(make_pair((((*iter).first)+1),(*iter).second));
                    }
                if((*iter).second != 0)
                    if((*(((*iter).first)))[(*iter).second-1] == 1){
                        (*(((*iter).first)))[(*iter).second-1]=2;
                        fulan1.push_back(make_pair((((*iter).first)),(*iter).second-1));
                    }
                if((*iter).second != size-1)
                    if((*(((*iter).first)))[(*iter).second+1] == 1){
                        (*(((*iter).first)))[(*iter).second+1]=2;
                        fulan1.push_back(make_pair((((*iter).first)),(*iter).second+1));
                    }
            }
            fulan2.clear();
            if(fulan1.size()==0){
                break;
        }
        else
            t++;
        }
        //判断是否有无法感染的橘子
        for(auto iter_i = grid.begin();iter_i != grid.end();iter_i++)
            for(int j=0;j<size;j++)
            {
                if((*iter_i)[j] == 1){
                    t=-1;
                    break;
                }
            }

        return t;
    }
};
```
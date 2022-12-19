很早之前做过带权并查集的题，没想到一下子又拿起来了，很开心。
总的来说，带权并查集和并查集的区别就是在并查集的树的边的意义不在只是“相连”，而又多了
一个记录值的意义，而这个值是什么是根据题目来定的。
在这个题中，这个边的值的意义：e2->e1的边值代表e1/e2的结果。而带权并查集和普通并查集的
区别在于union操作和find操作（也可能只有union操作）。
首先来看find操作，find操作不仅进行了常规的压缩路径寻找父节点（如果压缩路径不知道的话，应该去做一下普通的并查集熟练一下），而且还利用回溯法更新了边值，比如a->b->c,压缩完路径后，
变成了a->c,b->c,那么a的那条边对应的边值一定会改变，就是b到c的边值*a到b的边值(跟新的
规则依据题目来定，有的题是+)。
再来看union操作，也特殊在边值的更新上。，例如对于b/c=2,不仅要把c的父亲指向b的父亲，
还要设置c的父亲到b的父亲的边值，更新法则按以前我看的一篇回答的叫法称作“四边形法则”。
![c35872e9eebed40944bdbc8646a0aff.jpg](https://pic.leetcode-cn.com/2f3628bedcf85037a838d6abf37d714bcbbbd718749332b8ff4f085430698c27-c35872e9eebed40944bdbc8646a0aff.jpg)
如上图所示，我们要想更新x，4*x = 2*3,所有x=2*3/4,对应我代码里就是father[f2].second = father[e1].second * result / father[e2].second;
其他的就是常规的并查集的写法啦，祝大家学习顺利，学习开心！！
```
class Solution {
public:
    unordered_map<int,pair<int,double>>father;
    int Find(int x){
        if(x != father[x].first){
            int t = father[x].first;
            father[x].first = Find(father[x].first);
            father[x].second *= father[t].second;
            
            return father[x].first;
        }
        return x;
    }
    void Union(int e1,int e2,double result){
        int f1 = Find(e1);
        int f2 = Find(e2);
        if(f1 != f2){
            father[f2].first = f1;
            father[f2].second = father[e1].second * result / father[e2].second;
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string,int> now;
        int numString = 1;
        for(int i = 0 ; i < equations.size() ; i++){
            int e1,e2;
            if(now[equations[i][0]] == 0){
                now[equations[i][0]] = numString++;
                father[numString-1].first = numString-1;
                father[numString-1].second = 1;
            }
            if(now[equations[i][1]] == 0){
                now[equations[i][1]] = numString++;
                father[numString-1].first = numString-1;
                father[numString-1].second = 1;
            }
            e1 = now[equations[i][0]];
            e2 = now[equations[i][1]];
            Union(e1,e2,values[i]);
          
        }
       
        for(int i = 0 ; i < queries.size() ; i++){
            if(now[queries[i][0]] == 0 || now[queries[i][1]] == 0){
                ans.push_back(-1.0);
                continue;
            }
                
            int e1 = now[queries[i][0]];
            int e2 = now[queries[i][1]];
            int f1 = Find(e1);
            int f2 = Find(e2);
            if(f1 != f2){
                ans.push_back(-1.0);
            }
            else{
                double temp = father[e1].second;
                double temp2 = father[e2].second;
                ans.push_back(temp2/temp);
            }
        }
       
        return ans;

    }
};
```

写完深搜，一直卡在1000那个用例，单独跑又能过

看了别人写的，我发现他们哈希映射或二维数组，是这样的[前置index : [x1,x2,x3,x4]]

如[0,1] [2,1] [3,1] 写成[1 : [0,2,3]]

这样能保证先访问前置，而我写的就是[x : 前置列表[y1,y2,y3]]]

这样要向更深处递归，而且存在重复递归的情况

我以为这就是超时的原因。。。

结果发现并不是，还是会超时，改了好久哈希映射改二维数组等等，，，

最后发现是递归时参数需要用引用，，，这样用指针访问原数据，不像传值一样对值进行拷贝

我发现有的把哈希表和二维数组写成全局变量，也是类似的效果

最后两种哈希表的形式都能通过

```
class Solution {
public:
    //深搜
    bool dfs(vector<vector<int>> &hash, int n, vector<int> &used){
        //1表示访问过
        //-1表示需要前置
        if(used[n] == 1)    return true;
        if(used[n] == -1)   return false;
        used[n] = -1;
        for(auto m : hash[n]){
            if(dfs(hash, m, used) == false) return false;
        }
        used[n] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //初始化哈希表
        vector<vector<int>> hash(numCourses, vector<int>());
        for(auto p : prerequisites) hash[p[0]].push_back(p[1]);
        //这两种初始化都能过
        //for(auto p : prerequisites) hash[p[1]].push_back(p[0]);
        //设置访问过标记数组
        vector<int> used(numCourses,0);
        //只需要循环图里的节点即可
        for(int i = 0 ; i < numCourses ; i++){
            if(dfs(hash, i, used) == false)  return false;
        }
        return true;
    }
};
```


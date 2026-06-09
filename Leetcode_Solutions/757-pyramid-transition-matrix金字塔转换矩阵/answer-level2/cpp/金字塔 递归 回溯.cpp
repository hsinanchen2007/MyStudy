### 解题思路
- 对allowed[ ] 从小到大排序 ，使相近的在一起
- 设置一个 string 类型的变量 t , 记录 bottom 上一层的字符串
- 每次检查 bottom 是否可以用allowed[i]构成，若可以，记录使用的allowed[i][2]，将其加到 t 的最后
- bottom 检查完毕，符合条件 ，将 bottom 置为 t , t 置为 空字符串，继续递归
- 当 当前的 bottom 长度为 1 ，说明到金字塔的顶点了，存在一种方法，返回 true
- 回溯： 若不满足条件，删除 t 的最后一个字符，再在 allowed[ ] 中找符合的下一个三元组

### 代码

```cpp
class Solution {
public:
    bool dfs(string bottom, vector<string>& allowed,int u,string t){
        if(u == bottom.size() - 1 || bottom.size() == 1) return true;
        for(int i = 0;i < allowed.size();i ++){
            if(bottom.substr(u,2) == allowed[i].substr(0,2)){
                t += allowed[i].substr(2,1);
                if(dfs(bottom,allowed,u + 1,t)) 
                   return dfs(t,allowed,0,"");
                t.pop_back();
            }
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        sort(allowed.begin(),allowed.end());
        string t;
        return dfs(bottom,allowed,0,t);
    }
};
```
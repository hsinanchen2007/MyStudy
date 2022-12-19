### 解题思路

突发奇想尝试用NFA做

- 用unordered_map<int, multimap<char, int>> g保存NFA的状态转移，因为同一个输入可以对应不同的转换状态，因此用multimap，int保存各个状态id
- 对给定模式串p构造NFA的方法：
  - 初始化状态id=0，从左向右遍历P
    - 当前字符char不为'.'，且下一个字符不是'*'：直接构造当前id[char]=id+1，即状态id通过char转移为状态id+1
    - 当前字符char不为'.'，且下一个字符是'*'：构造id[char]=id和id['#']=id+1，表示既可以通过char扔保留在当前状态，又可以不通过char（用'#'表示空字符）直接进入下一个状态（在自动机课程里学过，这样的模块代表匹配任意多个字符char）
    - 对当前字符char为'.'的情况，处理逻辑和前面是类似的，只不过要对a-z都构造相应的状态转移
  - NFA的终止状态为最后一个状态id
- 利用NFA判断s的方法：
  - 用unordered_set<int> curStates记录当前状态，初始化为从0开始不通过任何字符就可以到达的所有状态（注意这里不能直接初始化为0）
  - 遍历s，在每一步中，对每个curStates里的状态都根据NFA做状态转移，记录在nextStates里，记得不要忘记那些不通过任何字符就可以直接转移到的状态，然后更新curStates
  - 遍历完s后，查看curStates可以到达的状态，如果里有终止状态则匹配，否则不匹配

### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_map<int, multimap<char, int>> g;//NFA
        //构造NFA
        int id = 0;
        int len_p = p.size();
        for(int i = 0; i < len_p; ){
            if(i == len_p - 1 || p[i+1] != '*'){
                if(p[i] != '.')
                    g[id].insert(make_pair(p[i], id+1));
                else
                    for(int j = 0; j < 26; j++) 
                        g[id].insert(make_pair('a'+j, id+1));
                id++;
                i++;
            }
            else{
                if(p[i] != '.')
                	g[id].insert(make_pair(p[i], id));
                else
                    for(int j = 0; j < 26; j++)
                        g[id].insert(make_pair('a'+j, id));
                g[id].insert(make_pair('#', id+1));
                id++;
                i += 2;
            }
        }
        int end = id;//终止状态
		//利用NFA判断s
        unordered_set<int> curStates;
        curStates.insert(0);
        int tmp = 0;
        auto tmp_it = g[tmp].find('#');
        while(tmp_it != g[tmp].end()){//从tmp开始能够不通过任何字符转移到的所有状态
            curStates.insert(tmp_it->second);
            tmp = tmp_it->second;
            tmp_it = g[tmp].find('#');
        }
        for(int i = 0; i < s.size() && !curStates.empty(); i++){//遍历s
            unordered_set<int> nextStates;
            for(auto it = curStates.begin(); it != curStates.end(); it++){//每一个可能的当前状态
                int cnt = g[*it].count(s[i]);//当前状态通过s[i]走一步后可以到达的状态数
                if(cnt > 0){
                    auto cur = g[*it].find(s[i]);
                    while(cnt--){//遍历所有可以一步到达的状态
                        int tmp = cur->second;
                        nextStates.insert(tmp);//加入nextStates
                        //把从tmp开始不通过任何字符能转移到的所有状态也加入nextStates
                        auto tmp_it = g[tmp].find('#');
                        while(tmp_it != g[tmp].end()){
                            tmp = tmp_it->second;
                            nextStates.insert(tmp);//通过'#'只能转移到一个状态
                            tmp_it = g[tmp].find('#');
                        }
                        cur++;
                    }
                }
            }
            curStates = nextStates;
        }
        //判断遍历完s后所有可以到达的状态，里面有没有终止状态
        for(auto it = curStates.begin(); it != curStates.end(); it++)
            if(*it == end) 
                return true;
        return false;
    }
};
```
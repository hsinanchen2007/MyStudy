回溯算法一定要先把树画出来
关键地方
（1）递归结束点：就是叶子节点的判断；
（2）for循环：兄弟节点的遍历
（3）dfs中参数的控制（depth），一层层往下dfs递归

回溯模板：
result = []
def backtrack(路径, 选择列表):
     if 满足结束条件:
        result.push_back(路径)
        return
    
     for 选择 in 选择列表:
        做选择    path.push_back(tmp);
        backtrack(路径, 选择列表) dfs(s, size, i+1, path);
        撤销选择    path.pop_back(); 
		


### 代码

```cpp
class Solution {
private:
    vector<vector<string>> result;
    bool check(string s, int start, int i){
        while(start < i){
            if(s[start++] != s[i--])
                return false;
        }
        return true;
    }


    void dfs(string s, int size, int start, vector<string>& path) {
        if (start == size) { //开始的位置已经越界,到达字符串最末位置，一棵树已经遍历到最底了,递归结束点
             result.push_back(path);
             return;
         }

        for (int i = start; i < size; i++) {   //for循环是针对兄弟节点的，是树的横向看，写for循环里面只要从上往下看层次
            if (check(s,start,i)) { //判断条件相当于剪枝
                string tmp = s.substr(start,i+1-start);
                path.push_back(tmp);
                dfs(s, size, i+1, path); //通过start= i+1 一层层往下dfs递归，i+1这里是关键
                path.pop_back(); 
            }
        }
   }
   
public:
    vector<vector<string>> partition(string s) {
        
        int size = s.size();
        int start = 0;
        vector<string> path;

        if (size == 0 || size == 1 ) {
            path.push_back(s);
            result.push_back(path);
        }
        
        if (size > 1){
            dfs(s, size, start, path);
        }
        return result;
    }
};
```
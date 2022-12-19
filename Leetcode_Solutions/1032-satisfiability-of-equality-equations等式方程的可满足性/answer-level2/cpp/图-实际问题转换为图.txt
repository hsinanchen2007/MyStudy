### dfs
1.等式的传递性相当于图的连通性，所有相等的点会出现在一个连通子图中，26个字母可能会形成多个连通子图，我们dfs将所有子图标记为不同颜色，然后查看不相等的点颜色是否相同，相同则false.

2.整个过程：
1）每个点对应一个相等和不相等的点集合。字母转换为数字：n=x-'a'
2) 从每个点开始dfs(如果已有颜色则continue)将所有连通子图标记颜色，这个只有一个连通图不同。
3）然后查看不相等的点颜色是否相同.

3.bfs遵从先入先出所以可用队列模拟，而dfs遵从先入后出，一直往前走，然后回溯，可用栈模拟，将递归改用while循环解决。

4.不要局限于题目本身的场景，跳出来灵活建模。

### 代码

```cpp
//递归
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int size = equations.size();
        vector<set<int>> equSet(26);
        vector<set<int>> notEquSet(26);
        int c1,c2;
        for (int i = 0; i < size; i++){
            c1=equations[i][0]-'a',c2=equations[i][3]-'a';
            if(c1==c2){
                if(equations[i][1]=='=')continue;
                else return false;
            }

            if(equations[i][1]=='='){
                if(notEquSet[c1].find(c2)==notEquSet[c1].end()&&notEquSet[c2].find(c1)==notEquSet[c2].end()){
                    equSet[c1].insert(c2);
                    equSet[c2].insert(c1);
                }
                else return false;
            }
            else{
                //每次添加不相等的值要判断相等集中有没有该值
                if(equSet[c1].find(c2)==equSet[c1].end()&&equSet[c2].find(c1)==equSet[c2].end()){
                    notEquSet[c1].insert(c2);
                    notEquSet[c2].insert(c1);
                }
                else return false;
            }
        }
        vector<int>color(26,0);

        //给每个连通子图标上不同颜色
        for(int i=0;i<26;i++){
            if(color[i]==0)//所在连通子图没被遍历过
                dfs(color,equSet,i+1,i);
        }

        //查看每个结点和其notEquSet中的点是否颜色不同
        for(int i=0;i<26;i++){
            for(auto c:notEquSet[i]){
                if(color[i]==color[c])return false;
            }
        }
        return true;

    }
    
    void dfs(vector<int>&color,vector<set<int>>&equSet,int tag,int n){
        color[n]=tag;
        if(equSet[n].empty())return ;

        for(auto node:equSet[n]){
            if(color[node]==0)
                dfs(color,equSet,tag,node);
        }
    }
};

//不用递归

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int size = equations.size();
        vector<unordered_set<int>> equSet(26);
        vector<unordered_set<int>> notEquSet(26);
        int c1,c2;
        for (int i = 0; i < size; i++){
            c1=equations[i][0]-'a',c2=equations[i][3]-'a';
            if(c1==c2){
                if(equations[i][1]=='=')continue;
                else return false;
            }

            if(equations[i][1]=='='){
                if(notEquSet[c1].find(c2)==notEquSet[c1].end()&&notEquSet[c2].find(c1)==notEquSet[c2].end()){
                    equSet[c1].insert(c2);
                    equSet[c2].insert(c1);
                }
                else return false;
            }
            else{
                //每次添加不相等的值要判断相等集中有没有该值
                if(equSet[c1].find(c2)==equSet[c1].end()&&equSet[c2].find(c1)==equSet[c2].end()){
                    notEquSet[c1].insert(c2);
                    notEquSet[c2].insert(c1);
                }
                else return false;
            }
        }
        vector<int>color(26,0);

        //给每个连通子图标上不同颜色
        stack<int>stk;
        for(int i=0;i<26;i++){
            if(color[i]==0){
                stk.push(i);
                while(!stk.empty()){
                    int temp=stk.top();
                    color[temp]=i+1;
                    int flag=0;
                    for(auto node:equSet[temp]){
                        if(color[node]==0){
                            stk.push(node);
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)stk.pop();
                }
            }
        }

        //查看每个结点和其notEquSet中的点是否颜色不同
        for(int i=0;i<26;i++){
            for(auto c:notEquSet[i]){
                if(color[i]==color[c])return false;
            }
        }
        return true;
    }
};

//也可以用bfs遍历

```
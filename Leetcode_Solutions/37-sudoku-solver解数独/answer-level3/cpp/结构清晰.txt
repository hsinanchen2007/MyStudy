### 解题思路
向每一个格子中填充‘1’-‘9’，判断其是否可行，可行则填入，如果出现了‘1’-‘9’都无法填充的情况，则回溯

### 代码

```cpp
class Solution {
public:
    vector<vector<char>>s;
    bool check(int p,char x){
        for(int i=0;i<9;i++){//判断行是否有重复
            if(s[p/9][i]==x)
                return false;
        }
        for(int i=0;i<9;i++){//判断列是否有重复
            if(s[i][p%9]==x)
                return false;
        }
        for(int i=p/9/3*3;i<p/9/3*3+3;i++){//判断九宫格是否有重复
            for(int j=p%9/3*3;j<p%9/3*3+3;j++){
                if(s[i][j]==x)
                    return false;
            }
        }
        return true;
    }
    bool dfs(int p){
        if(p==81){//最后一个格子符合条件，我是从0开始的（方便除法和取模运算），所以80为最后一个格子
            return true;
        }
        if(s[p/9][p%9]!='.')//如果不是空白位则跳过
            return dfs(p+1);
        for(char i='1';i<='9';i++){//枚举
            if(check(p,i)){//判断是否可填入
                s[p/9][p%9]=i;//填入字符
                if(dfs(p+1))//填下一个格子，并且检查p是否能走到81
                    return true;
                s[p/9][p%9]='.';//不可走到81，则要更换数字。
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& b) {
        s=b;//设全局方便操作
        dfs(0);
        b=s;
    }
};
```
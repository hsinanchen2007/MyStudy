### 解题思路
递归的结束条件是i == word.size()-1；
通过i+1体现一层层的回溯
回溯的思想体现在单元格匹配上只是暂时放在选择列表，回头还要移出选择列表
这个题目一定要回溯，不回退会导致其他路径经过这个点的时候无法匹配；
回溯的目的就是保证通过其他路径到达这个点的时候，这个点还会继续参加其他路径的匹配
[A,B,C,E]
[B,C,*C*,C]
[A,D,E,E]
查找ABCCED，存在2个路径

可以传引用的就不要传值（传值的话就不需要显示回溯，因为值每次进来都会更新）

### 代码
回溯模板：
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        return true;
    
    for 选择 in 选择列表:
        做选择    path.push_back(tmp);
        backtrack(路径, 选择列表) dfs(s, size, i+1, path);
        撤销选择    path.pop_back(); 



```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string& word) {
        for (int x=0; x<board.size(); ++x) {
            for (int y=0; y<board[0].size(); ++y)
                if (backtrack(board, word, 0, x, y))
                    return true;
        }
        return false;
    }

    //i 控制循环结束的条件，i达到单词大小时就结束
    bool backtrack(vector<vector<char>>& board,string& word,int i,int x,int y)
    {
        if (x < 0 || x == board.size() || y < 0 || y == board[0].size())
            return false;	//超过递归边界
        if (board[x][y] == '#' || board[x][y] != word[i])
            return false;		//递归方向不对，board[x][y]已经匹配过；或者当前位置没有匹配上
        if(i == word.size()-1)
            return true;		//递归结束条件：所有单词都已经匹配上

        //与word相等，加入选择列表
        char temp=board[x][y]; 
        board[x][y]='#';  //回溯的思想体现在单元格匹配上只是暂时放在选择列表，回头还要移出选择列表 #作为字符已经匹配过的标志
        
        //进入下一步决策
        bool flag=  backtrack(board,word,i+1,x-1,y)||backtrack(board,word,i+1,x+1,y)
                    ||backtrack(board,word,i+1,x,y-1)||backtrack(board,word,i+1,x,y+1);
       
        //移出选择列表   移除已经匹配过的标志#，重新匹配 
        board[x][y]=temp;
        return flag;
    }
};
```
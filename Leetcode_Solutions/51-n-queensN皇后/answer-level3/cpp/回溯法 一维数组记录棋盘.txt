### 解题思路
C++就是快，本题是一个非常经典的回溯问题，当年算法课上听明白了但没有动手实现过，这道题做的我也是十分曲折啊！！
基本思路：递归回溯。我们用一个一维数组position来记录整个棋盘。然后对n个皇后进行编号。我们不妨假设1号皇后放在第一行，i号皇后放在第i行。position[i]的含义就是在棋盘的第i列中放了编号为position[i]的皇后。初始化为-1表示这一列没有放过皇后。这样看起来，遍历的次序就很明显了，首先是先遍历每一个皇后（因为最后结果一定是每一个皇后都有一个列号），然后对每一个皇后，我们遍历每一个每一个列号，也就是position[i],在检查每一个position是否可以放这个皇后时，我们只需要检查两个方向的对角线就可以啦，因为行和列的冲突性已经被我们排除掉了。然后对于ok的position[i]来说，我们把它放上去，然后进入下一次递归，当然，由于可能由很多列都可以放这个皇后，所以呢自己当前的Position[i]满足规则我们也不放下去（因为说不定后面有更好的），所以我们在回溯之后要把position[i]置回-1；
一下是完整代码，本人代码能力极为有限，代码比较粗糙，有看不懂的直接评论问我就好啦。
有一点点小疑问，leetcode的oj对new 和 malloc的处理不一样吗？new的话我在本地编译执行没问题，在oj会执行出错。

### 代码

```cpp
class Solution {
public:
    vector<vector<string> > ans;
    bool is_ok(int* postion, int i, int Num){
    int temp1 = postion[i]-i;
    int temp2 = postion[i]+i;
    bool ans = true;
    for(int x=0; x<Num; x++){
        //+左上到右下 -从右上到左下
        if(x+temp1>=0 && x + temp1 < Num){
            //在二维数组的index范围内
            if(postion[x]==x+temp1){
                if(x!=i){
                    //在对角线
                    ans = false;
                    break;
                }
            }
        }
        if(temp2-x>=0 && temp2-x < Num){
            //在二维数组的index范围内
            if(postion[x]==temp2-x){
                if(x!=i){
                    //在对角线
                    ans = false;
                    break;
                }
            }
        }
    }
    
    return ans;
}
    void backtrace(int queen_index,int Num, int* position){
    if(queen_index >= Num){
        vector<string> ele_ans;
        char* str = (char*)malloc(sizeof(char)*(Num+1));
        for(int i=0; i<Num; i++){
            str[i] = '.';
        }
        str[Num] = '\0';
        for(int i=0; i<Num; i++){
            string s = string(str);
            ele_ans.push_back(s);
        }
        for(int i=0; i<Num; i++){
            ele_ans[position[i]][i] = 'Q';
        }
        // for(int i=0; i<Num; i++){
        //     for(int j=0; j<Num; j++){
        //         cout<<ele_ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        this->ans.push_back(ele_ans);
    }
    for(int i=0; i<Num; i++){
        if(position[i]==-1){
            //未被使用的列
            position[i] = queen_index;
            if(is_ok(position, i, Num)){
                //行列对角线都ok
                backtrace(queen_index+1, Num, position);           
            }
            //回溯
            position[i] = -1;
        }
    }
}
    vector<vector<string> > solveNQueens(int n) {
        int* position;
    vector< vector<string> > *ans;
    position = (int*)malloc(sizeof(int)*(n+1));
    fill_n(position, n, -1);
    int i = 0;
    backtrace(0, n, position);
    return this->ans;
    }
};
```
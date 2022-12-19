### 解题思路
**执行用时击败100.00%，内存消耗击败100.00%，**
还是很开心的，说明思路效率不错。
**题目要求：**
1、在原地解决问题，不新建新的面板；
2、注意处理面板边界。
**算法思路：**
1、建立操作数组，把8种操作都放进去；

2、遍历面板中的每一个元素（即每一个细胞），
判断这个元素值（细胞状态）会不会改变，
把所有改变了状态的细胞坐标保存入一个数组；

3、对每个元素做8种操作，计算周围存活的细胞数（注意要判断是否超出边界）：
1）元素为活的细胞：只有当周围活细胞数为2或3时，返回true，其余返回false，即细胞状态改变；
2）元素为死的细胞：只有当周围活细胞数为3时，返回false，即细胞状态改变；

4、遍历保存坐标的数组，把这个数组内的所有坐标的值取到相反值。
### 代码

```cpp
class Solution {
public:
    vector<pair<int, int>> op;
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int>> change;//保存变化了的细胞的坐标
        op_init();
        for(int i=0; i<board.size();i++){
            for(int j=0; j<board[0].size();j++){
                if (!judge(i, j, board)) change.push_back(pair<int, int>(i,j));//状态改变了
            }
        }
        for(int i=0; i<change.size(); i++){
            if (board[change[i].first][change[i].second]){
                board[change[i].first][change[i].second]=0;
            }
            else board[change[i].first][change[i].second]=1;
        }
        return;   
    }
    void op_init(){
        op.push_back(pair<int, int>(1,0));//上
        op.push_back(pair<int, int>(-1,0));//下
        op.push_back(pair<int, int>(0,1));//右
        op.push_back(pair<int, int>(0,-1));//左
        op.push_back(pair<int, int>(1,-1));//左上
        op.push_back(pair<int, int>(1,1));//右上
        op.push_back(pair<int, int>(-1,-1));//左下
        op.push_back(pair<int, int>(-1,1));//右下
        return;
    }
    bool judge(int i, int j, vector<vector<int>>& board){//判断原有状态是否改变
        //计算周围的活细胞数和死细胞数
        int num_live=0;
        int ii,jj;
        for (int k=0; k<8; k++){
            ii=i+op[k].first;
            jj=j+op[k].second;
            if (ii>=0 && ii<board.size() && jj>=0 && jj<board[0].size()){
                if (board[ii][jj]==1) num_live++;
            }
        }
        if (board[i][j]==1){
            if (num_live<2) return false;//活的死了
            else if (num_live == 2 || num_live == 3) return true;
            else return false;//活的死了
        }
        else{
            if (num_live == 3) return false;//死的活了
            else return true;
        }
    }
};
```
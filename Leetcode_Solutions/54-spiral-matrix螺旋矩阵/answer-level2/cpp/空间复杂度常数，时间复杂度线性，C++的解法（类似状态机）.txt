C++。
时间：100%，空间：88%。
空间复杂度O（1），时间复杂度O（N），其中N为m*n即输入矩阵元素总数
思路：很简单，direction标识方向，right，left等分别标识离各个边界已经存在几层。比如说一开始right为0，如果走到矩阵（除去已经遍历过的元素）最右边（根据j<(n-right-1)来判断），方向direction变为向下，right加一。

```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n;
        if(m==0) n=0;
        else n=matrix[0].size();
        int direction = 0;//标识方向
        vector<int> res(m*n);//结果向量
        int right=0;
        int left=0;
        int top=1;
        int bottom=0;
        int i=0,j=0;
        int index=0;
        //以上代码均为初始化，核心在下面的while循环里，有点像状态机
        while(index<m*n)
        {
            res[index]=matrix[i][j];
            if(direction==0&&j<(n-right-1)){j++;}
            else if(direction==0){direction++;i++;right++;}
            else if(direction==1&&i<(m-bottom-1)){i++;}
            else if(direction==1){direction++;j--;bottom++;}
            else if(direction==2&&j>left){j--;}
            else if(direction==2){direction++;i--;left++;}
            else if(direction==3&&i>top){i--;}
            else if(direction==3){direction=0;j++;top++;}
            index++;
        }
        return res;
    }
};
```

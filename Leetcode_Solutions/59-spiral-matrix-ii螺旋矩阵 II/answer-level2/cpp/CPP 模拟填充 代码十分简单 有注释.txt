### 解题思路
首先创建这个矩阵，然后循环n*n次填充这个矩阵
每次循环判断下个填充的点，如果是边界或者已经填充过就改变方向
见代码注释

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));    //创建n*n初始为0
        int i=0,j=0;        //当前坐标
        int ori=1;          //方向 1向右 2向下 3向左 4向右
        for(int x=1;x<=n*n;x++){
            res[i][j]=x;
            switch(ori){
                case 1:
                    if(j+1!=n&&res[i][j+1]==0){         //下一个向右不“撞墙”并且为空
                        j++;
                    }else{
                        ori=2;                          //调整方向为向下
                        i++;
                    }
                    break;
                case 2:
                    if(i+1!=n&&res[i+1][j]==0){         //下一个向下不“撞墙”并且为空
                        i++;
                    }else{
                        ori=3;                          //调整方向为向左
                        j--;
                    }
                    break;
                case 3:
                    if(j-1!=-1&&res[i][j-1]==0){        //下一个向左不“撞墙”并且为空
                        j--;
                    }else{
                        ori=4;                          //调整方向为向上
                        i--;
                    }
                    break;
                case 4:
                    if(res[i-1][j]==0){                 //下一个向上为空
                        i--;
                    }else{
                        ori=1;                          //调整方向为向右
                        j++;
                    }
                    break;
            }
        }
        return res;
    }
};
```
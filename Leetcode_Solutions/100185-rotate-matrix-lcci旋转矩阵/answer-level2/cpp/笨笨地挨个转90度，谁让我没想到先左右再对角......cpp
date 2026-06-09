### 解题思路
把注释的“//”去掉即可看到整个过程的实现

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size=matrix.size();
        pair<double,double> center((size-1)/2.0,(size-1.0)/2.0);//找到矩阵中心点
        for(int i=0;i<=size/2;i++){//一圈一圈处理，最后到中心点
            for(int j=i;j<size-i-1;j++){
                pair<double,double> now(i,j);
                int next_num=matrix[i][j];
                for(int k=0;k<4;k++){
                    pair<double,double> next(center.first-(center.second-now.second),center.second+center.first-now.first);
                    int now_num=next_num;
                    next_num=matrix[next.first][next.second];
                    matrix[next.first][next.second]=now_num;
                    //cout<<"("<<next.first<<","<<next.second<<")"<<"="<<now_num<<endl;
                    now=next;
                }
                //cout<<"----------"<<endl;
            }
        }
    }
};
```
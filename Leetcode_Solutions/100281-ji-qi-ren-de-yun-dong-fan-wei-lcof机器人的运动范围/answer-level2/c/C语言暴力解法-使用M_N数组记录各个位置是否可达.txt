### 解题思路
用一个大小为M*N的数组记录数据中每个点是否能到达，对一个新的点，先判断坐标和满足要求不，如果满足，判断这个点的上下左右有没有已经记录为可以到达的点，如果有，将该点记录为可到达。

### 代码

```c
bool isOK(int i,int j,int k);
int movingCount(int m, int n, int k){
    int count=1;
    int tmp[m][n];
    memset(tmp,0,sizeof(tmp));
    tmp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(isOK(i,j,k)){
                if(((i-1>=0)&&(tmp[i-1][j]==1))||((j-1>=0)&&(tmp[i][j-1]==1))){
                    tmp[i][j]=1;
                    count++;
                }
            }
        }
    }
    return count;
}

bool isOK(int i,int j,int k){
     int int_i=i/100+(i%100)/10+(i%10);
     int int_j=j/100+(j%100)/10+(j%10);
     return (int_i+int_j>k?false:true);
}
```
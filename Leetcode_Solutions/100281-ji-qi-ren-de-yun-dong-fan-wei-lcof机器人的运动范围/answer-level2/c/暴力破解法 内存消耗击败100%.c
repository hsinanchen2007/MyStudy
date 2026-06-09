### 解题思路
暴力破解法解题

### 代码

```c
int movingCount(int m, int n, int k){
    if(k<0)
        return 0;
    int cnt=1;
    int sum,p;
    int i,j,o;
    int visit[100][100]={0};//用来记录机器人的运动痕迹，若已经过该处，则置为1
    visit[0][0]=1;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            sum=0;//位数之和，每次循环都置0
            for(o=0;o<=2;o++){//求位数
                p=pow(10,o);
                if(i/p>0)
                    sum+=(i/p)%10;
                if(j/p>0)
                    sum+=(j/p)%10;
            }
            if(sum<=k){
                if((i>0&&visit[i-1][j]==1)||visit[i+1][j]==1||(j>0&&visit[i][j-1]==1)||visit[i][j+1]==1){//如果上下左右只要有一个格子机器人走过，并且该格子sum<=k，则cnt++，并将该格子的visit数组置1，表示已经被遍历过
                    cnt++;
                    visit[i][j]=1;
                }
                //注意，这里不能写break，否则会出错
            }
        }
    }
    return cnt;
}
```
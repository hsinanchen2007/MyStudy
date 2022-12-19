击败100%的用户。
在顺时针往矩阵添加数据时，移动的方向有四个：右、下、左、上，定义方向向量为int dx[]={0,1,0,-1};int dy[]={1,0,-1,0};来分别表示这四个方向，初始坐标为(0,0)，随后根据x=x+dx[i];y=y+dy[i];来更新矩阵索引，需要添加的数k从1到n*n。代码中，先把第一行填充，由于走完一次向右的方向，所以time=1，随后，每走完一个方向，time++，time用来作为dx[]/dy[]的索引；还有一个关键点在于，每次在一个方向上走时，应该走多少步，代码中用m记录，以n=5为例，我发现m的规律如下：

![IMG_0161.jpg](https://pic.leetcode-cn.com/9ba3679b12ae75ca1b22ba2217d30210172b6ef7630afb9f3e843414021d6080-IMG_0161.jpg)
发现规律并不难，难的是用代码实现出来，一会儿这可能有点问题，一会儿那儿可能有点问题，时间都耗费在写代码时的一些些漏洞上面。
```
    vector<vector<int>> generateMatrix(int n) {
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        vector<vector<int> >vec(n,vector<int>(n));
        for(int j=0;j<n;j++){
            vec[0][j]=j+1;//先把第一行填充
        }
        int x=0,y=n-1;
        int count=1,m=n-1,time=1;
        for(int k=n+1;k<n*n;){
            for(int j=m;j>0;j--){
                x=x+dx[time%4];
                y=y+dy[time%4];
                vec[x][y]=k;
                k++;
            }
            time++;
            for(int j=m;j>0;j--){
                x=x+dx[time%4];
                y=y+dy[time%4];
                vec[x][y]=k;
                k++;
            }
            m--;
            count++;
            time++;
        }
        return vec;
    }
```

### 解题思路
使用一个二维数组保存已经走过的格子；
递归：
    每到达一个位置，1.判断是否超出界限
        2.判断此格子是否来过：来过则return
        3.没有来过判断这个格子是否符合要求，不符合则return
        4.符合的话判断它上下左右四个格子。

### 代码

```java
class Solution {

    int xm,yn;
    int cnt = 0;

    public int movingCount(int m, int n, int k) {
        int [][] flag = new int[m][n];
        xm=m;
        yn = n;
        func(0,0,k,flag);
        return cnt;
    }

    public void func(int x,int y,int k,int[][] flag){
        if(x>=xm || y>=yn || x<0 || y<0){
            return;
        } 
        if(flag[x][y]==1)return;
        if(isCan(x,y,k)){
            flag[x][y]=1;
            cnt++;
            func(x+1,y,k,flag);
            func(x,y+1,k,flag);
            func(x-1,y,k,flag);
            func(x,y-1,k,flag);
        }
    }
    
    public boolean isCan(int x,int y,int k){
        int sum=0;
        while(x!=0){
            sum+=x%10;
            x/=10;
        }
        while(y!=0){
            sum+=y%10;
            y/=10;
        }
        if(sum<=k){
            return true;
        }
        else return false;
    }
}
```
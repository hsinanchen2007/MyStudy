有上下左右4个方向限制，flag=0是左右移动，flag=1是上下移动，每次碰到u,d,l,r四个方向flag就改变，t1,t2表示上下和左右移动的值，1或者-1，在碰到4个方向的时候也会改变，同时u,dl,r也会改变，但是这里边需要注意的一点是
u              r
l              d因为每次都要判断是否到达l,r,u,d这四个方向，如果你在碰到r的时候就让u+1,则向下填充一个的时候就已经满足了i=u,这显然不对，所以我们可以这样设计，在碰到l的时候r再-1，碰到u的时候d再减1，碰到d的时候u再加1，在第二次以及之后碰到r的时候l再+1
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n);
        for (int i = 0; i < a.size(); i++)
            a[i].resize(n);//矩阵
        int u=0,d=n-1,l=0,r=n-1;
        int count=1;
        int t1=1;
        int t2=1;
        int i=0,j=0;
        int flag=0;
        if(n>0)
        a[0][0]=1;
        while(count<n*n)
        {
            count=count+1;
            if(flag==0)//左右移动
            {
                j=j+t2;
                a[i][j]=count;
                if(j==r)//碰到r，则flag变为1，变成上下移动
                {
                    flag=1-flag;
                    if(count>n)
                    l=l+1;//在第二次及以后碰到r证明已经碰到过l了，l减1
                    t2=-t2;//下一次就向相反的方向移动
                }
                else if(j==l)
                {
                    flag=1-flag;
                    r=r-1;
                    t2=-t2;
                }
            }
            else if(flag==1)
            {
                i=i+t1;
                a[i][j]=count;
                if(i==d)
                {
                    flag=1-flag;
                    u=u+1;
                    t1=-t1;
                }
                else if(i==u)
                {
                    flag=1-flag;
                    d=d-1;
                    t1=-t1;
                }
            }
            if(u>d||l>r)
            break;
        }
        return a;
    }
};

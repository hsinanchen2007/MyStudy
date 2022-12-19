模拟每一步，把走过的路存下来，记录下路径边界，最后输出时再把每个地方的状态填上。
```cpp
class Solution {
    const int INF=1<<30;
    int Minx,Miny,Maxx,Maxy;
    map<pair<int,int>,bool> Mark;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int px,py,pd;
    pair<int,int> v;
    void solve(int x,int y,int d,int k)
    {
        while (true)
        {
            Minx=min(Minx,x);
            Maxx=max(Maxx,x);
            Miny=min(Miny,y);
            Maxy=max(Maxy,y);
            if (!k) break;
            v=make_pair(x,y);
            if (Mark[make_pair(x,y)]) d--;
            else d++;
            if (d<0) d=3;
            if (d==4) d=0;
            Mark[v]^=1;
            x+=dx[d];
            y+=dy[d];
            --k;
        }
        px=x;
        py=y;
        pd=d;
    }
public:
    vector<string> printKMoves(int K) {
        Minx=Miny=Maxx=Maxy=0;
        solve(0,0,1,K);
        int n=Maxy-Miny+1;
        int m=Maxx-Minx+1;
        vector<string> A;
        for (int i=0;i<n;++i)
        {
            string s;
            for (int j=0;j<m;++j) s.push_back('_');
            A.push_back(s);
        }
        for (auto it:Mark)
        {
            int x=it.first.first;
            int y=it.first.second;
            int s=it.second;
            x-=Minx;
            y-=Miny;
            if (s) A[n-1-y][x]='X';
        }
        px-=Minx;
        py-=Miny;
        char c;
        if (pd==0) c='U';
        else if (pd==1) c='R';
        else if (pd==2) c='D';
        else c='L';
        A[n-1-py][px]=c;
        return A;
    }
};
```
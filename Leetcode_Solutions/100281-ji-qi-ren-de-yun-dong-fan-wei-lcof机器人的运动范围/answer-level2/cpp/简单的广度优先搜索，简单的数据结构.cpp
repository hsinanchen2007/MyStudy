第一次题解有点乱，就当记录思路了。
其实明白了原理，解起来也不难。
我们使用广度优先搜索，从原点开始不断地生成节点，
    if(a[x][y]==1||x<0||y<0||x>=m||y>=n||(Fun(x)+Fun(y))>k)；
上面这一句使用来防止出界，二次记录，位数和大于K这三种情况的，如果当前点存在这三种那个情况的某一种或多种，那当前节点就执行空操作不做记录，更不会在这个节点上生成更多的节点。
如果没有上面三种情况，那当前点是可以广度扩展的，将a[x][y]置一；str后面添加一个空字符。
    解释一下这里的str,我利用str.length()函数获取str的长度，str初始为空，每一次产生可扩展节点，就给str后面添加空字符，这样str.length()值就加了一。
    为什么用str呢，因为我现在没必要用到复杂的数据结构。
扩展方向是向右和向下就可以了，最后返回str.length()就知道添加了多少个空字符，也就是多少个可到达节点。
就是这样，第一次写题解，有点烂，轻点喷！！！






class Solution {
public:
    string str="";
    bool a[100][100];
    int movingCount(int m, int n, int k) {

       
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                a[i][j]=0;
            }
        
        bfs(0,0,m,n,k);
        return str.length();

    }
    void bfs(int x,int y,int m,int n,int k)
    {
        if(a[x][y]==1||x<0||y<0||x>=m||y>=n||(Fun(x)+Fun(y))>k)
            ;
        else
        {
            a[x][y]=1;
            str+=' ';
            bfs(x+1,y,m,n,k);
             bfs(x,y+1,m,n,k);
        }
        
        
    }
    int Fun(int x)
    {
        
        int sum=0;
        int temp;
        while(x)
        {
            temp=x%10;
            sum+=temp;
            x=x/10;
        }
        return sum;
    }
};
我们设想一下加入有两对情侣互相坐错了位置，我们至多只需要换一次。
如果三对情侣相互坐错了位置，A1+B2,B1+C2,C1+A2。他们三个之间形成了一个环，我们只需要交换两次。
如果四队情侣相互坐错了位置，即这四对情侣不与其他情侣坐在一起，A1+B2,B1+C2,C1+D2,D1+A2.他们四个之间形成了一个环，他们只需要交换三次并且不用和其他情侣交换，就可以将这四对情侣交换好，
以此类推，其实就是假设`k`对情侣形成一个环状的错误链，我们只需要交换`k - 1`次就可以将这`k`对情侣的位置排好。
所以问题转化成N对情侣中，有几个这样的错误环。
我们可以使用并查集来处理，每次遍历相邻的两个位置，如果他们本来就是情侣，他们处于大小为1的错误环中，只需要交换0次。如果不是情侣，说明他们呢两对处在同一个错误环中，我们将他们合并（union），将所有的错坐情侣合并和后，答案就是`情侣对 - 环个数`。
这也说明，最差的情况就是所有`N`对情侣都在一个环中，这时候我们需要`N - 1`调换。
最好情况每对情侣已经坐好了，已经有`N`个大小为1的环，这时候我们需要`N - N`次调换。



```
class Solution {
public:
    vector<int> fa,size;
    int getfa(int x)
    {
        if(x != fa[x]) fa[x] = getfa(fa[x]);
        return fa[x];
    }
    void uni(int x,int y )
    {
        int fx = getfa(x),fy = getfa(y);
        if(fx != fy)
        {
            if(size[fx] < size[fy])
            {
                fa[fx] = fy;
                size[fy] += size[fx];
            }else
            {
                fa[fy] = fx;
                size[fx] += size[fy];
            }
        }
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(),m = n / 2,res = 0,circle = 0;
        fa = vector<int>(m,0),size = vector<int>(m,1);
        for(int i = 0 ; i < m ; i ++) fa[i] = i;
        for(int i = 0 ; i < n ; i += 2)
            uni(row[i] / 2,row[i + 1] / 2);
        for(int i = 0; i < m ; i ++)
            if(i == getfa(i))
                circle ++;
        return m - circle;
    }
};
```
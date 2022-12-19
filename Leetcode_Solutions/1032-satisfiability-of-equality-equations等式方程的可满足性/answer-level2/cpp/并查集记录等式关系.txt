### 解题思路
对于多个等式和不等式联合判断，需要注意的一点就是：**等式是具有传递性的**。
基于等式的传递性，首先找出所有的等式，通过**并查集**记录等式中出现的变量，之后只需要判断每一个不等式，判断不等式中的变量是否在记录等式的并查集中属于同一族，只要有一个不等式的两个变量属于同一族，就说明他们直接或者间接传递相等，发生了矛盾，返回false。否则返回true。

### 代码

```cpp
class Solution {
    int f[30];
public:
    void init()
    {
        for(int i=0;i<30;i++)
        {
            f[i]=i;
        }
    }
    int find(int x)
    {
        if(f[x]==x)
            return x;
        f[x]=find(f[x]);
        return f[x];
    }
    void uion(int x,int y)
    {
        int fx=find(x);
        int fy=find(y);
        if(fx!=fy)
        {
            f[fx]=fy;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        init();
        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='=')
            {
                uion(equations[i][0]-'a',equations[i][3]-'a');
            }
        }
        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='!')
            {
                int fx=find(equations[i][0]-'a');
                int fy=find(equations[i][3]-'a');
                if(fx==fy)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
```
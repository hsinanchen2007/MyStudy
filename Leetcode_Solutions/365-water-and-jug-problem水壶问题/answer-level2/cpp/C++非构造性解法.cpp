### 解题思路
大多数情况下这其实是一个数学问题。
这里有一个结论：当且仅当x与y的最大公因数整除z的时候可以完成倒水工作。
其他的题解已经有详细的证明了，需要一点数论知识，这里就不证了。（这就是喜欢数学的程序员独有的优势了）
这么一来，写一个非构造性的判断程序就特别简单了，比构造性的BFS写法好写又跑的快。
注意需要刨除几种特殊情况。用例中并没有涵盖所有的特殊情况，至少没有x>0，y==0，z==x这种，所以我通过的代码是有一个bug的，在下面修正了。
### 代码

```cpp
class Solution {
    int gcd(int x,int y)
    {
        while (x>0 && y>0)
        {
            y%=x;
            if (y!=0) x%=y;
        }
        if (x==0 && y!=0) return y;
        else if (x!=0) return x;
        else return 0;
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z>x+y || z<0) return false;
        if (z==0) return true;
        if (x==0)
        {
            if (z==y) return true;
            else return false;
        }
        if (y==0)
        {
            if (z==x) return true;
            else return false;
        }
        int gxy=gcd(x,y);
        if (gxy!=0 && z%gxy==0) return true;
        return false;
    }
};
```
首先，拿到这个题，我想到的是从原点开始查找，使用dfs或者bfs暴力去做。但是看了下数据范围显而易见是不行的。
所以，这个题可以考虑从终点开始往前查找。原因很简单，分析如下：
对于一个点(tx,ty)，上一步的位置很容易确定：
1.tx>ty，上一个点应该为(tx-ty,ty)
2.tx<=ty,上一个点应该为(tx,ty-tx)
如果说出现了x>tx或者y>ty，很显然查找失败。
因此我们可以写出第一版本的代码：
```
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx<sx||ty<sy){
            return false;
        }
        if(tx==sx&&ty==sy){
            return true;
        }
        if(tx>ty){
            return reachingPoints(sx,sy,tx-ty,ty);
        }
        else{
            return reachingPoints(sx,sy,tx,ty-tx);
        }
        return true;
    }
};
```
逻辑十分简单，但是提交执行出错。
出错例子为：
1
1
1000000000
1

分析原因，由于tx远大于ty，则我们递归时，需要递归的深度太大了，所以造成了函数栈溢出。 因此我们需要做一些优化，来满足条件。

如果tx>ty,我们要尽可能的使tx向ty靠拢，但是始终大于等于ty,因为这个过程是重复的。
比如tx=1000000,ty=1时，上一步是tx=999999,ty=1,上上步是tx=9999998,ty=1，tx都是通过tx+ty得到的。所以要尽可能的减少tx，
但是同时，由于我们的判别条件为x>tx时，返回false。所以我们也要保证tx>=ty的同时，也要保证tx>=sx，这样不会影响答案的正确性。否则尽管减少了，tx靠近了ty
但是返回了错误的答案。比如：
10
5
15
5
我们在对tx=15进行消减的时候，也要保证消减后的值大于等于10，否则会影响结果正确性。

同样tx<=ty时，我们也尽量让ty向tx靠拢，然是始终大于等于tx以及sy,因此代码构造如下：
```
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx<sx||ty<sy){
            return false;
        }
        if(tx==sx&&ty==sy){
            return true;
        }
        if(tx>ty){
            int d=(tx-sx)/ty;
            if(d==0){
                d=1;
            }
            return reachingPoints(sx,sy,tx-d*ty,ty);
        }
        else{
            int d=(ty-sy)/tx;
            if(d==0){
                d=1;
            }
            return reachingPoints(sx,sy,tx,ty-d*tx);
        }
        return true;
    }
};
```

最终结果：
![image.png](https://pic.leetcode-cn.com/5766e215bcb808ca3cca1b8445c5a40aaca15321030102fc0b3e7f0c1f084dfb-image.png)

首先我们分析下水壶问题给出的信息：
- 两个水壶不断改变水量，求满足当前水量x+y=z是否成立
- 状态：（x，y）组成的双值对象定义一种状态，即两个水壶的当前水量
- 动作：题目描述给出了三个动作：
        ![image.png](https://pic.leetcode-cn.com/e497f2e32daaf5368ffee00308b9330d7b49ba8960b7d4d000b8353744be1a3c-image.png)

# 思考一：动态规划？
从上述题目分析，可以容易的想到将问题分解为子问题，可以用动态规划：
- 重叠子问题：每组当前状态（x，y）通过执行三种不同动作生成新的状态（x，y）
- 最优子结构：总共有x*y种状态，初始状态为（0，0），在每个子问题中判断x+y=z是否成立，成立则存在最优子结构，返回true
- 存储历史状态：避免重复计算历史的状态，陷入循环，可用二维数组visited存储访问过的状态
- 状态转移：题目给出的三个动作，考虑到X倒入Y壶和Y倒入X壶的两种情况，共用6种转移状态
        1）x清空 -> (0,y)
        2）y清空 -> (x,0)
        3）装满x -> (capacityX,y)
        4）装满y -> (x,capacityY)
        5）x倒入y -> (max(x-capacityY+y,0),min(x+y,capacityY)) 
        6）y倒入x -> (min(x+y,capacityX),max(y-capacityX+x,0))

不过分析归分析，写出的java代码无效...
原因就在于当两个壶容量过大时，考虑x*y个状态，肯定需要较大的内存做递归运算，这样会超出内存。不过还是把代码贴上吧
```
class Solution {
    int capacityX,capacityY;
    int[][] state;
    boolean flag = false;
    public boolean canMeasureWater(int x, int y, int z) {
        capacityX = x;
        capacityY = y;
        state = new int[x+1][y+1];
        dp(0,0,z);
        return flag;
    }
    public void dp(int x,int y,int z){
        if(flag){return;}
        if(x==z||y==z||x+y==z){
            flag = true;
            return;
        }
        if(state[x][y]==1){
            return;
        }else{
            state[x][y]=1;
        }
        dp(0,y,z);
        dp(x,0,z);
        dp(capacityX,y,z);
        dp(x,capacityY,z);
        dp(Math.min(x+y,capacityX),Math.max(y-capacityX+x,0),z);
        dp(Math.max(x-capacityY+y,0),Math.min(x+y,capacityY),z);
    }
}
```

# 思考二：广度优先遍历BFS   
为了减少内存的占用，DFS（动态规划类似于DFS的过程）改为BFS，这样可以遍历一部分状态后解除遍历队列中部分对象占用的空间。
同时考虑到visited数组也占用非常大的空间，所以可以将访问过的状态改为用set存储，为了方便比较，这里将x和y的int值拼接为long存储在set中。代码如下

```
class Solution {
    int capacityX;
    int capacityY;
    public boolean canMeasureWater(int x, int y, int z) {
        capacityX = x;
        capacityY = y;
        Set<Long> set = new HashSet<>();
        Queue<Long> dfs = new LinkedList<>();   //遍历链表
        dfs.add(0L);
        while(!dfs.isEmpty()){
            Long l = dfs.poll();
            if(set.contains(l)){
                continue;
            }
            x = (int)(l>>32);
            y = (int)l.intValue();
            if(x==z||y==z||x+y==z){
                return true;
            }  
            set.add(l);
            if(x!=0&&y!=0){
                dfs.add((long)y);
                dfs.add(((long)x)<<32);
            }
            if(x!=capacityX){
                dfs.add(combineToLong(capacityX,y));
                if(y!=0){
                     dfs.add(combineToLong(Math.min(x+y,capacityX),Math.max(y-capacityX+x,0)));
                }
            }
            if(y!=capacityY){
                dfs.add(combineToLong(x,capacityY));
                if(x!=0){
                    dfs.add(combineToLong(Math.max(x-capacityY+y,0),Math.min(x+y,capacityY)));
                }
            }
        }
        return false;
    } 
    public long combineToLong(int a,int b){
        long res = (long)a;
        res = res<<32;
        return res|b;
    } 
}
```

不过空间和时间效率依然不尽人意。这时候就需要从其他角度入手，一方面从题意上缩小(x,y)的取值范围，另一方面考虑数学方法。

# 思考三 数学算法
这道题目要求的返回值是真或者假，并非求解倒水操作的集合。这时若是有数学方法能够算出是否有解，至少可以避免遍历所费的空间。

我们先来观察题目给出的例子，若是我们思考倒水的过程，可以像下方所示图来操作：
![123.png](https://pic.leetcode-cn.com/c794670154ab3f324d41085ad8a3fd97bb8cea296afce1bc2353bde0683055e6-123.png)
通过观察更多的方案，可以看出这些操作序列有以下几个特点：
- 每次注水，不会将两个水壶都打满，这样的情况在初始状态中即有所判断，即是否满足x+y==z
- 两个壶相互倒水的过程中，结果必然有一个空壶或者一个满壶，因为若是存在两个非空或非满的壶，则说明倒水的过程中没有刻度把控（只有全倒出，或者倒满才知道每个壶中水量的确定刻度）
- 每次装水的过程中，不会向非空壶内装水。若是有此操作，则相当于返回红框内的初始状态，或者两个壶都满
根据以上的观察，可以得出结论：两个壶内总水量每次的变化要么是x，要么是y，最终水量为ax+by（a、b为装水次数，若为负值，则说明该壶的水量都是从另一个壶中得来）

再回到题干，既然最终水量为ax+by，则只需判断是否存在a、b，满足：
                    ax + by = z
根据祖定理可知，判断该线性方程是否有解需要需要判断z是否为x,y最大公约数的倍数。此时为题转化为了求解最大公约数，而该问题可以使用gcd算法（辗转相除法）。最终代码如下
```
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(x==z||y==z||x+y<=z){
            if(x+y<z){
                return false;
            }
            return true;
        }
        return x>y?(z%gcd(x,y))==0:(z%gcd(y,x))==0;
    }
    public int gcd(int x,int y){
        return y==0?x:gcd(y,x%y);
    } 
}
```


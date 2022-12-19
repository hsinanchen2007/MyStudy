### 解题思路
这道题就是纯数学的解法，
第一种解法：
我们对水壶的操作就是加水和倒水，题目中要求了，加水必须加满，倒水必须倒完。
对于加水操作为1.倒水操作为-1，两个水壶里水的总数永远等于ax+by。a,b为整数。
若要两个水壶中水的总量为z.那么就要找到使z=ax+by的a,b的值
这里就用到gcd算法求x,y的最大公约数，为w。w=a1*x+b1*y.若z为w的整数倍就行。


第二种解法：
用一个unordered_set<int,int> state来记录对水壶x,y的6种操作：
1.加满x. state为{x,0}
2.加满y. state为{0,y}
3.倒完x. state为{0,state.second}
4.倒完y. state为{state.first,0}
5.x倒进y. state为{state.first-move,state.second+move}  move=min(y-state.second, state.first)
6.y倒进x. state为{state.first+move,state.second-move}  move=min(x-state.first, state.second)
使用一个队列存储当前可以走的节点。再用一个数组保存走过的节点。
首先队列了存储初始状态(0,0)。
若当前state.first+state.second==z。就返回true。
否则弹出队首节点。队首节点通过6种操作。把能达到的且没有走过的节点右压入队列。
一直循环。
直到队列为空。返回false

### 代码

```cpp
class Solution {
public:

    //执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
    //内存消耗 :6 MB, 在所有 C++ 提交中击败了100.00%的用户
    bool canMeasureWater(int x, int y, int z) {
        if(z==0) return true;
        if(x==z||y==z) return true;
        if(x==0&&y==0) return false;
        if(z>x+y) return false;
        
        
        return z%gcd(x,y)==0;
    }
    
};
```
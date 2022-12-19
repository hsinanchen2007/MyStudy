## 1. 数学方法
已知：  
- 不可能两个桶中都有水且不满。  
- 灌入水只能对空桶做。  
- 倒出水只能对满桶做。  
  
**因此，水的总量每次变化是`+-x`或`+-y`**  
所以，可得出方程`ax+by=z`，并要求`a, b`是整数解。  
  
**根据贝祖定理，`ax+by=z`有整数解`a, b`的条件是：`z`是`x`和`y`的最大公约数gcd的倍数。**  
求gcd可以用：  
1. 辗转相除法
   $$
   gcd(a, 0) = a\\
   gcd(a, b) = gcd(b, a mod b)
   $$
2. 更相减损法
   $$
   gcd(a, a) = a\\
   gcd(a, b) = gcd(a, b - a), if b > a\\
   gcd(a, b) = gcd(a - b, b), if a > b
   $$
```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z > x + y)
            return false;
        
        if (x == 0 && y == 0)
            return z == 0;
        
        return z % gcd(x, y) == 0;
    }
};
```
![image.png](https://pic.leetcode-cn.com/fad51423b476f57ce5578c619c87588b83a5f1e9ebf441cae62c5438c8eabc6f-image.png)

  
## 2. 状态节点+BFS
由于
1. 倒空只能对满壶操作
2. 装满只能对空壶操作
3. 不可能同时两个桶都有水且不满
  
把`(x, y)`看作是代表一个状态的结点，则可能有以下情况：  
1. `(0, cury)`：x倒空（当`curx == x`时）
2. `(x, cury)`：x装满（当`curx == 0`时）
3. `(curx, 0)`：y倒空（当`cury == y`时）
4. `(curx, y)`：y倒满（当`cury == 0`时）
5. x倒到y中：
   - `if (y - cury >= curx) {(0, cury + curx)}`
   - `(else) if (y - cury < curx) {curx - y + cury, y}`
6. y倒到x中：
   - `if (x - curx >= cury) {(curx + cury, 0)}`
   - `(else) if (x - curx < cury) {(x, cury - x + curx)}`
  
所以问题就变成了，从点`(0, 0)`出发，通过BFS看能否到达`(z, 0)||(0, z)||(x, z - x)||(z - y, y)`  
时间复杂度`O(xy)`，空间复杂度`O(xy)`，因为内部有判断，所以也不至于这么复杂，但是也只是勉强通过  
  
```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z > x + y)
            return false;
        
        if (x == 0 || y == 0)
            return z == x || z == y;

        //unordered_map<pair<int, int>, bool> rec;
        // unordered_map没有pair的hash函数，需要自己提供。
        map<pair<int, int>, bool> rec;
        rec[make_pair(0, 0)] = true;
        queue<pair<int, int> > q;
        q.push(make_pair(0, 0));

        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            int curx = temp.first;
            int cury = temp.second;

            if ((curx == z && cury == 0) || (curx == 0 && cury == z) || (curx == x && cury == z - x) || (curx == z - y && cury == y))
                return true;

            //empty x
            if (curx == x && rec.count(make_pair(0, cury)) == 0) {
                rec[make_pair(0, cury)] = true;
                q.push(make_pair(0, cury));
            }
            //fill x
            if (curx == 0 && rec.count(make_pair(x, cury)) == 0) {
                rec[make_pair(x, cury)] = true;
                q.push(make_pair(x, cury));
            }
            //empty y
            if (cury == y && rec.count(make_pair(curx, 0)) == 0) {
                rec[make_pair(curx, 0)] = true;
                q.push(make_pair(curx, 0));
            }
            //fill y
            if (cury == 0 && rec.count(make_pair(curx, y)) == 0) {
                rec[make_pair(curx, y)] = true;
                q.push(make_pair(curx, y));
            }
            //x -> y
            if (y - cury >= curx && rec.count(make_pair(0, cury + curx)) == 0) {
                rec[make_pair(0, cury + curx)] = true;
                q.push(make_pair(0, cury + curx));
            } else if (y - cury < curx && rec.count(make_pair(curx - y + cury, y)) == 0) {
                rec[make_pair(curx - y + cury, y)] = true;
                q.push(make_pair(curx - y + cury, y));
            }
            //y->x
            if (x - curx >= cury && rec.count(make_pair(curx + cury, 0)) == 0) {
                rec[make_pair(curx + cury, 0)] = true;
                q.push(make_pair(curx + cury, 0));
            } else if (x - curx < cury && rec.count(make_pair(x, cury - x + curx)) == 0) {
                rec[make_pair(x, cury - x + curx)] = true;
                q.push(make_pair(x, cury - x + curx));
            }
        }

        return rec[make_pair(z, 0)] || rec[make_pair(0, z)] || rec[make_pair(x, z - x)] || rec[make_pair(z - y, y)];
    }
};
```
![image.png](https://pic.leetcode-cn.com/c2d40642c7c5ddfc218b15f6e7323c3a8402ec5eb447393e1b516ea44e7d48b0-image.png)

### 解题思路
使用BFS压入可能的状态, 或者使用数学求解

### 代码

```java []
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        // 裴蜀定理求解
        if(x + y < z)
            return false;
        if(x == 0 || y==0)
            return z==0 || x+y == z;

        return z%gcd(x, y) == 0;
    }

    private int gcd(int x, int y){
        if(x % y == 0)
            return y;

        return gcd(y, x%y);
    }
}
```
```python []
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        # 裴蜀定理
        if x + y < z:
            return False

        if x==0 or y == 0:
            return z==0 or x+y == z

        return z % self.gcd(x, y) == 0

    def gcd(self, x, y):
        if x %y == 0:
            return y

        return self.gcd(y, x%y)

```
```c++ []
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        // 使用stack进行BFS搜索
        // 记录已经访问过的状态
        // 1. 初始状态 (rX, rY)
        // 2. 可能转移到的状态
        // 2.1 清空x中的水 (0, rY)
        // 2.2 清空y中的水 (rX, 0)
        // 2.3 装满x中的水 (x, rY)
        // 2.4 装满y中的水 (rX, y)
        // 2.5 x中的水导入y中, (rX-min(rX, y-rY), rY+min(rX, y-rY))
        // 2.6 y中的水导入x中, (rX+min(x-rX, rY), rY-min(x-rX, rY))

        stack<pair<int, int>> st;
        st.push(make_pair(0, 0));

        while(!st.empty()){
            // 取出当前状态
            int curX = st.top().first;
            int curY = st.top().second;
            st.pop();
            if(rec.find(make_pair(curX, curY))!=rec.end())
                continue;
            
            rec.insert(make_pair(curX, curY));

            // 达到求解条件
            if(curX == z || curY == z || curX+curY==z)
                return true;
            
            // 装载所有可能的转移状态, 加入剪枝判断, 否则TLE
            if(x > 0)
                st.push(make_pair(0, curY));
            if(y > 0)
                st.push(make_pair(curX, 0));
            if(curX != x)
                st.push(make_pair(x, curY));
            if(curY != y)
                st.push(make_pair(curX, y));
            if(x > 0 && y!=curY)
                st.push(make_pair(curX-min(curX, y-curY), curY+min(curX, y-curY)));
            if(y > 0 && x!=curX)
                st.push(make_pair(curX+min(curY, x-curX), curY-min(curY, x-curX)));
            
        }
        return false;
    }
private:
    // 使用一个集合存储已经访问过的状态
    set<pair<int, int>> rec;
};
```
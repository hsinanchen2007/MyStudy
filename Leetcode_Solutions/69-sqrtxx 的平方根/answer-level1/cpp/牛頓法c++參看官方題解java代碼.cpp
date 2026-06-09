### 解题思路
c++牛頓法參看官方題解（附在注釋部分）

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        double x0=x;
        double x1=(x0+x/x0)/2.0;
        while(abs(x0-x1)>=1)
        {
            x0=x1;
            x1=(x0+x/x0)/2.0;
        }
        return (int)x1;
    }
};
/*class Solution {
  public int mySqrt(int x) {
    if (x < 2) return x;

    double x0 = x;
    double x1 = (x0 + x / x0) / 2.0;
    while (Math.abs(x0 - x1) >= 1) {
      x0 = x1;
      x1 = (x0 + x / x0) / 2.0;
    }

    return (int)x1;
  }
}

作者：LeetCode
链接：https://leetcode-cn.com/problems/sqrtx/solution/x-de-ping-fang-gen-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
```
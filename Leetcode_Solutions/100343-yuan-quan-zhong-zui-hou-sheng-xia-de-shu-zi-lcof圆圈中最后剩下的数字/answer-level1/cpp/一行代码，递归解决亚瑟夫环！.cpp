### 解题思路
举例说明，第一个示例为例，n=5,m=3,X为删除的数
0--2--X
1--3--0
2--X
3--0--1
4--1--2
旧编号old=（新编号new+m）%n,即得到lastRemaining(n,m)与lastRemaining(n-1,m)之间的关系，
当n=1时，返回第一个编号0


### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        return n==1?0:(lastRemaining(n-1,m)+m)%n;
    }
};
```
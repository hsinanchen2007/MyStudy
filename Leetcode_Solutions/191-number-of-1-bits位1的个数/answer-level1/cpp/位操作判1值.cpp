第一反应是移位操作，每次和1相与判断最低位然后右移除去，做32次。

但是不知道内存消耗怎么优化orz

（会乱码吗再编辑一次……）

```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int an=0;
        for(int i=1;i<=32;i++)
        {
            if(n&1) an++;
            n=n>>1;
        }
        return an;
    }
};
```

执行用时 :
4 ms, 在所有 C++ 提交中击败了91.89%的用户
内存消耗 :
8.2 MB, 在所有 C++ 提交中击败了8.89%的用户

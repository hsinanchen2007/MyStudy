![QQ图片20190927151442.png](https://pic.leetcode-cn.com/fdc70c2312c56fe48a5d1db04e7a5f3a1afe2a564871e914ab295be5287989a6-QQ%E5%9B%BE%E7%89%8720190927151442.png)

一行代码搞定，学过信息论或者相关理论的直接理论推导吧……

```
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return   (int)(ceil(log(buckets)/log(minutesToTest/minutesToDie+1)));
    }
};
```

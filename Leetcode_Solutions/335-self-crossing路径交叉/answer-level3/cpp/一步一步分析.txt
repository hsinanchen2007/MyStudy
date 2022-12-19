[强推题解](https://leetcode-cn.com/problems/self-crossing/solution/335lu-jing-jiao-cha-by-zhangll/)，又是学习的一天
首先明白给出的是**正数数组**，这帮我们省去好多难题
鼠标+win自带画图作图，画的不够直啊什么的多多包涵，**起点用圆圈表示**，在每个图片下面标注了序号
我们的分析方式多是将**最后一条边设为i，前一条边设为i-1，再前面一条边设为i-2，这样以此类推**
基本思路：从不相交推导到相交，从复杂模型简化到基本模型
# 1.首先我们来讨论下不会相交的情况
其实无非就是向内扩展螺旋状，向外扩展螺旋状，或者两种的结合
![image.png](https://pic.leetcode-cn.com/4e7b1500704f31b3e87a239df8dff2013f7ca6fcf13bbf9dfbb2f57b1772e3eb-image.png)
`图1`
还有情况就是在边的个数x_size<=3的时候无论如何也相交不了
![image.png](https://pic.leetcode-cn.com/b6280d8e40e85a1a47bbefb4bdf461956eb74a7ec3e34dd1aa6fbda73b434181-image.png)
`图2`

# 2.那就先看看边数=4的相交情况
其实很简单，也就只有一种
![image.png](https://pic.leetcode-cn.com/c80f04793e3df9e99f47114802a7930fd7e08491eb4ee09783e995326175830c-image.png)
`图3`
那就先设最后遍历到的一条边为i，前面的边分别位i-1、i-2、i-3，从而得出这种情况相交的代码条件，即
![image.png](https://pic.leetcode-cn.com/667ea43c97b7b5101067a3e3166dd8dcbe1711edf31d24b3a0e1a27f47abb1c3-image.png)
`图4`
写成代码即`if (i>=3 && x.at(i-1)<=x.at(i-3) && x.at(i)>=x.at(i-2)) return true;`
这里的条件中的等于号，就包括了那种刚好相交就没有突出的情况了

# 3.再看看边数=5的情况
讨论边数=5相交的情况，我们不妨从边数=4时不相交的情况来开始推导，可以先固定[i-2]与[i-3]，对[i]和[i-1]做所有可能的分析
![image.png](https://pic.leetcode-cn.com/b5545feb1ba9a095d56d7ff892ff33036e55627541bca231313a686e3e19b6ed-image.png)
`图5`
1. 对于图5的前三种情况，其实是同一种类型，发现要想相交，只能是 第5条x.at(4) 和 第二条边x.at(1) 相交才有可能达成在边数=5情况下相交，而这种情况下 第一条边x.at(0) 就没有讨论的意义了，你挡住 第一条边x.at(0) 就发现回到了图3的情况了，所以前面的判断条件足以判断出当前3种情况
2. 对于图5的第四种情况，发现下面的边和上面的边刚好长度相等，这是可以构成在边数=5情况下有相交的，即只需要第 五条边x.at(4) 往上触碰到 第一条边x.at(0) 即可(最后一条边用不同的颜色表明)
![image.png](https://pic.leetcode-cn.com/fc7f7ce189ae3fcd5d2fcd4d770588b7cfa1f59eea5f49bda0082bbb7abfdb57-image.png)
`图6`
写成代码即`if (i>=4 && x.at(i-3)==x.at(i-1) && x.at(i)+x.at(i-4)>=x.at(i-2)) return true;`
3. 对于图5的最后一种情况就有些特别了，发现他不仅在边数=4情况下无相交，在边数=5情况下也无法相交（因为 第5条边x.at(4) 竖直向上，和 第一条边x.at(0) 平行），只有在边数=6情况下才可能出现相交了

# 4.边数=6的情况
我们上面讨论到边数=4的情况下即图5的最后一种，我们先来讨论它在边数=5的情况不相交下有几种可能
![image.png](https://pic.leetcode-cn.com/9216a57364b248d4035931e0c5e073b94de193d1de85a7de4f6dca8389075908-image.png)
`图7`
1. 来看图7第一种情况，它要想在边数=6时有相交，那么只能是 下一条边 和 最左竖直的边x.at(2) 相交了，而这种情况又退化到了图3，所以不用单独考虑
![image.png](https://pic.leetcode-cn.com/2f8c5dd3131e377b74ba1ecb7941bb66958e7e0dbbacb0b271163bfd7b018194-image.png)
`图8`
2. 图7第二种情况，他要想相交只能 下一条边 和 最开始的第一条边x.at(0) 相交，这是一种全新的情况，我们单独考虑
![image.png](https://pic.leetcode-cn.com/23d61b80cf366bd40202d0cc502499c306c18446da3378dfa5ddeb012ba75a67-image.png)
`图9`
代码即`if (i>=5 && x.at(i)+x.at(i-4)>=x.at(i-2) && x.at(i-1)+x.at(i-5)>=x.at(i-3) && x.at(i-2)>x.at(i-4) && x.at(i-3)>x.at(i-1)) return true;`
某些题解的代码可能会在大于号改成大于等于号，其实没这个必要，部分的等于条件会退化到前面两种相交模型
3. 图7的第三种情况，要想相交，只有 新增的一条边 与 第二条边x.at(1) 相交，而这又退化到了图6的情况
![image.png](https://pic.leetcode-cn.com/2b7dccb9f360fad2708ca977291a493cc77ae38079ac88eba7d08fb9a8948bcf-image.png)
`图10`
4. 图7的最后一种情况，再新增一条边怎样都构不成相交，要想相交只能在边数达到7的情况下，此时 第一条边x.at(0) 没有任何作用，而这恰好又退化到了图9的情况
![image.png](https://pic.leetcode-cn.com/db93ded11e18b70b332b10ed80f4f0cc994bb1958e968b7ea3c7a25e17571d8d-image.png)
`图11`

至此，**3种基本的相交模型**已经讨论完全了，后面在边数相加的基础上再发生相交，其实都可以退化成这3种相交模型情况之一

所以在新增一条边时，我们只需要判断他是否是3种相交模型的一种即可了
```
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int x_size=x.size();
        for (int i=3;i<x_size;++i)
        {
            if (i>=3 && x.at(i-1)<=x.at(i-3) && x.at(i)>=x.at(i-2))
                return true;
            if (i>=4 && x.at(i-3)==x.at(i-1) && x.at(i)+x.at(i-4)>=x.at(i-2))
                return true;
            if (i>=5 && x.at(i)+x.at(i-4)>=x.at(i-2) && x.at(i-1)+x.at(i-5)>=x.at(i-3) && x.at(i-2)>x.at(i-4) && x.at(i-3)>x.at(i-1))
                return true;
        }
        return false;
    }
};
```

代码很简单，想的过程。。一言难尽


















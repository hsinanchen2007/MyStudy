感觉这个猪的问题可以用信息论的方法思考
总共有x个桶每个概率相同，表达在某个桶的所需的信息量就为 h(x)=-log2(1/x)
然后每只猪都贡献了一些信息量，就变成了要多少猪才能提供足够的信息量
具体知识可以搜索一下信息量、互信息等词。先把代码粘上
```
import math
class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        ## 因为每个桶概率相同，确定在哪个桶所需的信息量靠公式可得
        ## *只有一个桶的时候信息量为0，不需要猪
        InformationQuantity = -math.log2(1/buckets)
        ## 每进行t轮测试，可以把所有的桶分为t+1部分来让猪测试，猪可以从t+1份中选出正确（有毒）的
        t = minutesToTest//minutesToDie
        ## 所以每只猪所贡献的信息量为 H(Xi) = −log2(1/t+1)
        IQperPig = -math.log2(1/(t+1))
        ## 每只猪的测试都不相干，除一下后向上取整得出需要多少猪
        return math.ceil(InformationQuantity/IQperPig)
```

看到有些回复说可以用一轮2猪测量5个桶，应该是利用了题目中'有且只有一桶装的含有毒药'的信息，可以把桶分为其中一桶和其余所有桶两组

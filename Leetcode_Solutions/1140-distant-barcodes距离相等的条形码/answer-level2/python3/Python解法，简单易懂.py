分析：
  
   要想让相邻的元素不重复那么可以将相同的元素间隔一个一字儿排开，排到末尾再从头开始填空就行。

  对于题目给的例子`[1,1,1,1,2,2,3,3]`，分两步完成:

1. `[1, _, 1, _, 1, _, 1, _]` 其中`_`表示还未填写
2. `[1, 2, 1, 2, 1, 3, 1, 4]`

这样就能保证一定不会有连续的元素存在。题目已经保证了一定存在解法。那我们需要做的是按照元素出现的次数由多到少排序好进而进行间隔插入。代码如下:

```
class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        counter = dict(collections.Counter(barcodes))
        #按出现次数统计元素
        sortedCounter = sorted( counter, key=lambda k: 0 - counter[k])
        barcodes = []
        #重新排序
        for i in sortedCounter:
            barcodes += [i] * counter[i]
        
        arrangedBarcodes = [None for _ in range(len(barcodes))]
        #间隔插入
        arrangedBarcodes[::2] = barcodes[:len(arrangedBarcodes[::2])]
        arrangedBarcodes[1::2] = barcodes[len(arrangedBarcodes[::2]):]

        return arrangedBarcodes
```
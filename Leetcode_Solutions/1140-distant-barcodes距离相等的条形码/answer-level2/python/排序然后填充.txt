按照出现次数从大到小一次排序，然后从奇数位开始填充，直到超出位置，才从偶数开始填充
import operator
```python
class Solution(object):
    def countter(self, barcodes):
        results = {}
        for x in barcodes:
            if x not in results:
                results[x] = 1
            else:
                results[x] = results[x] + 1
        results = sorted(results.items(), key=operator.itemgetter(1), reverse=True)
        print(results)
        return results

    def rearrangeBarcodes(self, barcodes):
        """
        :type barcodes: List[int]
        :rtype: List[int]
        """
        length = len(barcodes)
        if length < 3:
            return barcodes
        counts = self.countter(barcodes)
        results=[0]*length
        i = -2
        for kv in counts:
            key = kv[0]
            value = kv[1]
            # print("----")
            # print(i)
            # print(results)
            for _ in range(value):
                i += 2
                if i > length - 1:
                    i = 1
                results[i]=key
            # print(i)
            # print(results)
            # print("---")
        return results


s = Solution()
# print(s.rearrangeBarcodes([2, 2, 1, 3]))
# print(s.rearrangeBarcodes([1, 1, 1, 1, 2, 2, 3, 3]))
# print(s.rearrangeBarcodes([1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3]))
print(s.rearrangeBarcodes([1, 1, 1, 2, 2, 2]))
# print(s.rearrangeBarcodes([7, 7, 7, 8, 5, 7, 5, 5, 5, 8]))

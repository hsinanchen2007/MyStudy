![b533c951ea740d871c0a831c3ef2edb.png](https://pic.leetcode-cn.com/3c5c11ad4f5422ce99ffc37ecb587a50845223c84c6224ba1ba891d5ac4eafe5-b533c951ea740d871c0a831c3ef2edb.png)
一、算法思想
1.由于只要求返回数字数目并列最多的组有多少个，因此可以不用创建数组存储数位和相等的数字，而是利用哈希表记录每个数位和出现的次数，最后对数组的values进行排序，则排序后数组最后端相等的数的个数即为数字数目并列最多的组的个数。
2.在计算每个整数的数位和时，可以巧妙利用数学性质，减少计算量。
本例中每1000个计算1次,当然也可以更大次数计算1次。
在逐个计算每个整数数位和时，如果不逢10，因只有整数个位数加1，因此数位和加1。
当逢10不逢100时，其十位数加1，个位数由9减为0，因此数位和减8。
当逢100不逢1000时，其百位数加1，个位和十位数由9减0，因此数位和减17。
由1、2的分析不难设计相应算法。
二、算法实现
```
class Solution:
    def countLargestGroup(self, n: int) -> int:
        my_dict = {}
        i = 1
        ss = 0
        while i <= n:
            if i % 10 == 0:
                if i % 1000 == 0:
                    ss = 0
                    temp = i
                    while temp != 0:
                        ss += temp % 10
                        temp = temp // 10
                elif i % 100 == 0:
                    ss -= 17
                else:
                    ss -= 8
            else:
                ss += 1
            my_dict[ss] = my_dict.setdefault(ss, 0) + 1
            i += 1
        arr = sorted(my_dict.values())
        n = len(arr)
        if arr[0] == arr[-1]:
            return n
        for j in range(n-2, -1, -1):
            if arr[j] != arr[-1]:
                return n - j - 1
```
三、复杂度分析
1.时间复杂度：O(max(N, MlogM))，其中N=n，M表示数位和的个数。算法实现中虽然用到了两层循环，但由于内层循环执行次数为4或5次，因此两层循环实际时间复杂度为O(N)。算法实现中所用排序算法，也就是python语言中所用排序算法——蒂姆排序的时间复杂度为O(MlogM)。由于此例中，M<9*4，所以n较大时，其时间性能主要受制于计算每个整数的数位和。
2.空间复杂度：O(M)。
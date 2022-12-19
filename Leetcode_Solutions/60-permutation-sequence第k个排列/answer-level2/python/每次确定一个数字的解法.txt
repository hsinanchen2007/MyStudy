记录一下结题思路，供大家参考。
这个直接想到的方法是列举出全部排列，然后定位到目标的结果。但是在想着构造全部序列的时候发现序列是有规律的，可以一步一步确定每个位置上的数字，然后最终确定出实际的结果.
思考过程就是在纸上写了几个排列规则，然后找其中的规律。
  第一个数字比较好确认，通过k/(n-1)!就可以实现。关键是如何确定后续的数字，规律是什么。
  最核心的一个规律是用过的数字不能再继续使用，于是我想到了利用一个外部空间的数组去记录使用了当前可以用的数字，用完之后删除。每次需要找的是当前要确定的数字的下标是什么。
  接下来的一步比较复杂，是看如何更新n和k。n比较好理解，每次减一即可。k经过观察后发现是每次取k%(n-1)!。测试的时候发现当余数为0的时候会出差，需要处理一下，改成余数为0的时候k=(n-1)!. 

代码如下：
`

    def getPermutation(self, n, k):
        nums = [x+1 for x in range(n)]

        res = ""
        while n > 1 :
            tmp =  self.factorial(n-1)
            t_idx = int(math.ceil(1.0*k/tmp))
            res += str(nums.pop(t_idx-1))
            k = tmp if k%tmp == 0 else k%tmp
            n -= 1

        res = res + str(nums[0])
        return res

    def factorial(self, x):
        y = 1
        for i in range(1, x + 1):
            y = y*i
        return y

`
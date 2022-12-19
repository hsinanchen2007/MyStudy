比如所有数字的异或为:

                        xor=0010100=a^b其中a, b是出现次数为一的数字。

则xor二进制中为1的位置，所有数字中在该位置为1的数字个数为奇数，并有且仅有一个是a，b中的一个。故只要对该位置为1的数字进行异或就可得到a, b中的某一个：

                        所有该位置为1的数字异或 = c = (a, b中的某一个)

现在得到了其中一个，由于若 x ^ y = z， 则x = z^y。 故另一个可以这么求得：

                        另一个 = xor^c ,  其中c前面已经求得。


```python []
class Solution:
    def singleNumbers(self, nums):
        all_xor = 0
        for num in nums:
            all_xor ^= num

        mask = 1
        while mask & all_xor == 0:  # 找到all_xor中的1某个位置，这里为右数第一个位置（哪个都可以）
            mask = mask << 1
        a, b = 0, 0
        for num in nums:
            if mask & num != 0:  # 该位置为1才进行亦或
                a ^= num
        return [a, all_xor ^ a]


if __name__ == '__main__':
    so = Solution()
    print(so.singleNumbers([1,2,10,4,1,4,3,3]))
```


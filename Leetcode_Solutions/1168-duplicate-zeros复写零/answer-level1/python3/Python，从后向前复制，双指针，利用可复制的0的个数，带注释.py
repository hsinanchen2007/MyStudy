# 一、代码及注释：

```
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        zeros = 0                               # 记录数组中需要被复制的0的个数
                                                # 由于数组中的0是从前向后复制的
                                                # 每次复制相当于把数组整体后移1
                                                # 这里的zeros相当于数组后移的次数

        l = len(arr)                            # 数组长度
        zero_idx = -1

        for i in range(l):                         
                                                # 对于任意一个的0而言
                                                # 当后移之后
                                                # 它的位置在数组倒数第2位或之前的话
                                                # 它是会被复制的
                                                # 即它所在的位置 + 后移次数 < l - 1
            if arr[i] == 0 and zeros+i < len(arr)-1:
                                                # 当有可复制的0时
                                                # 个数+1 并记录其位置
                zeros += 1
                zero_idx = i

                                                # 由于最终结果相当于数组整体后移zeros次
                                                # 我们可以从后往前复制数组
                                                # arr[l]对应arr[l-zeros-1]
                                                # 如果index = l, i = l-zeros-1
                                                # 则arr[index] = arr[i], index -= 1
                                                # 当arr[i] = 0时，继续向前复制
                                                # arr[index] = 0, index = index - 1
                                                # 不论是否向前复制，该过程结束后，i -= 1
        index = l - 1
        for i in range(l-zeros-1,-1,-1):
            arr[index] = arr[i]
            index -= 1
            if arr[i] == 0:                     # 考虑一种特殊情况
                                                # 复制前 [1,0,2,0,3,0,0,4]
                                                # 复制后 [1,0,0,2,0,0,3,0]
                                                # 此时最后一位的0没有参与复制过程
                                                # 前面记录的zero_idx便是为了处理该情况
                                                # 当arr[i] = 0 且 i < zero_idx时
                                                # 进行向前复制
                if i <= zero_idx:
                    arr[index] = arr[i]
                    index -= 1

```

![微信截图_20200207111939.png](https://pic.leetcode-cn.com/be4208901fe638faab82dda07049fadb9e07cd5e3db763c257178f2f7be72c28-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200207111939.png)

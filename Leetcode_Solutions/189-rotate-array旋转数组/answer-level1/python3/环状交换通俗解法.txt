### 思路
观察题目给的示例
```
3
[1,2,3,4,5,6,7] => [5,6,7,1,2,3,4]
```

我们可以发现第1个数字移动到了第4`1+3`的位置，
第4个位置的数字移动到了第7`4+3`的位置，
第7个位置的数字移动到了第3`(7+3)%7`的位置
假设数组的长度为l, i=1`从第一个开始`
所以可以得出结论数字的移动是按照`(i+l)%7`的方式移动的


**只要将当前的数字等于第`(i+l)%7`个元素，并将第`(i+l)%7`个元素保存下来赋值给下一个`(i+l)%7`元素即可，交换一圈直到遍历到第一个最开始的数字为止**

### Version 1.0
```Python
class Solution:
    def rotate(self, nums: list, k: int) -> None:
        l = len(nums)
        if l < 2 or k == 0 or k == l:
            return
        i = 0
        # temp用于保存当前的位置
        temp = (i + k) % l
        # pre用来保存上一个数字
        pre = nums[i]

        while True:
            nums[temp], pre = pre, nums[temp]
            temp = (temp + k) % l
            if temp == i:
                break

        # 回到最初的位置的时候进行最后一次交换
        nums[i] = pre
```
这时候可以解出示例，但是提交后发现当输入为
```
2
[1,2,3,4,5,6]
```
得到的答案是错误的，发现只交换了一部分数字，还有一部分数字并没有交换
这是因为在`temp = 4,i = 0`的时候出现了`4 % 2 = 0`直接跳出了循环导致后续的数字并没有交换，所以我们需要在某些情况下让`4 % 2 = 0`不直接跳出循环，而是从`i+1`的位置开始继续交换

### Version 2.0
什么时候交换呢？
**其实也不难发现所有的数字都交换过位置，这样我们就可以通过判断交换的次数是否等于数组的长度即可知道是否还需要进入下一次循环**

增加初始变量`step = 0`，每进行一次交换我们就让`step + 1`
 ```Python
class Solution:
    def rotate(self, nums: list, k: int) -> None:
        l = len(nums)
        if l < 2 or k == 0 or k == l:
            return
        i = -1
        step = 0
        while step != l:
            i += 1
            # temp用于保存当前的位置
            temp = (i + k) % l
            # pre用来保存上一个数字
            pre = nums[i]
            while True:
                nums[temp], pre = pre, nums[temp]
                temp = (temp + k) % l

                step += 1
                if temp == i:
                    break
            # 回到最初的位置的时候进行最后一次交换
            nums[i] = pre
            step += 1
```

**第一次写题解，有什么不对的或者没讲明白的地方欢迎来怼**
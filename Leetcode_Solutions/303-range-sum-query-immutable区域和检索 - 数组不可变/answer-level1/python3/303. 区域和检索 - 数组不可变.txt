原理：
假设我们用 f(i,j) 表示数组 i至j 范围内的元素和，例如：f(0,4) 表示第一个元素到第五个元素的和

现有数组如下：
[1， 2， 3， 4， 5]

我们用区间表示此数组如下：
![image.png](https://pic.leetcode-cn.com/314acc0fd78f284c3d92089324889713ffcea4697546dc30d3e4fec667c8bcda-image.png)

元素一到元素五的和f(0,4)可表示为：
![image.png](https://pic.leetcode-cn.com/b7eb24a148d9112efe97cf77c32ee1f697d6ad5d0665f1cfbd4827b7af289001-image.png)

元素一到元素二的和f(0,1)可表示为：
![image.png](https://pic.leetcode-cn.com/2ca82387adf55080742c281d7b2468e2010f00eff1f9bb5cbbc16831b0ed0f5c-image.png)

元素三到元素五的和f(2,4)可表示为：
![image.png](https://pic.leetcode-cn.com/55a1706454fa4ac05895b64c903d55fe0b15db29f4e24a4bcec56a54f29e387b-image.png)

可以看出后面三个元素的和等于五个元素的和减去前面两个元素的和：f(2,4) = f(0,4) - f(0,1)

同理，第二、第三个元素的和等于前三个元素的和减去第一个元素的值：f(1,2) = f(0,2) - f(0,0)
![image.png](https://pic.leetcode-cn.com/dc8608caf56165efab9551fae5aa0be37703bac255c6ded8e37f55cb44f3ba3a-image.png)


于是，我们总结出规律：
f(i,j) = f(0, j) - f(0,i-1)
简单来说，就是：
f(i,j) = 前面j个元素的和 - 前面(i-1)个元素的和


我们先预先把 0-1,0-2,...0-j的和都算出来，用字典保存
```
class NumArray:

    def __init__(self, nums: list):
        self.memory = {}
        self.memory[-1] = 0
        for i in range(len(nums)):
            self.memory[i] = self.memory[i-1] + nums[i]
```

然后要取 f(i,j) 的值就简单了：
f(0,j) = memory[j]
f(0,i-1) = memory[i-1]

完整代码如下：
```
class NumArray:

    def __init__(self, nums: list):
        self.memory = {}
        self.memory[-1] = 0
        for i in range(len(nums)):
            self.memory[i] = self.memory[i-1] + nums[i]

    def sumRange(self, i: int, j: int) -> int:
        return self.memory[j] - self.memory[i-1]
```



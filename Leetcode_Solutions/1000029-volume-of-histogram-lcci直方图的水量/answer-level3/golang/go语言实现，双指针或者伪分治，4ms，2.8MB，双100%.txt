第一次写题解，有什么不太妥当的地方欢迎大家指出。
主要是两种方法，一种是双指针，一种是伪分治

# 双指针

两个指针 i ， j 分别从左右两端向内移动
两个指标 leftMax, rightMax 分别用于存储 [:i+1],[j:] 最高的墙

既定条件：
对于任何一个位置x，其可容纳的水柱高度为**min(leftMax,rightMax)-height[x]**
e.g.如果是左侧的高墙更高，那么只能移动右侧的指针，因为 height[j] <= rightMax <= leftMax
所以可以容纳 rightMax - height[j] 的水量，并且一定不会溢出两边的高墙。
右侧同理。

具体的实现方法：

![image.png](https://pic.leetcode-cn.com/8866026a02a82e6590e775587a7552476d06eff5d18e7ded109b1e505369e3ea-image.png)

首先特判一下，避免出现越界

![image.png](https://pic.leetcode-cn.com/933431897c106f1e1f92a90c5810477255c9e9b8554c838d04cc128796723c36-image.png)


接着初始化，i 指针指向数组头部，j 指针指向数组尾部，leftMax, rightMax 初始化为最小值，这道题是0.

![image.png](https://pic.leetcode-cn.com/7f657ddcf9567e7e08e31909fdb195c63fe842fcc21d0fcc8c9665c155834b20-image.png)

i < j 作为终止条件，更新两个指标，然后两个指针向内移动，更新结果，最后返回

# 伪分治

之所以叫**伪分治**，是因为子问题和原问题有细微的不同。原问题是一个**两侧没有高墙**的问题，
无法确定能够容纳的水量，所以要找到一堵墙，分成两个板块，每一个板块以这堵墙作为参考，
于是问题被分解成有**单侧墙**的问题。但是还不够，最好**是两侧都有墙**，这样可以**直接计算**中间
可以容纳的水量。

**第一种类型：一侧有墙**

一侧有墙的类型，可以在这个版块里找出另一堵墙，其高度小于等于边缘的那堵墙，然后分解为另一个
单侧有墙的问题和一个双侧有墙的问题。

**第二种类型，两侧有墙**

直接计算即可，找到两侧墙中高度叫小的那一个，然后乘以宽度，之后逐一减去中间的柱子高度即可。

所有递归的终止条件是板块的长度小于等于2（包括墙在内），直接返回0即可。

具体实现：

![image.png](https://pic.leetcode-cn.com/bd56d7c8449231203f279d83d4288da46d5139c7e515ad2d25277159d18a2745-image.png)

首先特判，然后遍历找高墙，分割成两个部分，调用get函数

![image.png](https://pic.leetcode-cn.com/0090ec8ae69094844ded1b696b7d5ecaec71197e08e702c3e86bd7a28f833512-image.png)


包括墙，整个板块范围是[head,tail]闭区间，hasLeft 和 hasRight 分别用来指定左侧右侧是否有墙。
返回该板块的容量。

先实现一些工具函数

**getMax函数**

![image.png](https://pic.leetcode-cn.com/e5d326cb2f5cd90a88de21edd7b91f2addf4dc1cca7235397577dcceb3de2e4d-image.png)

找到[head,tail]闭区间里最高的柱子的下标，并返回

**countWater函数**

![image.png](https://pic.leetcode-cn.com/075ee2fc6a3a47925250fa457e07e9f99d4b28cb069ad28a36860bef9bfed4e1-image.png)

用于计算[head,tail]闭区间可以容纳的水量，最高水位是max，返回水量

然后就是主要的函数（get取名字瞎取的，实在不知道怎么说。。。）

**get函数内部实现**

![image.png](https://pic.leetcode-cn.com/1701d36a6b5f6de9470dc257731e09d32e9aade6d8c3842d34e63b61305ca290-image.png)

先特判，然后初始化结果。

![image.png](https://pic.leetcode-cn.com/15c260102ad224b74cd1d40396cc53adf3a197177480c939e9990cbf49f4ddb2-image.png)

如果是两侧都有墙，直接传参计算即可。

![image.png](https://pic.leetcode-cn.com/d50a86519dde9d7601e7227a80282e4f0f30ea4ef8ff621d46a6491a07cae3a0-image.png)

如果是单侧有墙，寻找到高墙下标并分解为两个子问题。

然后就实现了。

谢谢您的阅读，有什么值得改进的地方欢迎指出。

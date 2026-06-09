## 前言

如果您觉得我的题解尚可，欢迎给我点赞和评论
[另外一个随机算法--水池抽样](https://leetcode-cn.com/problems/linked-list-random-node/solution/xu-shui-chi-chou-yang-suan-fa-by-jackwener/)

## 什么叫打乱

简单的问题往往隐藏了重要信息，比如这里的，打乱，什么才叫乱？

其中有两个要素

- 随机的结果要能够覆盖所有的情况，（譬如 n个数，最后的结果有 n! 情况，结果所有顺序必须都**能够**出现）
- 所有出现的结果 概率 相等

## 如何去打乱

首先，设定我们已经拥有了系统提供的random函数，能够提供一个给定范围内的随机数，而且我们假定这个随机过程满足给定范围内的均匀分布。 

以洗牌为例

我们洗牌的细粒度最小的动作，应该是两张牌对换。（两堆对换，一张牌抽出放在顶部等动作都是O(n)的复杂度）

要达到打乱的效果，我们比较容易想到的方式是：

n张牌组成的全新牌堆，洗1次，会得到n种可能的结果；

洗2次，会得到n*(n-1)种结果（减一是因为当第一次和第二次为互逆过程，等于回到最开始，没有新的排列出现）；

洗3次，会得到n*(n-1)*(n-2)种结果；

洗...；

洗洗更健康...；

洗n次，会得到n！种结果，此时，已经完全充满n！的空间，洗更多次，样本空间不扩充。

所以，到这里，可以知道，对于一副新牌，最少只要随机的交换n次，才能在概率的意义上，让洗牌达到足够的“乱”，那么现在问题来了，如何选择一个好的算法？

一个比较容易想到的，简单粗暴的方法是，按照上面的文字，写出这样的伪代码：

``` java
    for(int i=0;i<suit.length;i++)
    {
        random1 = Random.next(1,n);
        random2 = Random.next(1,n);
        exchange(suit[random1],suit[random2]);
    }
```

### 改进

上面的算法在设计上能够充满整个样本空间，确实存在n！种可能性，但是不够好。

为什么不够好呢，因为这种算法不能够 **确保** 照顾到每一张牌。

随机洗牌的随机在于其不确定性，对于n张牌组成的有序排列，经过了n次随机选择，漏掉1只牌从未选过的概率不等于0，而且，随着牌的张数数量增加，这个概率非常可观。

现在就是经典的Fisher–Yates算法登场的时候了。下面给出伪代码：

``` java
    for(int i=suit.length-1;i>0;i--)
    {
        random1 = Random.next(1,i);
        exchange(suit[random1],suit[i]);
    }
```
这个算法和之前的算法最大的不同在于，每一次抽卡的范围在慢慢变小，具体的步骤可以看wiki给出的例子，我就直接照搬过来，源链接：

[Fisher-Yates shuffleen.wikipedia.org![图标](https://pic.leetcode-cn.com/a5a7104e4dbb0445c422063f453dd201f5df539c1ac8c970e3dbf2c3edf6f7e9-file_1583480982794)](https://link.zhihu.com/?target=https%3A//en.wikipedia.org/wiki/Fisher-Yates_shuffle)

![img](https://pic.leetcode-cn.com/a5192e9d1470f4785d1b624317d397dc4c759b570d49883bbb5567896aa613e7-file_1583480982821)

![img](https://pic.leetcode-cn.com/56a9f83848a1668ce57026860bac8e01434e2dc6a2ae9badd2aa56aa6afe2b73-file_1583480982847)

![img](https://pic.leetcode-cn.com/7b99533f9758054fad4b77b64a1c34ee34b8e4c4af9ef1997323d3ff721339c0-file_1583480982831)

![img](https://pic.leetcode-cn.com/590cbc1281847ce19b012883e0b12617d24fd7c96a24e097012d50142fd364be-file_1583480982855)

这个算法在样本空间上，跟前面简单粗暴的随机抽取一样。

充满了n！的样本空间，好在哪里呢？

因为它利用了抽卡本身的顺序，【保证照顾】到了每一张原本序列中的卡，

而简单粗暴随机抽取存在出现重复位置的可能性，就等于浪费了一次排序的机会，

换句话说，其等效抽卡次数因为出现了过去相同的洗法，有效洗牌次数下降，样本空间缩小，无法充满整个n！空间，所以有效性会下降。

而Fisher–Yates算法在原理上保证了不会出现浪费次数，重复选择的情况，导致样本空间一直保持n！，没有坍缩，这就是其在数学意义上优秀的原因。

## python代码

```python
class Solution:
    def __init__(self, nums):
        self.nums = nums

    def reset(self):
        return self.nums

    def shuffle(self):
        array = copy.copy(self.nums)
        for i in range(len(array)):
            random_num = random.randint(i,len(array)-1)
            array[i], array[random_num] = array[random_num], array[i]
        return array
```
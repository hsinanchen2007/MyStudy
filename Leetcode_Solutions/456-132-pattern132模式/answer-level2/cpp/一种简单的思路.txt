首先可已将132问题中的三字数字分别设为front,pos,behind
由此可知，现找到pos然后左右两边去考虑
1.遍历向量，依次设遍历的值为pos，找到第一个pos的值大于其下一个元素的值
2.确定pos后开始寻找front和behind来验证我们找到的这个pos值是否可行

*注：   经过分析可得，front的值满足pos之前的所有数值里最小的元素，而behind则为pos后的所有值里最大的值。且要满足132，即为front最小，pos最大，behind小于pos，大于front

3.可将逻辑稍微分解，即先找到pos左侧最小的元素，返回其值
4.再找到pos右侧最大的元素，且要满足其值小于pos
5.随后比较找到的front,behind两值是否满足front < behind，满足则返回true,未满足则继续遍历

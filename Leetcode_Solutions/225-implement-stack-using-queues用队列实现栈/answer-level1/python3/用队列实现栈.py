### 解题思路
首先使用list实现queue
之后stack中的pop，top，empty可以直接使用queue的peek，pop和empty
push的实现通过建立一个辅助queue，将x push进入辅助队列中，之后对stack内的队列重复进行pop操作并push进入辅助queue中，最后令stack内部队列为辅助队列即可，时间复杂度较高，应该有优化方案。



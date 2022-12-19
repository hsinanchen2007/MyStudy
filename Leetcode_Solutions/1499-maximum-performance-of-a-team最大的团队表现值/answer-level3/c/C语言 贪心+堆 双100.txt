手撕堆好爽-.-

当efficiency相等时，speed越大越优。
最多有 n 种 efficiency。
按efficiency降序排序，遍历一遍，用最小堆维护，每次取出k个最大，当堆size>k时，删除掉堆顶元素（里面包含了滑动窗口的思想）

![捕获2.PNG](https://pic.leetcode-cn.com/7dd338a92041295f4595bf545bf617186a877637f796ebf94b42d7572462ae04-%E6%8D%95%E8%8E%B72.PNG)


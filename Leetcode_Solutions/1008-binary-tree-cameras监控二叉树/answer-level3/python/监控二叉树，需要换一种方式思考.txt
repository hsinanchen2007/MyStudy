要能抽象出一颗最小的二叉树(3个节点)的状态，以及状态之间的扭转。这样就能递归的解决。
3个节点的状态可以拆分为：
    1. root没有monitor 
        0. child也没有monitor
        1. child至少有1个有
    2. root有monitor -> child是什么状态都ok

用图来表达更容易梳理逻辑

![monitor_tree.JPG](https://pic.leetcode-cn.com/2469fba20592afa12a1033b7d4d464c700ad68a7658b246204caa609927f8dab-monitor_tree.JPG)



写的时候2个小细节
    1. S2的状态，child可以是S0/S1/S2,  哪个小取哪个，不要把S2直接干掉了
    2. S2记得+1，不然整个递归里面没有增加的逻辑了
![e47165046b260e23223d520d5dd9455.png](https://pic.leetcode-cn.com/f6519b719773cfb94adb285d974ba17f78d4e9e0d732f050ffd7074c54c0a119-e47165046b260e23223d520d5dd9455.png)

利用STL队列，其实这道题用一个while循环即可实现遍历，但由于返回值是vector<vector<int>>因此，需要用两个while
还有一点在做题时令我困扰的是不知道什么时候返回vector<int>（因为不同层的节点数量不同），一开始还是想着写一个高度检测函数来检测每个节点高度，如果不相同的话就返回一个vector<int>给vector<vector<int>>，后来想到，可以在每层多push进去一个NULL，将内层循环条件变为aQueue.front()即可，这也是为什么利用两个while.


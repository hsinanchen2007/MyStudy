这道题算是我见过的最简单的LeetCode题目了。。。很直接地想到使用哈希算法，但是Key的范围是`a-zA-Z`，如果直接使用数组似乎有些空间浪费，使用C++提供的unordered_map怎么样呢？ 效果如下：

**1. 使用数组**
```c++
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        char jewels[256] = {0};
        for (auto c : J)
            jewels[c] = 1;
        
        int sum = 0;
        for (auto c : S)
            sum += jewels[c];
        
        return sum;
    }
};
```
![使用内置数组的结果](https://pic.leetcode-cn.com/1413c6f4d2ac6b51e45971d1888adb8c0548f437f2dd49a0357ba6617de864c9-result1.png)

**2. 使用unordered_map**
```c++
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> jewels;
        for (auto c : J)
            jewels[c] = 1;
        
        int sum = 0;
        for (auto c : S)
            sum += jewels[c]; // may insert new elements
        
        return sum;
    }
};
```
![使用unordered_map的结果](https://pic.leetcode-cn.com/7ad46b144226f88b0ac789f5459a4db90e6c4e2385a731478fc5eb00b160067f-result2.png)

**结束语**

在本例中，使用数组和`unordered_map`在性能上是基本一致的，但由于`unordered_map`封装了比较复杂的底层实现细节，空间占用上要高于简单的数组。抛开本例来说，数组其实只能支持简单的哈希表功能，而unordered_map则是提供了一种通用的哈希表结构，远非数组可比。


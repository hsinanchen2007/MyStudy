#### 方案一：暴力遍历法
我们可以遍历数组两遍，然后计算每两个不同元素的和，如果等于 target 的话，则返回对应的下标。
```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        for (int i = 0; i < numbers.length; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                if (numbers[i] + numbers[j] == target) {
                    // 返回值的索引需要都加上 1，因为题目的说明要求返回值从非零开始
                    return new int[]{i + 1, j + 1};
                }
            }
        }
        return new int[]{-1, -1};
    }
}
```
上面的算法遍历了数组两遍，它的时间复杂度是 `O(n^2)`，但是空间复杂度是 O(1)，因为没有占用额外的空间

如果数组的长度很大的话，那么这种方案是非常慢的，接下来我们使用始末指针来优化算法。
#### 方案二：双指针法
从题目的描述来看，我们知道输入的数组是升序排列的，我们可以利用这个特点，然后使用始末指针技巧来遍历数组一遍就可以找到答案。

我们先初始化两个指针，第一个指针指向数组的第一个元素，第二个指针指向数组的最后一个元素，如下：

![image.png](https://pic.leetcode-cn.com/2852ca6b2d6fa7bdf71c57f217b4654c50948c5670a5d878e3fd5715578188ba-image.png)

这个时候，我们发现两个指针指向的元素之和**小于**目标值 18，这个时候我们应该加大元素的值，因为数组是升序排列的，所以我们只需要将第一个指针向前移动一位即可，如下图：

![image.png](https://pic.leetcode-cn.com/5f7f7ea8375ee29c6a2c961ca0cb8bf7d2171dbf26de166bc179067444e8b641-image.png)

但是，这个时候，我们发现两个指针指向的元素之和**大于**目标值 18，那么现在我们应该减少元素的值，因为数组是升序排列的，所以我们只需要将最后一个指针向后移动一位即可，如下图：

![image.png](https://pic.leetcode-cn.com/cf4c0ac09ebdba49ee192cb8469476b2c266ac6575eabe89f9425ce60a8f6942-image.png)

现在，两个指针指向的元素之和就**等于**目标值 18 了，那么这两个指针对应的索引就是我们想要的，所以返回两个索引依次加 1 的值。

代码如下：
```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int i = 0;
        int j = numbers.length - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                return new int[]{i + 1, j + 1};
            }
        }
        return new int[]{-1, -1};
    }
}
```
这种方法的时间复杂度是 O(n)，因为只要遍历一遍就可以找到结果了。

空间复杂度是 O(1)，因为没有用到额外的空间

更多算法题解见：[数据结构与算法](http://www.tangweiqun.com/)
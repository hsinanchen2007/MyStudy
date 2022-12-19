这题我觉得和第一题-两数之和没什么两样，只不过这题的返回形式是下标值加1了。
这题我也用两种方法来解答

方法一：暴力搜索法

这种方法肯定是最简单直接的了，定义两个指针从头至尾依次遍历，即可得出答案。

代码如下：

```Python
class Solution(object):
    # 此种方法属于暴力法，定义两个指针依次遍历
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        # 定义一列表专门用来保存结果集
        index_list = []
        for start in range(len(numbers)):
            for end in range(start+1, len(numbers)):
                if numbers[start]+numbers[end] == target:
                    index_list.extend([start+1, end+1])
                    break
        return index_list
        

if __name__ == "__main__":
    numbers = [2, 7, 11, 15]
    target = 9
    index_list = Solution().twoSum(numbers, target)
    print(index_list)
```

暴力法有两种形式，另一种形式是：不需要定义两个指针，只移动第一个指针，用target-numbers[start]判断其是否在numbers[start+1:]中即可。

代码如下：

```Python
class Solution(object):
    # 此种方法属于暴力法
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        # 定义一列表专门用来保存结果集
        index_list = []
        for start in range(len(numbers)):
            next_num = target - numbers[start]
            if next_num in numbers[start+1:]:
                end = numbers[start+1:].index(next_num)+start+1
                index_list.extend([start+1, end+1])
        return index_list
        

if __name__ == "__main__":
    numbers = [2, 7, 11, 15]
    target = 9
    index_list = Solution().twoSum(numbers, target)
    print(index_list)
```

不过这两种方法的执行效率你懂得，只要是暴力法基本上都是超过时间限制了。写出来主要是为了不让大家走同样的坑。

方法二：双指针两端逼近法

这种方法的名字是我这位天才自己取得，怎么样，牛逼吧！哈哈哈哈哈哈哈哈哈哈。一般暴力法的时间复杂度都是O(n^2)，即两次循环遍历，如果我只用一次遍历，那执行效率肯定会降下来。这种方法就是这样：分别定义两个指针指向数组numbers的首尾两端，分别向中间移动，直至找出符合要求的结果。

代码如下：

class Solution(object):
    # 双指针从两端往中间逼近
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        # 定义一列表专门用来保存结果集
        index_list = []
        # 分别定义首尾指针
        start = 0
        end = len(numbers)-1
        while start<end:
            if numbers[start] + numbers[end] == target:
                index_list.extend([start+1, end+1])
                break
            elif numbers[start] + numbers[end] > target:
                end -= 1
            else:
                start += 1
        return index_list
        

if __name__ == "__main__":
    numbers = [2, 7, 11, 15]
    target = 9
    index_list = Solution().twoSum(numbers, target)
    print(index_list)
```

执行效率还算不错，在80%左右。

![1.PNG](https://pic.leetcode-cn.com/f89f225ffd9546b28281ef3542323ae4d61c0540368f58675c9b9e865144f2a2-1.PNG)


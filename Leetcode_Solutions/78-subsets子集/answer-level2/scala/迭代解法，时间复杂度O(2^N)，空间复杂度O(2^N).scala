__首先通过一个实例来理解该解法__

假定输入集合为`nums`（1, 2, 3），不重复的全部子集集合为`subsets`，流程如下：


1. 没添加任何数字时，因为空集合是所有集合的子集，所以默认包含空子集。`subsets` = {[]}，

1. 添加数字1时，因为`subsets`中的空子集和1拼接形成集合[1]，再添加进`subsets` 。`subsets` = {[], [1]}

1. 添加数字2时，空子集与2拼接形成[2]，子集[1]与2拼接形成[1, 2]，再添加进`subsets`。`subsets` = {[], [1], [2], [1, 2]}

1. 添加数字3流程同上。`subsets` = {[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]}

__代码参考__
```scala []
  import scala.collection.mutable
  def getSubsets(nums: Array[Int]): List[List[Int]] = {
    // 构建subsets，添加空集合
    val subsets = new mutable.ListBuffer[List[Int]]()
    subsets.append(List())

    // 遍历需要添加的数字
    nums.foreach { num =>
      // 每拿到一个数字，用该数字与subsets中所有子集进行拼接，结果写回subsets中
      subsets.toList.foreach { subset =>
        subsets.append(subset :+ num)
      }
    }

    subsets.toList
  }
```

__复杂度分析__
- 时间复杂度：_O(2^N)_
  
  因为每添加一个数字都要与之前所有子集组合（如添加1时计算1次，添加2时计算2次，添加3时计算4次）所以每次的计算次数为等比数列（1、2、4、8）

  总计算次数我们可以根据等比数列求和公式进行推导，a1 * (1 - q^n) / (1 - q)，a1 = 1，q = 2，结果为2^n - 1，所以时间复杂度为2^N
- 空间复杂度：_O(2^N)_

  需要一个集合`subsets`存储全部子集，因为每计算一次，就将一个子集写入 ，所以空间复杂度与时间复杂度相同
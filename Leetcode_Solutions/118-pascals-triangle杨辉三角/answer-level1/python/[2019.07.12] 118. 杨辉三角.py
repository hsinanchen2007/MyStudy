(1) 很垃圾的写法, 自己想的， 但是通过了
```
def generate(numRows):
  List = []
  for i in range(0, numRows):
    itemList = []

    for j in range(0, i + 1):
      if j == 0 or j == i:
        itemList.append(1)
      else:
        previousList = List[i - 1]
        itemList.append(previousList[j-1] + previousList[j])

    List.append(itemList)

  return List
```
(2) 看了别人的例子, 甚是好啊, 学习了一哈
```
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        # 返回内容
        List = []
        # 临时数组
        temp = []

        for _ in range(numRows):
          # 每次循环都会在0位置上填上1
          # temp = [1,2,1]
          temp.insert(0, 1)
          # 插入后, 变为 temp = [1,1,2,1]

          # 针对temp的值 在temp基础上, 进行操作, 如果是1或2的情况, 该循环是不进来的
          for i in range(1, len(temp) - 1):
            temp[i] = temp[i] + temp[i + 1]

          # L1 = L # L和L1是一回事，穿同一条裤子，改L的值，L1也改变
          # L1=L[:] #L1和L是两回事，L1和L恩断义绝，改L1的值，L的内心毫无波动
          # temp[:] 是当前的值赋值给List, temp之后变更的内容不会 对List之前值有任何影响
          List.append(temp[:])
        return List
```

(3) 其实官方的例子跟我想的差不多
```
class Solution:
    def generate(self, num_rows):
        triangle = []

        for row_num in range(num_rows):
            # 这里是将确认的位置值附上值, 不确定的内容留None
            # The first and last row elements are always 1.
            row = [None for _ in range(row_num+1)]
            row[0], row[-1] = 1, 1

            # Each triangle element is equal to the sum of the elements
            # above-and-to-the-left and above-and-to-the-right.
            for j in range(1, len(row)-1):
                row[j] = triangle[row_num-1][j-1] + triangle[row_num-1][j]

            triangle.append(row)

        return triangle

作者：LeetCode
链接：https://leetcode-cn.com/problems/two-sum/solution/yang-hui-san-jiao-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

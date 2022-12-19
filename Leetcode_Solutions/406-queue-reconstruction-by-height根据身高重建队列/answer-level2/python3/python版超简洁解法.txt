### 解题思路
整体解题思路：
（1）首先按照身高h降序，个数k值升序
例如：
输入：[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
输出：[[7, 0], [7, 1], [6, 1], [5, 0], [5, 2], [4, 4]]
（2）按照k值，确定每个同学的插入位置
理由：根据k值的含义是值前面存在k个同学比他高或一样高，而我们已经根据身高对每个同学进行降序排列，因为从最高的同学进行遍历，后面的都是比他矮的，并不会影响k值，因此k即插入的位置。


### 代码

```python
class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        if len(people)==0:
            return 
        queue=[]
        people.sort(key=lambda x:(-x[0],x[1]))
        for i in people:
            queue.insert(i[1],i)
        return queue
```
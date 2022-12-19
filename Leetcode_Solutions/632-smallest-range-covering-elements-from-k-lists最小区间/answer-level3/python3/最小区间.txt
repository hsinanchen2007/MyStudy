
### 方法一：K-pointer

* 思路
    * 用k个指针来表示指向k个list中的元素，计算此时的最大最小值
    * 此时的range与全局的最大最小值形成的range进行比较
    * 如果此时range更小，那么更新全局的最大最小值
    * 不断右移指针，直到有指针到达最后一个元素
* 实现
    * `index_list`，长度为k的数组，记录指针位置
    * `elem_list`，长度为k的数组，记录指针指向的元素值
    * `currmaxval`, `currminval`，此时`elem_list`中的最大最小值
    * `maxval`, `minval`，全局的最大最小值

<![幻灯片1.JPG](https://pic.leetcode-cn.com/c8aed27f81c1d818b33e6a3267e0ef98082af7480854b4e90af9b4f369d36067-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/f99ff14b6d4907f8bc632845d82838b19ef445caca884473d120f6f49ce98aba-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/b31bc3c33bba6e2673d76e369af23989b409202d8a8c5f1e1524bf68adbdcba3-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/4150f92a62699a797bd8cfe0d1bceb03d493253a81916aeeb090febdf881a133-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/400bfd80448d631622117d8aabe353c1e18e0622731da2f43f49001aef7ddf61-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/6ced8d8edae73faad385d03e937197f35757bd3ea21629cf93e094ffba2e46aa-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/d8803a7021ce4701aadeaf0c7e9b0836de08c4bddc787f1c08a7f2fb8db90eb9-%E5%B9%BB%E7%81%AF%E7%89%877.JPG)>

代码如下：

```python []
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        # define variables
        k = len(nums)
        index_list = [0] * k
        elem_list = [0] * k
        for i in range(k):
            elem_list[i] = nums[i][index_list[i]]
        minval, maxval = min(elem_list), max(elem_list)

        # recursion
        while True:
            currminval, currmaxval = min(elem_list), max(elem_list)
            if currmaxval - currminval < maxval - minval:
                maxval = currmaxval
                minval = currminval
            index = elem_list.index(currminval)
            if index_list[index] < len(nums[index]) - 1:
                index_list[index] += 1
                elem_list[index] = nums[index][index_list[index]]
            else:
                break
        return [minval, maxval]
```

* 时间复杂度：O(nk\*k)。其中n是数组的平均长度。指针平均要移动nk次，复杂度为nk；每次移动都要计算最大最小值，复杂度为k。因此，总的复杂度为O(nk\*k)。
* 空间复杂度：O(k)。使用k个指针，建立了两个数组：`elem_list`和`index_list`，所以复杂度为O(k)。

然鹅，这个方法超时辽。于是乎，我们在方法一的基础上进行升级，使用最小堆来储存k个指针指向的元素值，这样pop最小值的复杂度为O(log(k))，最终提交成功。

### 方法二：K-pointer + heap
* 思路
    * 方法同一，只不过把数据结构升级为最小堆。复习一下堆的用法：找最小值时，先把根结点pop出来，把叶节点移到根结点，然后sift down进行交换，直到符合最小堆。
* 实现
    * python中可以使用堆`import heapq`或者优先级队列`from queue import PriorityQueue as PQ`。实际上，优先级队列的源码就是用堆来实现的。需要注意的是，`heapq`只能实现最小堆，如果要使用最大堆，可以先取相反数，再建堆，最后再取反回来。当然，这个题用最小堆就足够了。
    * 两个库的用法可以参考[这篇博文](https://blog.csdn.net/xiaohuihui1994/article/details/90552270)
    * 建立数组`elem_id_index`来存储三元组的list。

<![幻灯片8.JPG](https://pic.leetcode-cn.com/3d082fe82021079146ca32a7410e80ecd5949b7bd0f60f93bafa0a1968b0a3f6-%E5%B9%BB%E7%81%AF%E7%89%878.JPG),![幻灯片9.JPG](https://pic.leetcode-cn.com/f11ab3598de269dad01337edf5d1a479e84bdb3f012682c613210f0f0c5309a3-%E5%B9%BB%E7%81%AF%E7%89%879.JPG),![幻灯片10.JPG](https://pic.leetcode-cn.com/85654c92a2002c68098b865d2e5ead4b01e6425546ba1ee78a45fd0567f44301-%E5%B9%BB%E7%81%AF%E7%89%8710.JPG),![幻灯片11.JPG](https://pic.leetcode-cn.com/d28ddf19b7ca81799aadf252dd065f72de639dd178616ac295328422fa8ed400-%E5%B9%BB%E7%81%AF%E7%89%8711.JPG),![幻灯片12.JPG](https://pic.leetcode-cn.com/34c2b6dcb6514426db5abc84714a8eef41c30972b6948ecf5005a759d2ef2756-%E5%B9%BB%E7%81%AF%E7%89%8712.JPG),![幻灯片13.JPG](https://pic.leetcode-cn.com/7e5c93609b7c013b93a80946630ea16d2e65c035e0c8e643e8a38351836954f6-%E5%B9%BB%E7%81%AF%E7%89%8713.JPG),![幻灯片14.JPG](https://pic.leetcode-cn.com/9518df1f172f4d3cf89d52d21c4dfa1fd3686b5bd086bfa9756a6f59fcdb1711-%E5%B9%BB%E7%81%AF%E7%89%8714.JPG)>


代码如下：
```python []
import heapq
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        # define variables
        k = len(nums)
        elem_id_index = [(elem[0], id, 0) for id, elem in enumerate(nums)]
        heapq.heapify(elem_id_index)
        maxval, minval = 1e5, -1e5
        currmaxval = max(elem_id_index)[0]

        # recursion
        while True:
            currminval, id, index = heapq.heappop(elem_id_index)
            if currmaxval - currminval < maxval - minval:
                maxval = currmaxval
                minval = currminval
            if index < len(nums[id]) - 1:
                val = nums[id][index+1]
                currmaxval = max(currmaxval, val)
                heapq.heappush(elem_id_index, (val, id, index+1))
            else:
                break
        return [minval, maxval]
```

* 时间复杂度：O(nk\*log(k))。其中n是数组的平均长度。指针平均要移动nk次，复杂度为nk；计算最小值时使用堆，复杂度为O(log(k)),计算最大值复杂度为O(1)。因此，时间复杂度为O(nk\*log(k))。
* 空间复杂度：O(k)。使用k个指针，建立数组：`elem_id_idex`，所以复杂度为O(k)。

### follow-up question

如果要包含每个列表的至少两个元素呢？
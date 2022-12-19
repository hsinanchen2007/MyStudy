### 循环判断
- 使用简单的循环判断,我们的思路是顺序扫描整个数组,每扫到一个数字,逐个比较该数自和它后面的数字大小
- 这种方法时间复杂度为`O(n**2)`,空间复杂度`O(1)`
- 这种方法跑不通oj,时间复杂度很高
### 代码
```
def reversePairs(self, nums):
    """
    :type nums: List[int]
    :rtype: int        
    """
        result = 0
        for i in range(len(nums)):
            for j in nums[i:]:
                if nums[i] > j:
                    result += 1
        return result
```


### 基于归并排序的统计
![image.png](https://pic.leetcode-cn.com/0de9ed2ce35020d58d65d170353b5c4da37bcadf3de031d9026b8d3a54152520-image.png)
- 下面是我摘自剑指offer的图示,方便大家理解:
![image.png](https://pic.leetcode-cn.com/74ed2a804041a623013ceba448c5614b4eac4f96443fa8e8f0f7811feb37c2a4-image.png)
- 下面我们这样来思考:[7,5,6,4]
1. 先把数组分成两个部分[7,5],[6,4],在继续分割成[[7],[5]],[[6],[4]]两个组
2. 接着进行合并,先合并[[7],[5]],由于7>5,在这个组内存在一个逆序排列,根据由小到大排序得到[5,7];同理对[[6],[4]]进行同样的操作,得到[4,6],同样也存在一个逆序对
3. 下面进行组间的合并s1=[5,7],s2=[4,6],此时我们需要需要一个辅助数组s来存储排序好的数组,我们设置两个指针分别指向s1和s2的尾部,当前指向的数字为7和6,由于这两个数组都是排好序的,所以7会大于s2中的所有数字,即与7能组成逆序对的个数为s2数组的长度,然后将7放入s的末尾,再比较5和6,5<6,不存在逆序对,将6放入s中,此时s=[6,7],再次比较5和4,5>4,存在逆序对,逆序对的数目等于1,将5放入s,将4放入s
4. 如此下去,可以发现上面的过程就是归并排序的过程,只需简单的加入统计逆序对变量即可

### 代码

```python
class Solution(object):
    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = [0]
        def Merge_sort(s):
            n = len(s)
            if n < 2:
                return
            mid = n // 2
            s1 = s[0:mid]
            s2 = s[mid:n]
            Merge_sort(s1)
            Merge_sort(s2)
            Merge(s1,s2,s)

        def Merge(s1,s2,s):
            len_s1 = len(s1) - 1
            len_s2 = len(s2) - 1
            temp = len(s) - 1
            
            while len_s1 >=0 and len_s2 >= 0:
                if s1[len_s1] > s2[len_s2]:
                    s[temp] = s1[len_s1]
                    result[0] += len_s2 + 1
                    len_s1 -= 1
                    temp -= 1
                else:
                    s[temp] = s2[len_s2]
                    len_s2 -= 1
                    temp -= 1
                    
            while len_s1 >= 0:
                s[temp] = s1[len_s1]
                len_s1 -= 1
                temp -= 1
            while len_s2 >= 0:
                s[temp] = s2[len_s2]
                temp -= 1
                len_s2 -= 1

        Merge_sort(nums)
        return result[0]
```


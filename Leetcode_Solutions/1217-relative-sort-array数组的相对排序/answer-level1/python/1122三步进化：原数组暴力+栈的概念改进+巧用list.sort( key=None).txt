###原数组暴力解法 第一阶段解题思路
![image.png](https://pic.leetcode-cn.com/2185bf8378be9101a983e24b37bd4a4a84f6a7d39d8ed2de4cc0f709d1c6a82a-image.png)
j,i双指针指到arr1和arr2中
如果arr1[j]==arr2[i]，处理arr1的下一个数；
如果arr1[j]!=arr2[i]，并且j右侧还存在arr2[i],将右侧的删除arr2[i]，并在j处插入一个arr2[i]。
如果arr1[j]!=arr2[i]，并且j右侧不存在arr2[i],处理arr2的下一个数。
### 代码

```python3
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        j=i=0
        arr1.sort()
        while j < len(arr1)-1 and i<len(arr2):
            if arr1[j]==arr2[i]:j=j+1
            elif arr1[j]!=arr2[i] and arr1[j:].count(arr2[i])>0:
               arr1.pop(j+arr1[j:].index(arr2[i]))
               arr1.insert(j,arr2[i])
               j=j+1
            else:
                i=i+1
        return arr1
```

###栈的概念改进，第二阶段解题思路
![image.png](https://pic.leetcode-cn.com/b8fc12134bfb0902384832b686cf75a544c2b67dd6339ffe632b90928917575c-image.png)


如果j在arr2中，且在arr1中，从arr1中取出j加入到arr3中。
结束之后arr1中剩下的数不在arr2中，对剩下的数排序加到arr3之后
细节优化验证结论1、最后对剩下的arr1排序的效率比最开始就排序的高，因为处理数据量少；
细节优化验证结论2、先arr1.remove比后执行arr1.remove，占用内存少。
### 代码

```python3
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        arr3=[]
        for j in arr2:
            while j in arr1:
                arr1.remove(j)
                arr3.append(j)
        arr1.sort()
        return arr3+arr1
```

###范例学习（在提交记录中找到的一个很巧妙的范例）\
![image.png](https://pic.leetcode-cn.com/ab6fa7d1a0e060abe1ea6f6ed34f5fdd5b77aefceaf6fb62b657628283fddcce-image.png)

1、先吧arr1和arr2转换为set，求差级。对差级排序后添加到arr2后面
2、对arr1排序，按照arr2中值得顺序
### 代码

```python3
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        arr2 += sorted(set(arr1)-set(arr2))
        arr1.sort(key=arr2.index)
        return arr1
```

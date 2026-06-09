### 解题思路
将数组转化为字典，通过字典来写算法
1、我们要知道字典的定义是什么？如何来进行操作？我们先创建一个空字典，最初的数组长度用n表示
2、通过for循环，从n中取开始取数（为下标），我们通过目标值-我们所取下标值对应的数=另一个数a
3、用if判断a在不在字典中，要是在，就返回字典对应的value值，和当前的x
4、不过，第一次一般字典里面什么也没有，所以a不在字典中，那么我们九月在字典中添加值{key,value},以此类推
5、最后，我们的结果，出现在字典中，我们就返回字典中对应的值，也就是我们所说的下标。

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        #用字典来提升速度
        dict = {}
        n = len(nums)
        for x in range(n):
            a = target - nums[x]
            if a in dict:
                return dict[a],x
            else:
                dict[nums[x]]=x#字典的操作，若键不存在，则添加  字典[要添加的键]=对应值
                #字典是由{键，值}组成/{key,value} 
                #key值必须为可哈希的不可变类型如：数字、字符串、元组
                #value值可以为任何数据类型
```
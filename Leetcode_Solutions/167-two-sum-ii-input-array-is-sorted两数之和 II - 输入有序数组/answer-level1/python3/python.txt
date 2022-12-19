# 方法一：双指针

- left指针从左往右扫，right指针从右往左扫
- 如果numbers[left]+numbers[right]==target说明匹配 输出left+1和right+1 (下标从1开始，所以加一)
- 如果numbers[left]+numbers[right]<target 说明两数之和需要增加 左边指针往右移(数组升序排列)
- 如果numbers[left]+numbers[right]>target 说明两数之和需要减少 右边指针忘左移（数组升序排列）
```
class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        left=0
        right=len(numbers)-1
        while left<right:
            if numbers[left]+numbers[right]==target:
                return [left+1,right+1]
            elif numbers[left]+numbers[right]<target:
                left+=1
            else:
                right-=1
```

# 方法二：需要额外的空间(字典)存储已经扫过的元素的值和下标 
- 每次在字典中查找有没有target-numbers[i]
  -  如果有，则输出对应的i+1 和字典中对应键的值
  -  如果没有，将numbers[i]加入字典中

```
class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict_1={}
        for i in range(len(numbers)):
            count=target-numbers[i]
            if count in dict_1:
                return [dict_1[n],i+1]
            dict_1[numbers[i]]=i+1
```

#  方法三（超时）
```
class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(numbers)):
            count=target-numbers[i]
            if count in numbers and numbers.index(count)!=i:
                s=[i+1,numbers.index(count)+1]
                s.sort()
                return s
```
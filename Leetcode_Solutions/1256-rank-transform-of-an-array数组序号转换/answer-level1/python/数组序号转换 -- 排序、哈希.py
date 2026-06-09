### 解题思路
题目描述：一个整数数组 arr ，请你将数组中的每个元素替换为它们排序后的序号
思考过程：
    1. 一闪而过的思路：整数数组，计数排序、桶排序，虽然扫描两遍数组，即可得到结果，但是开辟的空间有可能无线大，因此没有尝试。
    2. 使用python 内置的sorted() 和 dict()字典，记录序号，简单容易实现，所以采用了这种方案，没想到很快通过了。
        - 时间复杂度：O(NlgN)
        - 空间复杂度：O(N) 

### 代码

```python

class Solution(object):
    def arrayRankTransform(self, arr):
        arr_s = sorted(arr)
        d = dict()
        pre_ele = None
        cnt  = 0
        for ele in arr_s:
            if ele != pre_ele:
                pre_ele = ele
                cnt += 1
                d[ele] = cnt 
        
        
        for i, ele in enumerate(arr):
            arr[i] = d[ele]
        return arr
```
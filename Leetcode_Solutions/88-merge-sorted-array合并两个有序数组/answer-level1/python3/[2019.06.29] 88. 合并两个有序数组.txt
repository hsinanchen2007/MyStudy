(1) 从末尾开始合并, 每次找到最大的
```
def merge(nums1, m, nums2, n):
  i = m - 1
  j = n - 1
  z = m + n - 1
  while(True):
    if (i < 0 or j < 0):
      break

    if nums1[i] < nums2[j]:
      nums1[z] = nums2[j]
      j -= 1
      z -= 1
    else:
      nums1[z] = nums1[i]
      i -= 1
      z -= 1

  while(i >= 0):
    nums1[z] = nums1[i] 
    i -= 1 
    z -= 1
  while(j >= 0): 
    nums1[z] = nums2[j] 
    j -= 1 
    z -= 1

  return nums1
print(merge([1,2,3,0,0,0], 3, [2,5,6],3))
```

(2) 先把nums2内容插入到nums1中, 再插入排序
```
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        i = m
        j = 0
        while(j < n):
          nums1[i] = nums2[j]
          i += 1
          j += 1

        # 前面已经是排序好的, 插入排序
        for x in range(m, len(nums1), 1):
          for y in range(x, 0, -1):
            if (nums1[y] < nums1[y - 1]):
              nums1[y], nums1[y - 1] = nums1[y - 1], nums1[y]

        return nums1
```

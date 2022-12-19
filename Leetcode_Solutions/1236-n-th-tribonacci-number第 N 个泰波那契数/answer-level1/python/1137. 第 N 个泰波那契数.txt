![image.png](https://pic.leetcode-cn.com/a26ee2d6d784dec3c663f22e0b8b0b174acdec59836f86b5419d826aa102a43d-image.png)
```
class Solution(object):
    def tribonacci(self, n):
        """
        :type n: int
        :rtype: int
        """
        arr = [0, 1, 1]
        if n == 0:
            return arr[0]
        if n == 1:
            return arr[1]
        if n == 2:
            return arr[2]
        
        a = 2
        while a < n:
            s = sum(arr)
            arr[0], arr[1] = arr[1], arr[2]
            arr[2] = s
            # print(arr)
            a += 1
        return arr[2]
```

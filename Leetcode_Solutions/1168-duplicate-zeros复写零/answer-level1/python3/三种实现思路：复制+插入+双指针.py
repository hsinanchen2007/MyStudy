```
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        # 1. using extra space, O(n)
        # pos, new = 0, arr.copy()
        # for num in new:
        #     if num == 0:
        #         arr[pos] = 0
        #         if pos < len(arr) - 1:  # 加上这个很重要，看解释
        #             arr[pos+1] = 0
        #         pos += 2
        #     else:
        #         arr[pos] = num
        #         pos +=1
        #     if pos >= len(arr):
        #         break
        
        # 2. using insert(), 这个时间复杂度直接琢磨，看解释
        # pos, N = 0, len(arr)
        # while pos < N:
        #     if arr[pos] == 0:
        #         arr.insert(pos, 0)
        #         arr.pop()
        #         pos += 1
        #     pos += 1
            
        # 3. using two pointers, O(n) without extra space
        n, i, j = len(arr), 0, 0
        while j < n:
            if arr[i] == 0:
                j += 1
            i += 1
            j += 1
        
        i -= 1    # i 回到最后一次合法的位置
        j -= 1    # j 同理，但 j 仍可能等于 n(例如输入 [0])
        
        while i >= 0:
            if j < n:
                arr[j] = arr[i]
            if arr[i] == 0:
                j -= 1
                arr[j] = arr[i]
            i -= 1
            j -= 1   
```
### 思路一分析：
复制arr到new，设置指针pos=0，然后循环new，遇到值为0时`pos+2`，不为0时`pos+1`，直到`pos>=len(arr)`;
要注意的是边界问题，当num =0时`arr[pos+1] = 0`可能会下标越界，所以这个时候要另外判断。
举例栗子：`arr = [1,0,2,3,0,4,0,5,1]`，最后结果应该是`[1,0,0,2,3,0,0,4,0]`，原数组中的第三个0就不需要添加了

### 思路二分析：
为了不使用额外的空间，可以直接使用`insert()`函数，但是大家知道`insert()`本身的时间复杂度为O(n)，当`arr = [0,0,0,0,0,0,0,0,0]`的时候，时间复杂度就变成O(n^2)，这是最坏的情况

### 思路三分析：
(待更新...)

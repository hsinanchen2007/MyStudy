### 解题思路
在当前递归过程中，拆成left和right两个有序序列，用i，j来指向这左右两个序列，只考虑用right的来统计逆序，若right[j]<left[i]，right[j]就与left的left[i:]部分构成逆序对了，在这里就可以统计增加逆序对数量。

### 代码

```python3
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        self.res = 0
        
        def digui(cur):
            length = len(cur)
            if length<2:
                return cur
            if length==2:
                if cur[1]>=cur[0]:
                    return cur
                else:
                    self.res+=1
                    return cur[::-1]
                
            left = digui(cur[:length//2])
            right = digui(cur[length//2:])
            tmp = []
            len_l,len_r = len(left),len(right)
            i,j = 0,0
            while left and right and i<len_l and j<len_r:
                if right[j]<left[i]:
                    tmp.append(right[j])
                    j+=1
                    self.res+= (len_l-i)
                else:
                    tmp.append(left[i])
                    i+=1
            if i==len_l:
                return tmp+right[j:]
            else:
                return tmp+left[i:]
        s = digui(nums)
        # print(s)
        return self.res
```
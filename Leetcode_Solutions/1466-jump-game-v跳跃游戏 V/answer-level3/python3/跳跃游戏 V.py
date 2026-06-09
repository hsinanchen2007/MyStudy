* 递推公式：设`helper(i)`为从`arr[i]`开始跳能够访问的下标数，设从`arr[i]`跳一次能跳到`arr[i1],arr[i2],...arr[in]`，其中，`i-d<=i1,i2,..,in<=i+d`, 则`helper(i)=1+max(helper(i1), helper(i2), .. helper(in))`。
* 那么怎么求`i1, i2..in`呢？如果访问过`ij(j=1,..n)`，直接返回储存的值就好。如果没访问过，找`i`左右两边符合1.递减且2.没有访问过的下标。如果没有这样的`ij`，就返回`1`，即只能访问自己。
* 最终答案为`max(helper(i)), i=0,..len(arr)-1`

```python []
class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        m = len(arr)
        self.arr = arr
        self.res = [0] * m
        self.visited = [False] * m
        
        def helper(index: int):
            if self.visited[index]:
                return self.res[index]
            access = []
            for i in range(index-1, max(-1, index-d-1), -1):
                if self.arr[i] < self.arr[index]:
                    access.append(i)
                else:
                    break
            for i in range(index+1, min(len(self.arr), index+d+1)):
                if self.arr[i] < self.arr[index]:
                    access.append(i)
                else:
                    break
            if len(access) == 0:
                self.visited[index] = True
                self.res[index] = 1
                return 1
            times = []
            for i in access:
                times.append(helper(i))
            self.visited[index] = True
            self.res[index] = max(times)+1
            return self.res[index]
        
        for i in range(m):
            _ = helper(i)
        return max(self.res)
```
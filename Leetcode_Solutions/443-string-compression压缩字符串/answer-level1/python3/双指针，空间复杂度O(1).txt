### 解题思路
1.在双指针i，j上面加一个中间指针m
2.把m当作计数起点不移动，j指针移动。直到m和j指向元素不相等位置，记录两指针差值count
3.把count的计数情况放在i指针的位置上
4.i指针记录完向后移动，m指针指向j的当前位置。
5.再次循环直到遍历完整个数组

### 代码

```python3
class Solution:
    def compress(self, chars: List[str]) -> int:
        #i is return number , m is medium number for counts start point ,j is move point
        i,m,j=0,0,0
        while j < len(chars):
            count = 0
            #start count
            while j < len(chars) and chars[m] == chars[j]:
                count +=1
                j+=1
            #change list values
            chars[i] = chars[m]    
            if count >1 and count < 10:
                chars[i+1] = str(count)
                i+=1
            elif count>=10:
                chars[i+1] = str(count//10)
                chars[i+2] = str(count%10)
                i+=2
            i+=1
            #reset next value
            m = j
        return i
```
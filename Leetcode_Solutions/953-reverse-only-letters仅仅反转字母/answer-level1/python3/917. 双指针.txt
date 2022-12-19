### 解题思路
左右两个指针，所指位置为字母，就交换，不是字母，不是字母的指针就移动一位，直到两个指针相遇结束。

### 代码

```python3
class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        S_list=list(S)
        left, right = 0, len(S)-1

        while left < right:
            if S_list[left].isalpha() and S_list[right].isalpha():
                S_list[left], S_list[right] = S_list[right], S_list[left]
                left += 1
                right -= 1
            elif S_list[left].isalpha() == False:
                left += 1
            elif S_list[right].isalpha() == False:
                right -= 1
        
        return ''.join(S_list)
```
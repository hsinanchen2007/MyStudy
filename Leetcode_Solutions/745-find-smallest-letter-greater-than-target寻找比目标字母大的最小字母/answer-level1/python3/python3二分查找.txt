### 解题思路
python3二分查找

### 代码

```python3
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        if not letters:
            return ""
        target_val = ord(target)
        len_letters = len(letters)

        if target_val >= ord(letters[-1]) or ord(letters[0]) > target_val:
            return letters[0]
        else:
            left = 0
            right = len_letters - 1
            
            while left < right:
                mid = (left+right)//2
                if ord(letters[mid]) <= target_val:
                    left = mid+1
                else:
                    right = mid

            return letters[left]

```
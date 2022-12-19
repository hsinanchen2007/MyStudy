### 解题思路
主要是使用了二分法，按照模板套，把特殊情况也就是相同的字母在开头或结尾的时候的处理方法
时间超过97%，内存超过39%
### 代码

```python3
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        target_num=ord(target)
        letters_num = [ord(letter) for letter in letters]
        if target_num<letters_num[0]:
            return letters[0]
        if target_num>=letters_num[-1]:
            return letters[0]
        left = 0
        right =len(letters_num)-1
        while left<right:
            mid = left+(right-left)//2
            if letters_num[mid]>target_num:
                right = mid
            else:
                left = mid+1
        return letters[left]
```
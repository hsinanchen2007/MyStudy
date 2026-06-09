所有的题解中就是这几种方法，原地修改，翻转修改，环式修改。

环式修改最绕最复杂，不够pythonic，
下面总结了3种原地修改方法，供君参考。

1. 原地修改
    就是后半段拿掉，补到前面去，够直接吧！
```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        [nums.insert(0,nums.pop()) for _ in range(k%len(nums))]
```
    列表的insert(k,v)操作时间复杂度O(n),pop()操作时间复杂度O(1)，164ms,提交击败约29%的python3

2. 原地修改2
    换个思路，也可以看成前半段拿掉，补到后面去，也够直接！
```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        [nums.append(nums.pop(0)) for _ in range(len(nums)-k%len(nums))]
```
    列表的pop(k)操作时间复杂度O(n),append()操作时间复杂度O(1)，但是提交效果还不错哦
    执行用时 :88 ms, 在所有 Python3 提交中击败了83.99%的用户
    内存消耗 :15.1 MB, 在所有 Python3 提交中击败了5.18%的用户

3. 分段翻转（伪空间O(1)复杂度,因为用到了切片)
    [1,2,3,4,5,6,7]==前后两段分别翻转==>[4,3,2,1,7,6,5]==总体再反转==>[5,6,7,1,2,3,4]
```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k %= len(nums)
        nums[:-k],nums[-k:] = nums[:-k][::-1],nums[-k:][::-1]
        nums.reverse()
```
    执行用时 :72 ms, 在所有 Python3 提交中击败了92.20%的用户
    内存消耗 :15.2 MB, 在所有 Python3 提交中击败了5.18%的用户

4. 分段翻转2（自写函数，空间复杂度O(1)，时间复杂度O(n)）
```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = len(nums)-k%len(nums)
        
        def reverse(nums,s,e):
            while e>s:
                nums[s],nums[e] = nums[e],nums[s]
                e -= 1
                s +=1
        
        reverse(nums,0,k-1)
        reverse(nums,k,len(nums)-1)
        reverse(nums,0,len(nums)-1)

```
    执行用时 :68 ms, 在所有 Python3 提交中击败了95.25%的用户
    内存消耗 :14.9 MB, 在所有 Python3 提交中击败了5.18%的用户
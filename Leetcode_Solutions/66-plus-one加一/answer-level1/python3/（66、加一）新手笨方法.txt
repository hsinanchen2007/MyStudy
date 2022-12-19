执行用时 :28 ms, 在所有 Python3 提交中击败了97.05%的用户
内存消耗 :13.7 MB, 在所有 Python3 提交中击败了5.76%的用户
思路：将列表转化为字符串，再将字符串转化为数字，数字加一以后，再转化回去
```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits = [str(x) for x in digits]
        s1 = ''
        for i in range(len(digits)):
            s1 += digits[i]
        n = int(s1)
        n +=1 
        s2 = str(n)
        digits2 = []
        for j in range(len(s2)):
            digits2 += s2[j]
        digits2 = [int(x) for x in digits2]
        return digits2
```
别人的代码：
思路：逆向遍历，不为9时+1，为9时变为0
```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(1,len(digits)+1):
            if digits[-i] != 9:
                digits[-i] += 1
                return digits
            digits[-i] = 0
        digits.insert(0,1)  # 输入[9]时，9变为0的同时，前一位要插入1
        return digits
```
作者：xiao-sa-de-yuan-shuai
链接：https://leetcode-cn.com/problems/plus-one/solution/yi-ci-bian-li-by-xiao-sa-de-yuan-shuai/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

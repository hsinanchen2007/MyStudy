### 解题思路-快慢指针
本题的关键是如何将判断快乐数转换成如何判断是否为循环链表。循环链表的判断用快慢指针或哈希表即可。

根据题意，每一个正整数n可以找到下一个正整数m（n的各位平方和），一直传递下去，这个概念类似于链表的节点；
非快乐数存在一个无限循环，即链表中的循环链表；但快乐数也存在一个循环，即1本身循环，因此只要将这种循环情况排除在外即可。

### 代码

```python3
class Solution:
    """
    快慢指针: 本题可以看作一个链表，根据计算规则由n1->n2->n3->...，看最终能否变为1，即快乐数；
    对于非快乐数而言，存在一个不到1的循环链表，而对于快乐数，该链表会一直传递到1，随后会一直在1本身循环；
    因此本题可以转换为判断是否存在循环链表？与141题类似，借助快慢指针进行判断；
    """
    def sumTotal(self, n):
        """
        用来计算规则来返回整数n的下一个节点
        """
        res = 0
        while n:
            res += (n%10)**2
            n = n//10
        return res


    def isHappy(self, n: int) -> bool:
        if n == 1:
            return True
        if n == 0:
            return False

        # slow每次走一步，fast每次两步
        slow, fast = n, n
        while slow != 1 and fast != 1:
            slow = self.sumTotal(slow)
            fast = self.sumTotal(fast)
            fast = self.sumTotal(fast)
            # 由于快乐数也存在环，该环为1本身，除这种情况外的循环均为非快乐数
            if fast == slow and slow != 1 and fast != 1:
                return False
        
        return True
```
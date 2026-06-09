因为做过142题环形链表，也是有格环需要找到入口。  
这题一摸一样基本上，把数组看成链表就好了，有个数学的trick当时在142题学的。

不画了相当于一条**马路**---通着**操场**⭕️ ，在操场里一直绕圈。  ---⭕️，马路长设为a，圈为b。 
1. 设两个指针一快一慢，fast一次走两步，slow一次走一步，路程二倍关系吧
则 fast = 2*slow

2. 因为有环，两者相遇时（想象操场跑圈，相遇时一定快的比慢的人多跑了n圈吧）
则 fast = slow + nb，**b为环长。**

3. 结合上面俩式子（注意是正好是相遇时）则 slow = nb ，fast = 2nb 

4. 那么相遇时候，slow这人正好走了nb步，注意他是从头走的呀，那么需要再走个前面马路的长正好就是入口
**因为从头走，马路+n个圈即a + nb 一定是入口点啊。**

5. 设个新指针这里fast代替，从头走，一次一步，走个马路的长正好就碰到slow了。
```
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        fast, slow = 0, 0 #快慢两个指针
        while True: 
            fast = nums[nums[fast]] #快的一次走两格
            slow = nums[slow] #慢的一次走一格
            if fast == slow: 
                break        #第一次相遇停止
        
        fast = 0 #快的从头开始
        while fast != slow : #俩人都一次一格速度 相遇即为入口
            fast = nums[fast]
            slow = nums[slow]
        return fast
```

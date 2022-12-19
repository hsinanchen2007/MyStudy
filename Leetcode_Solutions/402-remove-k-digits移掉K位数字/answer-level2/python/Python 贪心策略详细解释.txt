主要依据 “Zhen Song” 和 “Inzone” 两位的代码，加了一些详细的解释。
```
class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        
        """处理boundary case，允许去除digit k=0 或者 k和num一样长"""
        if k==0: return num
        if len(num) == k: return '0'
        
        """贪心策略在于：希望去掉一些digit使得从左向右是increasing order，因为越靠左的digit的weight越大，比如15<51，而我们因为只能去掉一些有限的k个digit，我们希望能把那些靠左而且还大的digit去掉。"""
        Stack = list()
        for s in num:
            while k>0 and Stack:
                if Stack[-1] > s:
                    k -= 1
                    Stack.pop() #pop这个行为就相当于我们在原num里去掉了1个数字，所以要k-=1
                else:
                    break
            if not Stack and s=='0': #leading zero 可以忽略，不用管他
                continue
            Stack.append(s)
        while k>0 and Stack: #如果iterate一遍num后，k还没有等于0，那么我们就pop掉Stack里最后k个digit，因为他们是大的digit（Stack里是increasing order）
            Stack.pop()
            k-=1
        
        if len(Stack)==0: return '0' #k太大了，全部pop完了，所以就是0
        else: return "".join(Stack)
```

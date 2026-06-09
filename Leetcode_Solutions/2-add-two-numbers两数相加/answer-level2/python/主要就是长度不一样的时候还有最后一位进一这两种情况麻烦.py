### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def addTwoNumbers(self,l1,l2):
        res,l=self.find(l1,l2)
        if l!=0:
            res=self.find2(l,res)
        elif self.state==1:res.append(1)
        l=ListNode(res[0])
        if len(res)>=2:nl=ListNode(res[0]);l.next=nl
        for i in range(1,len(res)):
            nl.val=res[i]
            if i!=len(res)-1:nl.next=ListNode(0)
            nl=nl.next
        return l
    def find(self, l1, l2):
        self.state=0 ;res=[] ;fs=0 ;l=0
        while True:
            if self.state==0:
                tmp=l1.val+l2.val
            else:
                tmp=l1.val+l2.val+1
                self.state=0
            if tmp>=10:
                tmp=tmp%10
                self.state=1
            res.append(tmp)
            l1=l1.next ;l2=l2.next
            if not l1 and not l2:
                break
            elif not l1:
                l=l2 ;break
            elif not l2:
                l=l1 ;break
        return res,l
    def find2(self,l,res):
        state=0 ;fs=0
        while True:
            if self.state==0:
                tmp=l.val
            else:
                tmp=l.val+1 ;self.state=0
            if tmp>=10:
                tmp=tmp%10 ;self.state=1
            res.append(tmp)
            l=l.next
            if not l:
                if self.state==1:res.append(1)
                break
        return res
 

```
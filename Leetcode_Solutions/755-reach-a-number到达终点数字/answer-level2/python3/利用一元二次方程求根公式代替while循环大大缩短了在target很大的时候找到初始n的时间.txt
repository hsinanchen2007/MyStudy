和大部分人思路差不多，先对target取绝对值，后面修改了一下，利用一元二次方程求根公式代替while循环大大缩短了在target很大的时候找到初始n的时间（代替注释行），然后再找到最近的可以让target与迈出步数之差为偶数的n就好了，详细思路可以看注释
```
class Solution:
    def reachNumber(self, target: int) -> int:
        target=abs(target)          #same for + and -
        n=1+int(-1+(1+4*target)**0.5)//2                         #step start at min steps while target <= steps, the last step is n. func: ceil(n for (n+1)*n/2=target)
        #while target>(n*(1+n)/2):   #count "n" steps which get (over) the target
        #    n+=1
        if target==(n*(1+n)/2):     #if get target return n (else:can't just get the target when move to a certain direction)
            return n
        base = n*(n+1)/2            #set base step when make all n movements to same direction
        step=target-base            #difference between target and base
        while step%2!=0:            #difference between "+x" and "-x" is "2x", so let the difference between step and target is even
            n+=1                    #也就是说我们可以将之前长度为x的任意一步变为反方向，因为这一步一定有(target-step)<(n)
            step+=n
        return n
```

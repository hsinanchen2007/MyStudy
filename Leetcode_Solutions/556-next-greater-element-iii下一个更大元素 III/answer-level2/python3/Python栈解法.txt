为了找到题目中要求的数字，可以考虑**将数字视作一个数组**，那么我们需要**从右往左寻找某一个元素a[i]，在它的右边，存在一个元素a[j]，使得a[j]>a[i]且j>i成立**，找到这两个元素后，**将a[i]和a[j]位置互换，并把i+1到末尾的所有数组按递增顺序排列即可，即a[i+1:].sort()**

为了实现这个逻辑，我们可以用i代表扫描的位置，t代表目前扫描到的元素（t=a[i]），用栈stack保存目前为止遍历的所有元素，**由于加入stack中的元素总是大于stack[-1]，相当于stack已经进行了递增排序，因此不必考虑排序**。举例如下：

数字1234可以转化为数组[1,2,3,4]
1. i=3, t=4，stack=[]，因此把4加入stack，stack=[4]
2. i=2, t=3，stack=[4]，此时stack[-1]>3，因此停止扫描，并遍历stack内的元素，找到大于3的最小值，即4，交换他们的位置，t=4, stack=[3]。
3. **此时i=2, t=4, stack=[3]。保留数组下标0-1的位置，即a[:i]=[1,2]，此时a[i]=t=4,a[i+1:]=stack=[3]，所以结果为[1,2,4,3]**


举一个更加复杂的例子，比如2431可以转化为[2,4,3,1]
1. i=3, t=1，stack=[]，因此把1加入stack，stack=[1]
2. i=2, t=3，stack=[1]，此时stack[-1]<=3，因此把3加入stack，stack=[1,3]
3. i=1, t=4, stack=[1,3],此时stack[-1]<=4,因此把4加入stack, stack=[1,3,4]
4. i=0, t=2, stack=[1,3,4],此时stack[-1]>2，此时可以停止扫描，寻找stack中大于2的最小值，即3，交换他们的位置，t=3, stack=[1,2,4]，停止扫描。
5. **此时i=0, t=3, stack=[1,2,4]。保留数组下a[:i]=[]，此时a[i]=t=3,a[i+1:]=stack=[1,2,4]，所以结果为[3,1,2,4]**

按照该逻辑写出的代码为：
```
class Solution:
    def nextGreaterElement(self, n: int) -> int:
        stack = []
        res = 0
        a = []
        l = 0

        while n:
            a.append(n%10)
            n = n//10
            l += 1
        a.reverse()      #将n转化为数组a

        for i in range(l-1,-1,-1):    #从a的左右端往左开始遍历和比较
            if stack and stack[-1]>a[i]:#如果stack非空，且stack的最后一个数比当前a[i]要大
                                        #说明已经找到了恰当的a[i]，只需要遍历stack找到合适的值即可
                for j in range(len(stack)):
                    if stack[j]>a[i]:
                        stack[j],a[i] = a[i],stack[j]
                        break

                a = a[:i]+[a[i]]+stack #更新数组a
        
                for i in range(l):     #将数组a转化为数字
                    n = n*10 + a[i]
                return n if n<=2**31-1 else -1 #由于是32位正整数，如果超出范围则返回-1
            stack.append(a[i])
        
        return -1                    #如果遍历结束仍没有符合条件的数，即n为当前情况的最大值，返回-1
```

可以看到，被交换的数值a[i]前面的数字并没有真正参与运算，为了提高算法的效率，我们不必一开始便将数字n彻底转化为数组a，相反地，我们可以逐次取出n的最后一位进行比较，其他的逻辑与上述算法相似，代码如下：

```
class Solution:
    def nextGreaterElement(self, n: int) -> int:
        stack = []
        res = 0

        while n:
            t = n%10  #t为每次取出的n的最后一位
            n = n//10
            if stack and stack[-1]>t:
                for i in range(len(stack)):
                    if stack[i]>t:
                        stack[i],t = t,stack[i]
                        break
                digit = 0
                while stack:
                    res = res*10 + stack.pop(0)
                    digit += 1
                n = n*pow(10,digit+1)+t*pow(10,digit)+res
                return n if n<=2**31-1 else -1
            stack.append(t)
        
        return -1
```

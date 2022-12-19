请原谅我不会做图,只能用枯燥的文字来叙述。

# 第零步:算法分析
既然是O1内存空间的挑战,就势必不能开数组、开散列表,因此选择快慢指针法

# 第一步:数学模型
令p1速度为1,p2速度为2,考虑以下情况:
1.p2追p1时是否可能错过? 
答:不可能,因为p1>p2时必有p1-p2>=1,则(p2+2)-(p1+1)>=0

2.若环足够大,p1==p2意味着什么?
答:不妨设环大小为R,因为p1走了step,p2走了2*step,且p2恰巧比p1多转一圈,因此step == R
其中step由两部分组成,设s为入环前的路程,a为入环后的路程,易知s == step-a == R-a
注意到p1,p2相遇时,它们在环上所处的位置恰好是a,因此与环路入口的距离恰好是R-a
而head与环路入口的距离恰好是s,因此由head和p1/p2同时出发以相同速度前进必能相遇,相遇所需步数即为s

3.若环不够大,有什么不同?
不妨设p1==p2时p2在环上绕了k圈,即step == k * R,显然k必定是整数
由于k未知,s == step-a = k*R-a变得不可求,此时需要重新进行实验以确定k的大小
注意到,令p1,p2同时从环上出发再次相遇,此时有 step' == R ,因此k = step // step'
为了使用2中的结论,必须令k==1,因此对于k>1的情况,我们就一路滚过去。
loop: head -> head.next | (k-1)*R次,回归至情形2

#第二步:敲代码
之后就是码农的故事了::
先是自定义的测试用例
```
class Node(object):
        def __init__(self, x):
            self.val = x
            self.next = None

    ph = Node(None)
    p = ph
    test = None
    for i in range(4):
        node = Node(i)
        if i == 1: test = node
        p.next = node
        p = node
    p.next = test
```
然后是对数学模型的拆解
```
# 第零步,预处理
if not head or not head.next: return -1

p1 = head.next
p2 = head.next.next
count_a = 1

# 第一步,相逢
while p1!=p2:
    if not p2 or not p2.next: return -1
    p1 = p1.next
    p2 = p2.next.next
    count_a += 1

# 第二步,重逢
p1 = p1.next
p2 = p2.next.next
count_b = 1
while p1!=p2:
    p1 = p1.next
    p2 = p2.next.next
    count_b += 1
k = count_a // count_b

# 第三步,跑环
count = count_b * (k-1)
p = head
while k>1:
    for i in range(count_b):
        p = p.next
    k -= 1

# 第四步,连接
while p!=p1:
    p = p.next
    p1 = p1.next
    count += 1

##
return count
```
以上代码经过测试,并不能提交通过,但代码不背锅好吧,代码可以在正常时间内执行到返回,但平台会报超时=_=
可以用上面提供的本地测试用例检查算法
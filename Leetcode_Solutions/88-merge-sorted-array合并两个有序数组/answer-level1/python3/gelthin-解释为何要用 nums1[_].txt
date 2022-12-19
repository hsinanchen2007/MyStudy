### 解题思路
一般而言归并排序，需要一个额外大小为 m+n 的空间。
这里归并排序只用到了一个额外大小为 min(m, n) 的空间，较为巧妙。
如此一来，设置三个指针，只需要把当前合适的数放到额外空间中。
由于比较，总会有一个数组先结束，对于后结束的一个数组，如果其恰好就是最终需要返回的，则无需处理。
如果是另一个数组，则直接把它的剩下值全部 copy 过去，这里看了官方题解，
发现 nums1[k-b:k+1] = nums2[:b+1]  # 必然有 k-b == 0，因为剩下的是最小的，必然是copy到最前面 

官方题解中还有一些迷惑人的地方，涉及到 python3 的语言特性
排序法： nums1[:] = sorted(nums1[:m] + nums2) 以及 从前往后指针法：nums1_copy = nums1[:m], nums1[:] = []

我们可能会问，为何要使用 nums1[:]? 是否可以将 nums1[:] 换为 nums1 ?

我们来看一下题目要求：
对于 python3 语言， 题目要求：Do not return anything, modify nums1 in-place instead.
即，需要就地修改 nums1 对象，而不能新生成一个对象，并让 nums1 指向这一新对象。

注意到 python3 语言, 对象是一个盒子，有具体的地址，而变量名相当于是 "标签"，可以贴在盒子上。

我们需要辨析：nums1 = A  和 nums1[:] = A 的不同之处：
+ nums1 = A              # 更改 nums1 这一变量名所指向的对象。让 nums1 变量指向 A 所指向的对象
+ nums1[:] = A           # 对 nums1 指向的对象赋值。把 A 变量指向的对象的值逐个 copy 到 nums1 指向的对象中并覆盖 nums1 指向的对象的原来值。

nums1[:] 等价于 nums1[0:len(nums1)] 相当于取 nums1 对应的对象的一个视图，通常用这个来改变原对象的某几位值。
比如有时候，我们用 A[:2] = [0,1], 来改变 A 所指向的 list 对象的前两个值。
而如果用 A = [0,1], 则是让 A 这一变量名指向新的 list 对象 [0,1]


下面的代码则验证了上面的解释：

``` python3 
# 对象在内存中的地址与id 一一对应，可以使用 id() 查看并判断是否是同一个对象

nums1 = [1,2,4,0,0] 
print(id(nums1)) # 140125129895880

A = [1,2,3,4,5]
print(id(A))     # 140125129856640

nums1[:] = A
print(id(nums1))) # 140125129895880,  仍是原 list 对象, 只不过这一 list 对象的值发生了改变

# 若不执行 nums1[:] = A, 而执行
nums1 = A
print(id(nums1))  # 140125129856640, 不再是之前的那个 list 对象
```
示意图如下：
![difference_assign.png](https://pic.leetcode-cn.com/fbe36719d8d26410816c69213f2f6b30c8617bdfbfc0b75bf55780f1d6d46457-difference_assign.png)

到这里我们就明白了为何要使用 nums1[:]。这里 sorted() 函数返回的必然是一个新的对象，因此我们需要 nums1[:], 而 [] 也代表一个新的 list 对象，我们需要用 nums1[:] = []。

ps: 如果没有就地修改的要求，则用 nums1 也是完全正确的。


更多关于 python3 语言特性请参见书籍： 《流畅的Python》



### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if 0 == n:
            pass
        elif 0 == m:
            nums1[:n] = nums2[:n]
        else:
            a, b = m-1, n-1
            k = m+n-1
            while (a>=0) and (b>=0):
                if nums1[a]<=nums2[b]: #  nums1 的元素尽量少动
                    nums1[k] = nums2[b]
                    k -= 1
                    b -= 1
                else:
                    nums1[k] = nums1[a]
                    k -= 1
                    a -= 1
            if (a>=0):
                pass
            if (b>=0):
                nums1[k-b:k+1] = nums2[:b+1]  # 必然有 k-b == 0，因为剩下的是最小的，必然是copy到最前面 


```
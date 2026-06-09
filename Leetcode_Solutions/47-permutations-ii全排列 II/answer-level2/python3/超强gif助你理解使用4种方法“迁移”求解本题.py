大家做本题之前一定已经做过`46.全排列`了，而且针对46题我也写了一个题解(你不需要去找我在上一题的题解，下面我还会说的)，从**4种**不同的角度阐述了解题方法。如果你没看过也没关系，这两题很类似，只不过46题很理想没有重复数字，本题有重复数字而已。下面我将联合这两题分析一下之间的差异以及如何修改之前的代码使其能够适用本题。

# 1.投机取巧——库函数`itertools.permutations`
##### 针对46题
Python已经提供了`itertools.permutations`函数，用于输出对输入数字的全排列。针对无重复数字的全排列，我们是这么写的：
```python []
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return list(itertools.permutations(nums))
```
嗯，很简洁。那么问题来了：
1. 该程序是否适用本题呢？
2. 若不适用，要怎么修改呢？
##### 针对本题
直接把代码复制并提交，出现“解答错误”，再一看结果，每个结果出现了2遍，重复了，下面我们就要思考怎么样把重复的结果去掉。
![image.png](https://pic.leetcode-cn.com/3b9afd973f4cebfcdca8f2d83ab7221d74ca913aea79807964294a274ac8b58f-image.png)
略微做点改变，利用`集合set`的自动去重功能。`itertools.permutations(nums)`返回的是一种类似`元组`的形式，那么我们只要每次读取一个，再把它加入集合，如果已经存在于集合中将不会再次添加；如果集合中没有就会添加。
```python []
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        return {i for i in itertools.permutations(nums)}
```
# 2.宇宙无敌——回溯法
##### 针对46题
上一题从程序运行的的角度，体现了`nums=[1,2,3]`的运行过程以及相应变量的变化过程。代码如下：
```python []
class Solution:
    def permute(self, nums): 
        def backtrack(nums,tem):
            if nums==[]:
                if tem not in res:
                    res.append(tem[:])
            else:
                for i in range(len(nums)):
                    tem.append(nums[i])
                    backtrack(nums[0:i]+nums[i+1:],tem)
            if tem == []:
                return
            tem.pop()

        res = []
        tem = []
        backtrack(nums,tem)
        return res
```
#### gif中需要注意的点：
1. 右边是`程序运行队列图`，程序执行到的语句将 变红 显示。
2. 针对for循环，已经遍历过的数字将 变红 显示。全部变红代表遍历完成，此时将继续执行后续语句。
3. 图中由上而下`回溯深度`依次增加，其中回溯深度指的是当前程序运行到本段，调用backtrack（自己），程序进入了第二层执行；而第一层的程序相当于“停止”在了backtrack行，等待第二层运行完返回结果后再继续往后执行。反应在图中即为backtrack变灰、程序运行队列图叠加了下一个backtrack函数。
4. 动画在主程序第一轮for循环时较慢，第二轮开始就比较快了。动画和程序执行图中变红的语句对应着看会更便于理解！
5. gif时间较长，不要着急，慢慢的多看几遍。
![7.gif](https://pic.leetcode-cn.com/30cb68d56925ecebddaa4dba35ff23e85a0442cb3b2ecba10246a8f5cb207bdf-7.gif)

同样的，我们提出这两个问题：
1. 该程序是否适用本题呢？
2. 若不适用，要怎么修改呢？

##### 针对本题
我们先不急着提交，从程序运行的角度来想一想代码是否可以。
............................................思考的过程..................................................
嗯，其实在写上一题的时候我就在想，万一结果重了怎么办，于是就在最后一步append结果的时候加了个限制条件`if tem not in res:`，这句话存在就保证了相同的结果不会append入返回的列表中。
![image.png](https://pic.leetcode-cn.com/541cf8da291bd5f084a8ba9b5ec71884aeade47d23613f42daba03a8d869ba52-image.png)
提交通过了，但是时间有点不忍直视。我们再从程序执行的角度思考一下，针对`nums=[1,1,2]`的情况，`for i in range(len(nums)):`中第一轮是对`nums[0]=1`循环的，第二轮是对`nums[1]=1`循环的，二者的最终结果完全一致，都是`[1,1,2] [1,2,1]`；第三轮循环针对`nums[2]=2`，但是回溯的第二层和第三层都是1，所以将得到两次`[2,1,1]`(没听懂没关系，下面的gif帮助你理解)。也就是说，如果一个数字我们之前已经读取过了，当我们再次读到其他位置的相同数字时，直接跳过该轮轮循环就行，这样程序运行就会变得更快，这种思想就叫`剪枝`。
```python []
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def backtrack(nums,tem):
            if nums==[]:
                if tem not in res:
                    res.append(tem[:])
            else:
                for i in range(len(nums)):
                    if nums[i] in nums[:i]: #去重语句
                        continue
                    tem.append(nums[i])
                    backtrack(nums[0:i]+nums[i+1:],tem)
            if tem == []:
                return
            tem.pop()

        res = []
        tem = []
        backtrack(nums,tem)
        return res
```
![image.png](https://pic.leetcode-cn.com/247b25ff5f6567cbc599ec3e8abdc456732074ecca015aa0b90723534ee5f3fa-image.png)
时间直接降到了104ms，效果还是很显著的。
下面的gif展现的是`nums=[1,1,2]`的情况，帮助你理解回溯的执行过程，需要注意：
1. 右边是程序运行队列图，程序执行到的语句将 变红 显示。
2. 针对for循环，已经遍历过的数字将 变红 显示。全部变红代表遍历完成，此时将继续执行后续语句。
3. 图中由上而下回溯深度依次增加，其中回溯深度指的是当前程序运行到本段，调用backtrack（自己），程序进入了第二层执行；而第一层的程序相当于“停止”在了backtrack行，等待第二层运行完返回结果后再继续往后执行。反应在图中即为backtrack变蓝、程序运行队列图叠加了下一个backtrack函数。
4. 动画和程序执行图中变红的语句对应着看会更便于理解！
![10.gif](https://pic.leetcode-cn.com/acd5b0e4a5786b7e0f6a40a0f6a248799e90a859c4d4d8094bccbda3651d6f82-10.gif)


# 3.见异思迁——[31题](https://leetcode-cn.com/problems/next-permutation/)
##### 针对46题
31题是让我们求解输入数组的下一个排列，假设我们输入的就是最小的值1234，那么31题将输出1243；再将结果送入31题的程序，将输出1324...也就是说我们可以将31题的程序变成本题的一个函数，循环调用之并把结果保存到一个列表中，直到结果为最大值时停止。

下面以`nums=[1,2,3,4]`为例图解31题的思路(动画从1432到2134的时候来回往复了3遍，便于观察选取数字以及排序的过程)：：
![8.gif](https://pic.leetcode-cn.com/bdf817ef655d611988063a65a12c8f16a3f75a87cfd6eb11b3f58756629a9028-8.gif)

31题解决好了，下面的问题就是怎么调它、怎么保存结果，以及怎么判断是否已经达到最大值该停止循环了。尝试一下吧。

```python []
class Solution:
    def permute(self, nums):    
        nums.sort()
        is_max = 0#达到最大值
        res=[]
        res.append(nums[:])

        while is_max!=1:
            tem=[]
            a = self.nextPermutation(nums)
            if a==1:
                return res
            else:
                res.append(a[:])
        return res


    def nextPermutation(self,nums):#来自31题，改变了两个return
        is_max = 1
        r = 2 #从右边第二个数开始往左
        x=0 #列表中大于L值的数的索引
        while r<=len(nums):
            if nums[-r]<nums[-r+1]:
                is_max = 0
                for i in nums[-r+1:]:
                    if i > nums[-r]:#因为后面的数中每一次都是升序排列的结果，所以第一个比L值大的就是比L大的数中最小的
                        x=nums[-r+1:].index(i)-r+1
                    else:
                        break
                nums[-r],nums[x]=nums[x],nums[-r]#交换值
                nums[-r+1:]=sorted(nums[-r+1:])#升序排列后面的
                return nums #原来为break
            r+=1
        return is_max #原来为if is_max:
                            #nums.sort()
```

##### 针对本题
31题的思想前面已经说过了，那么：
1. 该程序是否适用本题呢？
2. 若不适用，要怎么修改呢？

答案是可以！注意前面图中所讲到的原则：
```
L<R时，将R及以后的数中*比L大的、最小的数*移动到L位置，*列表内再升序排列*即可得到下一排列。
```
这样不管某个数字重复几次，都不会影响程序。


# 4.见缝插数——[22题](https://leetcode-cn.com/problems/generate-parentheses/)
##### 针对46题
我当时随意的写了第一个题解[见缝插括号](https://leetcode-cn.com/problems/generate-parentheses/solution/5xing-python-by-chun-meng-da-xiao-yang/)，当时主要是感叹那一种pythonic写法的简洁和巧妙，现在这一题又用上了它的思想，而且与前面两个算法相比，可以算是最简单易懂易实现的了。主要思想就是以第一个数为基准，在它的两边分别插入第二个数，将结果保存；再以刚刚的结果为基准，数的左右插入第三个数，以此类推即可得到所有的解。看gif比较好理解：
![9.gif](https://pic.leetcode-cn.com/1117356ac347f60b90f49f448fd47732dafebb9decbe7fef909f03f4f03b9a95-9.gif)
```python []
class Solution:
    def permute(self, nums): 
        res = [[nums[0]]]
        tem = []
        n = len(nums)
        for i in range(1,n):
            for k in res:
                for j in range(len(k)+1):
                    k.insert(j,nums[i])#在索引为j的位置插入元素
                    tem.append(k[:])
                    k.pop(j)#删除索引为j的元素
            res=tem
            tem=[]
        return res
```
##### 针对本题
很明显，这种方法对`nums=[1,1,2]`来说会产生大量的重复解，但是解决办法也很简单，在append入res之前检查一下该结果是否已经存在，存在则跳过，不存在则加入即可。
![11.gif](https://pic.leetcode-cn.com/ccf29d6b05739e5499cf55dc87cb0644c1dcdf7ea8981c4f643e11f5103038f0-11.gif)

```
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = [[nums[0]]]
        tem = []
        n = len(nums)
        for i in range(1,n):
            for k in res:
                for j in range(len(k)+1):
                    k.insert(j,nums[i])#在索引为j的位置插入元素
                    if k[:] not in tem: #去重
                        tem.append(k[:])
                    k.pop(j)#删除索引为j的元素
            res=tem
            tem=[]
        return res
```
# 总结
*`做题不是目的，目的是通过做题锻炼思维、掌握常用的算法。
——蠢萌哒小洋`*

不要做过了就忘了，要变成你自己的。

# 其他
如果有缘的话，大家也可以看到我在[其他一些题目下面写的题解](https://leetcode-cn.com/profile/articles/)，同样都是以`超强gif助你理解使用...`开头的，我坚信**能用图说明白的绝不用嘴BB**，而且图片更直观形象，动画能更好的反应程序是怎么执行的、某个变量如何获取、它下一步到哪去了等等。做gif还是挺耗时间和精力的，上面这三个就做了一下午，尤其第一个gif最耗时间，导致第2、3个都没怎么美化了。所以大家要是喜欢的话记得点赞或者关注，当然**有什么建议也可以评论**，我会听的！才怪😜

有童鞋问我gif是怎么做的，我用的是**1.激活版** **2.PowerPoint365/其他*最新版*PowerPoint**，两个条件缺一不可。然后用Gif录制工具录下来的。
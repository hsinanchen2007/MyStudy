### 解题思路

这是整体的一个部分思考图，（整体又部分，我是有什么疾病吗。。。）
![image.png](https://pic.leetcode-cn.com/acf09d8349547a138e843bba90dbb82a59d10185e2c183f9d7e10af0e8de16a0-image.png)

但是！！！**一定要加粗：在我写了好几道（我是有多骄傲）回溯题之后，毅然发现，回溯题一定要画图，画图简直是天助**

接下来，我还是写一下我最近写回溯题的笔记吧，毕竟我之前真的是完全不能理解。。。看了很多套路模板都不如自己认真思考总结来得好
【等我哪天一定整理一下把写过的回溯题step by step（题by题）的写在一个题解里！[立flag，坐等】

### 回溯的思路

对我来说，基于**画图**，再次加粗，回溯题一定要考虑的问题是以下几个方面：
```
1.有效结果：什么时候这算是一个答案，应该被加入到答案列表里
2.回溯的范围：我们下一个维度要考虑如何将当前层的答案和上一层的答案结合，并继续递归
3.剪枝条件：是不是存在某些情况遇到了之后就不需要再处理了
```

对于以上几个问题，我们需要以下几个变量

- 1. **self.res**: 用来保存全部的答案，即整体的答案列表
  **sol**: 每一次的有效结果，某一个符合条件的答案
- 2.  2.1回溯范围需要是全部遍历，还是部分范围遍历 2.2答案如何累加
- 3. **check**：这是一个list，初始为0，当某个元素被用过，则改为1，
  这是因为在回溯里面主要的思路是**搜索尝试过程中寻找问题的解，当发现已不满足求解条件时，就“回溯”返回，尝试别的路径**
  那么就需要一个数组来记录用过的元素，避免陷入死循环

### 整体考虑
这是一个全排列的题【为什么现在才看题目，我是不是真的有什么疾病。。。】
`全排列，每个元素只用一次，每个**有效结果**都包含全部元素，不同顺序代表不同答案`

因为每个**有效结果**都包含全部元素，那么我们就知道**第二个问题2.1**，回溯范围，肯定是全部遍历，即为`for i in range(len(nums))`，又是全部遍历，但是每个元素只用一次，那就又知道了**第三个问题**，剪枝条件：当某个元素用过了，那下一层就不会再使用了，即为`if check[i]: continue`，`并且需要注意的是，check的更新，用于记录使用过的元素，那么在backtrack之前，需要把当前元素的check值改为1，标记为使用过，等到backtrack结束后，需要把check的值改回为0，这样不影响其他搜索对于这个元素的判断`，即为：
```
check[i] = 1
self.backtrack()
check[i] = 0
```


既然是遍历，那么一次都能拿到一个元素，每一层的新元素都应该和上一层的累计结果相结合，update为更新的结果，也就是我们的**第二个问题2.2**，如何累加答案：即为`sol+[nums[i]]`(这里有一个小的trick，占坑等下写)
答案一直累加，那总得有个结束的时候吧，那什么时候结束呢，也就是我们的**第一个问题**，什么时候是一个有效结果，当然当我们的sol的长度==nums的长度的时候，就说明我结束一次搜索，并且是一个有效的结果，即为`if len(sol) == len(nums): self.res.append(sol)`


### 层by层的考虑 eg：[1,2,3]
#### 1.第一层：也就是全排列解的第一个值
这个值可以从（1,2,3）中选择：
![image.png](https://pic.leetcode-cn.com/f0c3c9c0e0e0da44d33adf060e69dfd361d1d80a1066ea600ac96d47a6871621-image.png)
此时有三种情况，我们继续看第一种情况，即当`i`选择第0个元素也就是1的时候，此时`sol=[1]，check=[1,0,0]`：
继续搜索，因为还没有到有效结果的结束条件，下一层，仍然有三种情况，(1,2,3)，但是此时check中显示1这个元素被用过了，于是实际值选择的是(2,3):
![image.png](https://pic.leetcode-cn.com/9d40f06163f51cca36137a78bd8e5f60a00f89377e48c97186b13b7497425408-image.png)

继续回溯搜寻，因为还没有到结束条件：

![image.png](https://pic.leetcode-cn.com/89cfe25c6945803795814a6f6552541d70cb88d8a7ca23c58d07f356721f1001-image.png)



### 总结：回溯类题一定要考虑的几个方面
- **有效结果**：当长度为输入长度的时候停止，并保存当前结果
- **回溯条件**：每一层都是全部元素遍历：例如答案为[2,1,3]时，第二个元素也是从1开始
- **剪枝条件**：要用check数组来保存用过的元素，用过的不能再用了，**这是回溯里面的一个重要考虑因素**


### Trick
在前面有说在回溯（累加结果）的时候，用如下方式：
```
check[i] = 1
self.backtrack(sol+[nums[i]], nums, check)
check[i] = 0
```

其中check的更改是为了在回溯前改变当前使用元素的记录情况，但是在回溯结束之后，调用栈回到上一层，需要将使用元素的状态改回为0，因为下一个回溯搜索的时候这个元素其实是未使用状态，这样就表明了：在回溯中，修改过的元素在递归调用一层结束之后，都要恢复至原装，那么意味着我们是sol其实也应该修改回没有添加当前元素的状态
那么`sol+[nums[i]]`就是一个避免手动更改的小trick，回到上一层的`sol`其实就是`sol`，当然我们也可以sol.append(nums[i])，然后在回溯后`sol.pop()`，但是要**注意list是可变对象**，我们在保存结果的时候是`self.res.append(sol)`，那么在回溯之后的`sol.pop()`会影响`self.res.append(sol)`处的`sol`，如果要用`append+pop`处理`sol`，那么保存结果的时候就必须用`self.res.append(sol.copy())`
```
if len(sol) == len(nums):
    self.res.append(sol.copy())
    return
for i in range(len(nums)):
    if check[i] == 1:
        continue
    check[i] = 1
    sol.append(nums[i])
    self.backtrack(sol+[nums[i]], nums, check)
    sol.pop()
    check[i] = 0
```

#### 附：可变对象
```
>> a=[1,2,3]
>> b=a
>> c=a.copy()
>> a.append(4)
>> a
[1, 2, 3, 4]
>> b
[1, 2, 3, 4]
>> c
[1, 2, 3]
```

于是就可以写出最终的代码：

### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.res = []
        
        check = [0 for i in range(len(nums))]
        self.backtrack([], nums, check)
        
        return self.res
    
    def backtrack(self, sol, nums, check):
        if len(sol) == len(nums):
            self.res.append(sol)
            return
        
        for i in range(len(nums)):
            if check[i] == 1:
                continue
            check[i] = 1
            self.backtrack(sol+[nums[i]], nums, check)
            check[i] = 0
```
![image.png](https://pic.leetcode-cn.com/1262667921405c0227dc68c112be9aa896b536212fc14297f1e5851d037519ae-image.png)



我真的需要学习如何表达，而且不能间隔太久，写完题不马上写题解之后简直是nightmare！！！

#### 另：FLAG
2020年1月10日，工作452天，我（第N次，划掉重来）第finally次决定我要继续读博，并愿意为此努力。



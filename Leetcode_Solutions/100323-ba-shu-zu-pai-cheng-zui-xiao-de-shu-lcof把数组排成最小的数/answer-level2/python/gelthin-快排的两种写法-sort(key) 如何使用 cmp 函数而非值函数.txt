### 解题思路

排序： 如果 x+y < y+x, 那么 x 应该放在 y 前面


#### 1. 如何利用 sort() or sorted() 的 key 接入 cmp 函数，而非值函数？
原以为key是基于值比较，compare的思路没法用，但是有两位大神还是提供了解决方法。

1. [使用key = functools.cmp_to_key](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/mian-shi-ti-45-ba-shu-zu-pai-cheng-zui-xiao-de-s-4/)
``` python3 
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        def sort_rule(x, y):
            a, b = x + y, y + x
            if a > b: return 1
            elif a < b: return -1
            else: return 0
        
        strs = [str(num) for num in nums]
        strs.sort(key = functools.cmp_to_key(sort_rule))
        return ''.join(strs)
```
2. [定义一个新的类](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/python3jian-dan-chu-li-by-bigkjp97/) 这个是真的强，没看懂。

``` python3
class cmpSmaller(str):
    def __lt__(self, y):
        return self + y < y + self  # 字符串拼接比较(两两比较)
    # 按由小到大来排列

class Solution:
    def minNumber(self, nums: List[int]) -> str:
        res=sorted(map(str, nums),key=cmpSmaller)
        smallest = ''.join(res)
        return smallest
```
原本是 key = f, 然后比较 f(x)< f(y)。这里 key = cmpSmaller, cmpSmaller(x) 相当于重载了 x 元素的比较运算 '<', x'<'y  <=> x+y < y+x 。

#### 2. 如果不用 python3 的 sort key，自己写一个快排。
我自己的前期的快排代码来自于 [面试题40. 最小的k个数-快排-partition-这题需要反复做](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/solution/gelthin-kuai-pai-partition-by-gelthin/), 总结了 huangyu 老师课上所讲的快排，和自己[从 ACM 模板中看来的快排](https://github.com/matthewsamuel95/ACM-ICPC-Algorithms/blob/master/Sorting/QuickSort/python/QuickSort.py)。

[大佬的快排](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/mian-shi-ti-45-ba-shu-zu-pai-cheng-zui-xiao-de-s-4/)和 我的快排方式 完全不一样。其使用了三个 while循环,我的提问[引出了如下回复](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/mian-shi-ti-45-ba-shu-zu-pai-cheng-zui-xiao-de-s-4/334043)：其比较代码如下:  [算法导论-快速排序](https://www.cnblogs.com/mengwang024/p/4294525.html)

``` python3  
def partition(nums, int low, int high) # 这个代码和 huangyu 老师上课所讲的代码很像, 但更简单一点。都是[low, high]，但 huangyu 老师的代码构造了空洞的概念，找到了就 break(return)。 
    key = nums[low] # 这个 key 选定了永远就是这个了, 这里也可以换为 nums[high], 只需要下面 while 循环调一下位置
    while low < high:

        while low < high and key <= nums[high]:
            high -=1
        nums[low] = nums[high]

        while low < high and key >= nums[low]:
            low += 1
        nums[high] = nums[low]

    nums[low] = key
    return low

def partition(nums, left, right): # [left, right]  # 这是我自己常用的代码，来自于ACM 模板
    x = nums[right]
    i = left
    for j in range(left, right): # 不考虑 right
        if lower(nums[j], x):
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
    nums[i], nums[right] = nums[right], nums[i]
    return i

def partition(nums, left, right): # [left, right]   童老师课上稍微讲稍有一些不同
    x = nums[right]
    i = left - 1  # 这里初始化为 left-1
    for j in range(left, right): # 不考虑 right
        if lower(nums[j], x):
            i += 1
            nums[i], nums[j] = nums[j], nums[i]
    i += 1  # 这里还需要加 1
    nums[i], nums[right] = nums[right], nums[i]
    return i

```  

#### 3. 问题变体，是否允许前导 0？
+ 本题允许：拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0     
+ 但对 [面试题46. 把数字翻译成字符串](https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/gelthin-dp-shu-lou-ti-by-gelthin/)，如果有一个数是 0。不能放在最前面，用 DP 数楼梯，构造数值种数碰到过此    
如果本题也不允许前导 0，就比较麻烦。可以先按照允许前导 0 进行排序， 然后把排序后的数组中第一个非 0 数换到第一位，其他数一次挪后一位，应该就可以了。

### 代码

```python3
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        # 这一个题目就比较有意思
        def lower(x, y):  # x, y 可以有一个为 0
            if int(str(x)+str(y)) <= int(str(y) + str(x)):
                return True 
            else:
                return False

        def partition(nums, left, right): # [left, right]
            x = nums[right]
            i = left
            for j in range(left, right): # 不考虑 right
                if lower(nums[j], x):
                    nums[i], nums[j] = nums[j], nums[i]
                    i += 1
            nums[i], nums[right] = nums[right], nums[i]
            return i
        
        def quick_sort(nums, left, right):
            if left >= right:
                return
            ind = partition(nums, left, right)
            quick_sort(nums, left, ind-1)
            quick_sort(nums, ind+1, right)

        # python sort 的 key 对应的 不是 compare 函数，而是一个处理输出值函数，然后在比较这个值函数的结果
        # nums.sort(key=my_lower)
        quick_sort(nums, 0, len(nums)-1)

        return "".join(str(x) for x in nums)

        
```


拿到这个题，其实我是从[437.路径总和 III](https://leetcode-cn.com/problems/path-sum-iii/solution/hot-100-437lu-jing-zong-he-iii-python3-li-jie-di-g/)来的，结果437easy我还是觉得很迷惑，当然这道题我也是看了好久好久。。而且好多人的答案我其实第一次没有看懂，于是自己记录一下从暴力到优化之后的心路过程：
（好久没有写题解很羞愧。。今天又有一个朋友关注了我，很开心，还是要坚持下去！）

### 1.传统暴力解法

那我们还是从题目看起来：
![image.png](https://pic.leetcode-cn.com/b9e0d4be9c802b090755d8f44cbaaef54cd9c059e018ab168f0e29346f62896a-image.png)

画出图来就好比这样：
![image.png](https://pic.leetcode-cn.com/ac4c5f1ff3d102c0bdf76564c9ae866bcd5312133668bc339c34ff1d83d89945-image.png)

于是就可以有我们暴力解法的思路：
![image.png](https://pic.leetcode-cn.com/7108f32efaab9707f8f2e86f6f00ad561d075c41c0fd34d22d61c6ed7baa30e9-image.png)

那么`i可以从0到len(nums)-1，j可以从i到len(nums)-1，ij的总和需要从i到j`，也就可以写出我们暴力的方法：

### Brute force

![image.png](https://pic.leetcode-cn.com/a8d303990b57b2f04b5863f69e0d0db4870766c25a13bfae0c3f178c4480dab3-image.png)

但是我看到3个for就害怕，提交果然是**Time Limit Exceeded**
此时**Time：O(n^3), Space：O(1)**
那么怎么优化呢？


### 2.用prefixSum记录前一个总和的状态

暴力解法里面的蓝色代码部分，其实是在累加从i到j之间的数的总和，那么我能不能**用一个prefixSum的变量每次更新我之前所有数的总和**，这样我**不需要每次都遍历从i到j的数，只需要**`prefixSum + currentNum`，从而将这个O(n)的遍历缩小为O(1)的操作：
![image.png](https://pic.leetcode-cn.com/26b52e4fe0a26ea05413aae2bb7f254dcefd7497c6914b9a993d7624e1904370-image.png)

于是就可以对代码做如下的优化，**在计算`0-i`的总和时可以看做是`0-(i-1)的总和+nums[i]`**
![image.png](https://pic.leetcode-cn.com/9a39d40f75dcf011660a2f710422377e9d898c9f2e0f1f81d0812db83b80b33a-image.png)

我们就把三个遍历减少到两层遍历
此时**Time：O(n^2), Space：O(1)**
但是仍然是**Time Limit Exceeded**，还能不能继续优化呢？

### 3.用prefixSumArray保存prefixSum

方法2里面标出来的几行，其实做的事情是：
![image.png](https://pic.leetcode-cn.com/af1a5b3671bd907c06d7034f83e886960f9484287e4b981ac8de1bc6b44bed82-image.png)
![image.png](https://pic.leetcode-cn.com/6c82275c444e4509d370b75deffd03b59b330e8311f6861994e5330d4b7eba84-image.png)
于是很容易能得到
`subArray(i,j)的总和（也就是k） = prefixSum[j] - prefixSum[i]`
转换为：**`prefixSum[i] = prefixSum[j] - k`**
以及先遍历i，那么i在j前面，k已知，那么就可以有点类似于`2sum`的题，当我拿到`prefixSum[j]`的值的时候，我去检查曾经是否有`prefixSum[j]-k`也就是`prefixSum[i]`出现过，如果出现过，就说明`存在从prefixSum[i]到prefixSum[j]的距离为k的情况`

**那么这个曾经是否出现过要如何判断呢，当然是**hash table**保存啦。那如何更新这个hash table呢，当然是每次获得一个prefixSum，就存进去，如果表里没有这个key，那么value设置为1，否则value+=1**

但是我们这里有个小tip：
**初始化hash table的时候，要初始化为{0:1}**，然后用prefixSum来更新

![image.png](https://pic.leetcode-cn.com/35da11e658bbaa3d9a40b56997c7fe3f8ab77b47a506a0d9eb4d3ac8a297627f-image.png)

可以考虑为：
![image.png](https://pic.leetcode-cn.com/1e3d67d3afbc9e7a9201e48d046b5d0e775989e9c3084d576aa79ddd0d418f28-image.png)

于是就可以写出如下代码：
![image.png](https://pic.leetcode-cn.com/875a3c356e9fcc2a38fd9abf931253d12c8e8789467df2ef6bf563b17b0dca38-image.png)


### 代码

```
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefixSumArray = {0:1}
        count = 0
        prefixSum = 0
        
        for ele in nums:
            prefixSum += ele
            subArray = prefixSum - k
            
            if subArray in prefixSumArray:
                count += prefixSumArray[subArray]
            '''
            prefixSumArray.get(prefixSum, 0)
            在hash table里查找key，如果有返回对应的value，反之返回0 
            '''
            prefixSumArray[prefixSum] = prefixSumArray.get(prefixSum, 0) + 1
        
        return count
                    
```

这样我们就将对j的O(n)的遍历简化为O(1)的操作，但是额外添加hash tale的O(n)的空间，相当于用空间换时间，达到最后：**Time: O(n), Space: O(n)**的结果



### 反思：
要想获得自己的生活，一定要更要有底气。
要加油，要找到那个更完整的自己。
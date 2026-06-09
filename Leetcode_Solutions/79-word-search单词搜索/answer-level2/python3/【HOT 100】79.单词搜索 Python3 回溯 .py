### 解题思路
- 相似题型
- 回溯三要素
- 代码

### 相似题型
[46.全排列](https://leetcode-cn.com/problems/permutations/solution/hot-100-46quan-pai-lie-python3-hui-su-step-by-step/)
[47.全排列II](https://leetcode-cn.com/problems/permutations-ii/solution/hot-100-47quan-pai-lie-ii-python3-hui-su-kao-lu-zh/)
[78.子集](https://leetcode-cn.com/problems/subsets/solution/hot-100-78zi-ji-python3-hui-su-liang-chong-jie-ti-/)
[90.子集II](https://leetcode-cn.com/problems/subsets-ii/solution/hot-100-90zi-ji-ii-python3-hui-su-kao-lu-zhong-fu-/)
[22.括号生成](https://leetcode-cn.com/problems/generate-parentheses/solution/hot-100-22gua-hao-sheng-cheng-python3-hui-su-kao-2/)
[39.组合总和](https://leetcode-cn.com/problems/combination-sum/solution/hot-100-39zu-he-zong-he-python3-hui-su-kao-lu-jian/)
[40.组合总和II](https://leetcode-cn.com/problems/combination-sum-ii/solution/hot-100-40zu-he-zong-he-ii-python3-hui-su-by-sammy/)
[17.电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/hot-100-17dian-hua-hao-ma-de-zi-mu-zu-he-by-sammy-/)


### 回溯三要素
这依然是一个回溯法解决的典型题，但是区别在于这是第一次遇到的二维数组的输入，往常我们只需要考虑一维数组，从第一个元素开始，最多往两个方向去搜索，而这道题，有四个方向可以搜索，并且它的答案不仅限于从第一个元素开始，而是**可以任选一个格子作为word的起点**，这就又是一个**trick：我们第一次需要在主函数内也进行循环搜索**

然后这是一个判断word是否匹配的问题，其实也就是判断一段回溯搜索的路径是否等于这个word的问题，又是一个小**trick：在遇到sum或者sumPath的回溯问题，我们不一定要用sum累加来判断，我们也可以用target减去当前的元素或元素值，如果最终target=0或者target为空了，就说明找到了一个有效结果**，这道题我们也是一样的，尤其是虽然有四个方向的搜索可能，但是如果当前的元素根本不等于word里我想要的那个元素的话，我就根本不需要继续搜索了，于是可以进行剪枝，如果当前元素等于word里我想要的那个元素，那么我再考虑往它的四个方向去继续搜索，并且传入的word要更新，也就是word[1:]，因为首字母已经匹配过了，一直重复这个过程直到word上的所有字母都能在二维数组里找到对应的位置。

那么我们可以考虑一下回溯三要素：

- **有效结果**
如果`word`最终为空，说明已经将`word`上的所有字母都能在二维数组里找到对应的位置，也就是在矩阵中找到了匹配的`word`，应当返回`True`，但是这道题不是找所有答案，而是返回`True/False`，那么我们可以将`backtrack`函数的返回值设为`True/False`，就不再像之前那样更新`self.res`，这样的话，这个函数必须要在最后返回`False`，也就是`else`的部分：

```
if not word:
    return True
...
return False
```

- **回溯范围及答案更新**
我们需要让回溯题简洁，那么我们在每一次的回溯搜索中只考虑当前层的`check`改变，以及当前层的剪枝等，这里我们会有四个方向可以继续搜索，但是我们对于check的修改，我们依然只考虑当前点，不考虑四个方向：
```
check[i][j] = 1
if self.backtrack(i-1, j, board, word[1:], check) or \
   self.backtrack(i+1, j, board, word[1:], check) or \
   self.backtrack(i, j-1, board, word[1:], check) or \
   self.backtrack(i, j+1, board, word[1:], check):
    return True
check[i][j] = 0
```

- **剪枝条件**
因为我们有四个方向，而且都可以走，那么就要考虑边界的问题，如**ij横纵坐标**，那如果`ij小于0了肯定不行`，`ij大于等于横纵的长度了也不行`，`当前元素被用过了也不行`，`当前元素不等于word当前的元素肯定更不行`：这一个元素都对错了之后的肯定更不行了，于是这里有**6**个剪枝条件，**又由于是返回T/F，那么直接设置为False，不再继续回溯**：
```
if i<0 or j<0 or i>= len(board) or j>= len(board[0]) or check[i][j] == 1 or word[0] != board[i][j]:
    return False
```

#### 考虑主函数
之前的一维数组的回溯题我们不需要怎么考虑主函数，无非是初始化的部分，然后调用一次主函数，然后返回解集，但是这里有小小的不同，也在回溯三要素里第一段就说了：
它的答案不仅限于从第一个元素开始，而是**可以任选一个格子作为word的起点**，于是**我们第一次需要在主函数内也进行循环搜索**，并且`只要有一个True的答案了，我们就返回结果True，否则如果所有元素遍历完全都没有T，那么再返回False`：
```
for i in range(rows):
    for j in range(cols):
        if self.backtrack(i, j, board, word, check):
            return True
return False
```




### 代码


```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        rows = len(board)
        cols = len(board[0])
        check = [[0 for i in range(cols)] for j in range(rows)]
        
        for i in range(rows):
            for j in range(cols):
                if self.backtrack(i, j, board, word, check):
                    return True
        return False
        
    
    def backtrack(self, i, j, board, word, check):
        if not word:
            return True
        
        if i<0 or j<0 or i>= len(board) or j>= len(board[0]) or check[i][j] == 1 or word[0] != board[i][j]:
            return False
        
        check[i][j] = 1
        if self.backtrack(i-1, j, board, word[1:], check) or self.backtrack(i+1, j, board, word[1:], check) or self.backtrack(i, j-1, board, word[1:], check) or self.backtrack(i, j+1, board, word[1:], check):
            return True
        check[i][j] = 0
        
        return False
        
```

### 叹息
No. 35973
！回溯题一定要简洁，要剪枝，不然会TLE，然后就是每天再多背点单词，时间不多了，年龄也很大了，要想追求一些更多的价值不能只是说说，而需要加倍努力啊！（这句话打成了“要想追求一些更多的价值不能只是硕士，而需要加班”）【好像也没错哈哈。。。逃】
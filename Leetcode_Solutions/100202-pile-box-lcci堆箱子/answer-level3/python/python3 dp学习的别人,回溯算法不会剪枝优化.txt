### 解题思路
此处撰写解题思路
dp 摘抄的这位[道友](https://leetcode-cn.com/problems/pile-box-lcci/solution/python3-dong-tai-gui-hua-by-yesohh/)的
没有想到dp,先用的回溯算法，但是超时了，想着优化剪枝，但是看题解里面好像没看到类似的，用的记忆化数组，这个不太会，下面自己写的回溯只通过了18个案例，卡在第19个，特别长的那个，
可以学习学习dp的，比较简单，python碰到着类似的题目还是没法暴力破解的。。。

其实这个dp还是好理解的。dp[i]代表以第 i 个箱子放在最底下的最大高度，不是说就是前i个box的叠加符合要求的最大高度。 
所以最后需要返回的是 max(dp)

[[1, 1, 1], [2, 3, 8], [2, 6, 7], [3, 4, 5]]
排序之后还是原来的样子
求得dp 表如下。
[1, 9, 8, 6]

### 代码

```python3
class Solution:
    def pileBox(self, box: List[List[int]]) -> int:
        # box.sort(reverse=True)

        # print(box)
        # self.ans = 0
        # def helper(box,res=[[float('inf')]*3]):
        #     if not box:
        #         temp = 0
        #         for b in range(1,len(res)):
        #             temp+=res[b][-1]
        #         self.ans = max(self.ans,temp)

        #     for i in range(len(box)):
        #         if box[i][0]<res[-1][0] and box[i][1]<res[-1][1] and box[i][2]<res[-1][2]:
        #             res.append(box[i])
        #             helper(box[i+1:],res)
        #             res.pop()
        #         # else:
        #             # continue  # 出现那种后面存在不符合添加的方块，但是box不为空，所以没有返回值
        #             # 下面这段放在else里面，或者for外面都是超时的，不过都是正确的应该。
        #             # 想想如何剪枝？
        #     temp = 0
        #     for b in range(1,len(res)):
        #         temp+=res[b][-1]
        #     self.ans = max(self.ans,temp)
        
        # helper(box)
        # return self.ans

        dp = [0 for _ in range(len(box))]
        box.sort()

        for i in range(len(box)):
            dp[i] = box[i][2]
            for j in range(i):
                if box[j][0] < box[i][0] and box[j][1] < box[i][1] and box[j][2] < box[i][2]:
                    dp[i] = max(dp[i], dp[j] + box[i][2])
        return max(dp)



```
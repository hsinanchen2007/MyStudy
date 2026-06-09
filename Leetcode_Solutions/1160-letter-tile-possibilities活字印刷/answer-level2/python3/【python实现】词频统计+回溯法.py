解题思路：
1、题目要求的是返回所有可行的组合的数量，
一个可行的组合：在 输入的字符串 里抽取 若干个字母 按 不同的顺序 组成的
因此，输入的字符串中相同的字母是没有区别的，所以可以用词频统计的方法，就可以知道所有字母出现的次数
2、每次都在词频库里拿出一个字母构成一个可行组合，并用递归的方式来拿，拿完了就返回到上一步，这就是回溯的思想。

解题方法：词频统计+回溯
1、先统计输入字符串的词频
①用collections.Count（str）
②用for循环
第②种速度更快


2、回溯算法
    a.遍历所有可拿的情况
        剪枝：如果有不符合的情况，则跳过
    b.计数更新、词频更新
    c.递归：将更新完的词频传入到下一层中；并利用递归的返回来计数，这样就相当于进行了多少次递归，就有多少计数。
    d.回溯：把上一步的词频更新退回去

以下展示利用for循环的词频统计方法
![1.png](https://pic.leetcode-cn.com/c1e532f0411bdcb084514744fc00a8e2b104cea6fc91b5f3fbb2f12a34b7c991-1.png)
```
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        # 边界条件判断
        if not tiles:
            return 0
        # 词频统计
        freq = {}
        for c in tiles:
            if c in freq:
                freq[c] += 1
            else:
                freq[c] = 1

        def backtracking(freq):
            res = 0
            for k, i in freq.items():
                # 剪枝：当一个字母的频率为0，
                # 则表示已经用完了，应该跳过它并继续遍历下一个字母
                if i - 1 < 0:
                    continue
                res += 1  # 计数+1
                freq[k] -= 1  # 字母k消耗1次
                # 递归
                # 因为python是按引用传参，因此需要利用递归的返回值来保存计数结果
                res += backtracking(freq)

                # 回溯
                freq[k] += 1  # 还原上一步的状态：字母k频率加1
            return res

        res = backtracking( freq)

        return res
```

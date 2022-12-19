这一题其实和第123题-买卖股票的最佳时机III很像，都是用正序和逆序两次遍历来求解最佳答案，之前很少接触此种解法，觉得甚是奇妙。各位读者如果有对第123题-买卖股票的最佳时机III不是很熟悉的朋友，可以先看看我写的那篇文章。
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/123-mai-mai-gu-piao-de-zui-jia-shi-ji-python-by-fe/
此题的解法步骤是：
```
1. 首先给每个孩子分配一颗糖果，用candy_list数组来保存
2. 正向调整，如果当前孩子比之前孩子的分数高，
   那么令当前孩子的糖果数比之前孩子糖果数大1 res[i]=res[i-1]+1；
3. 反向调整，如果当前孩子比之前孩子的分数高，
   那么比较当前孩子的糖果数和之前孩子的糖果数+1，
   取更大的为当前孩子糖果数res[i]=max(res[i],res[i+1]+1)；
```
第二次遍历的时候会更新最终的值，真的很奇妙。后面我应该会专门写篇文章来介绍这种方法，大家敬请期待哈哈哈哈哈哈。

代码如下：
```Python
class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        # 首先给每个孩子分配一颗糖果
        candy_list = [1]*len(ratings)
        candy_list.insert(0, 0)
        candy_list.append(0)
        # 首尾加上0，方便遍历首尾元素
        ratings.insert(0, 0)
        ratings.append(0)
        # 正向调整，如果当前孩子比之前孩子的分数高，
        # 那么令当前孩子的糖果数比之前孩子糖果数大1 res[i]=res[i-1]+1；
        for start in range(1, len(ratings)-1):
            if ratings[start] > ratings[start-1]:
                candy_list[start] = candy_list[start-1]+1
        # 反向调整，如果当前孩子比之前孩子的分数高，
        # 那么比较当前孩子的糖果数和之前孩子的糖果数+1，
        # 取更大的为当前孩子糖果数res[i]=max(res[i],res[i+1]+1)；
        for end in range(len(ratings)-2, 0, -1):
            if ratings[end] > ratings[end+1]:
                candy_list[end] = max(candy_list[end], candy_list[end+1]+1)
        return sum(candy_list)


if __name__ == "__main__":
    ratings = [1, 2, 2]
    candy_num = Solution().candy(ratings)
    print(candy_num)
```
执行效率还算不错，达到了60%
![image.png](https://pic.leetcode-cn.com/6ddd5a50871f5800fa70d88d5bf3284ea40236c0794ea76041499d70f9521c49-image.png)

大家要是有更好的方法，也希望积极留言啊！！！
# 等差数列我都会，但是真的得好好把所有的未知数和变量名好好梳理一下，不然写到后面真是痛不欲生。
# 等差数列的方法需要大量公式进行解释，限于时间就跳过去吧。

# （其实我觉得暴力法更好，就算数据量大一些，也是机器算完了，我连公示都没有推导完😢）

# ```py
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        # 快速生成相同元素的 List
        res = [0] * num_people
        # 记录糖果数量并且在取模之后可以用作list 的索引
        index = 0
        
        while candies > 0:
            # 使用 min() 快速判断糖果数量
            res[index % num_people] += min(candies, index+1)
            candies -= min(candies, index+1)
            # 糖果数加一
            index += 1
        return res
# ```

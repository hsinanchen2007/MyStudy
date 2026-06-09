### 解题思路
这题的意思是，让solution里面的颜色和guess的颜色进行两两配对：如果配对的颜色位置是相同的，算一次猜中；如果位置不同，则算一次伪猜中
solution ----------R G R B----------
guess    ----------B B B Y----------
来看这个示例，solution中的最后一个B对位不是B，但它可以和guess中的第一个B（或任意一个B）配对，组成一次伪猜中。剩下俩B由于没有可以配对的，都没法算作伪猜中，因此答案是[0,1]
ok,也就是说完全猜中的优先级更高，如果猜中了，那么它就不能先看作是伪猜中，于是思路就来了
1、对solution中的四个颜色的数量进行统计。
2、遍历两个字符串，将完全匹配的位置记录下来，让对应颜色的计数减一说明它已经被配对了。
这里用一个列表来记录，比如[1,1,0,1]'1'就表示这个位置是完全配对的
3、对刚刚的位置列表中为0的位置进行遍历，检查guess[i]对应的颜色在solution中还有没有没用完剩的。如果有，记做一次伪猜中，并且对应颜色的计数减一

### 代码

```python3
class Solution:
    def masterMind(self, solution: str, guess: str) -> List[int]:
        #思路：过两关即可
        res = [0,0]
        #看伪猜中不能多次计算
        color_dict = {'R':0,'G':0,'B':0,'Y':0}
        for i in range(4):
            color_dict[solution[i]] += 1
        correc_list = [0] * 4
        for i in range(4):
            if guess[i] == solution[i]:
                res[0] += 1
                color_dict[guess[i]] -= 1
                correc_list[i] = 1
        for i in range(4):
            if correc_list[i] == 0:
                if color_dict[guess[i]] != 0:
                    res[1] += 1
                    color_dict[guess[i]] -= 1
        return res


```
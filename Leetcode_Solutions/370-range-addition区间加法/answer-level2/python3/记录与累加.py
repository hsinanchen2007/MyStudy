官方题解的区间求和方法的python版，做了一些注释说明。
```
class Solution():
    def getModifiedArray(self, length: int, updates: List[List[int]]) -> List[int]:
            ans = [0] * (length + 1)
            for update in updates:
                ans[update[0]] += update[2] #从这个索引开始，后面的所有元素都将会被增加update[2]
                ans[update[1]+1] -= update[2] #但是，不在这一区间的元素本不应该被增加update[2]，所以这一区间之后的元素都设置会被减去update[2]
            for k in range(1, length):
                ans[k] += ans[k-1] #把上面的设置累加起来
            return ans[:length] #最后一个元素只是辅助的
```

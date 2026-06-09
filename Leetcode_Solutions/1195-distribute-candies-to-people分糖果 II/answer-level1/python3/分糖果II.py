### 解题思路
此处撰写解题思路
循环累加+判断剩下的够不够分给下一个小朋友。这里用取余来完成n个小朋友来回地分糖果（参考官方）

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        #官方解答
        #ans = [0] * num_people
        # i = 0
        # while candies != 0:
        #     ans[i % num_people] += min(i + 1, candies)
        #     candies -= min(i + 1, candies)
        #     i += 1
        # return ans
        
        #我的解答
        candi_list = [0]*num_people#先初始化每人10个
        i = 0
        while candies:
            candi_list[i%num_people] += i+1
            candies -= i+1
            if candies <= i+2:
                candi_list[(i+1)%num_people] +=candies
                break
            i+=1
        
        return candi_list
            

```
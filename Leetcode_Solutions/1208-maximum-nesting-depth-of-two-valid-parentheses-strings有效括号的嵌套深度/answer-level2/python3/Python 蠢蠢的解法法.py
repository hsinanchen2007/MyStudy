# 解题思路
1. A与B哪个待配对的左括号少就优先给他加左括号
2. 哪个待配对的左括号多就优先给他分配右括号

# 代码
```
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        answer = []
        sum_of_lb_A = 0
        sum_of_lb_B = 0
        for index in range(len(seq)):
            if seq[index] == ")":
                if sum_of_lb_B >= sum_of_lb_A:
                    answer.append(1)
                    sum_of_lb_B -= 1
                else:
                    answer.append(0)
                    sum_of_lb_A -= 1
            else:
                if sum_of_lb_B > sum_of_lb_A:
                    answer.append(0)
                    sum_of_lb_A += 1
                else:
                    answer.append(1)
                    sum_of_lb_B += 1
                    
        return answer
```



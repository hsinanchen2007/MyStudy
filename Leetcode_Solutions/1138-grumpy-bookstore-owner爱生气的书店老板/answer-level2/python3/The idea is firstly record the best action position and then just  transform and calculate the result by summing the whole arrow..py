```python3
class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        time_len = len(customers)
        max_earn_X = 0
        tmp = 0
        ## record the best action position
        for i in range(time_len-X+1):
            if i == 0:
                for j in range(X):
                    tmp = tmp + grumpy[j]*customers[j]
                action = i
                max_earn_X = tmp
            else:
                tmp = tmp + customers[i+X-1]*grumpy[i+X-1] - customers[i-1]*grumpy[i-1]
                if tmp > max_earn_X:
                    max_earn_X = tmp
                    action = i
        # print(action)
        ## transform and calculate the result by summing the whole arrow.
        for i in range(action,action+X):
            grumpy[i] = 0
        res = 0
        for i in range(time_len):
            res += (1 - grumpy[i])*customers[i]
        return res



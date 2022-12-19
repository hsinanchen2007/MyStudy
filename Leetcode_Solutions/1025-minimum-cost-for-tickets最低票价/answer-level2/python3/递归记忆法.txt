```
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        """
           应该可以用递归可以解决
           每一天我都可以选择三种票期
           
           例如第一天我可以选择买1天票, 7天票, 30天票, 买完每一种票都可以管到对应的天:
           
           例如买了一天期票后, 直接递归 days[1:]
               用了七天期票后, 直接递归到 days中跨度到第7天开始递归
               用了三十天期票后, 直接递归到days中跨度到第30天开始递归
               
               最后这三种取最小值
           
           纯递归, 超时了, 所以可以想一下使用一个数组记忆从某个索引开始的最低消费
        """
        
#         # 1. 直接递归, 会超时
#         if len(days) == 1:
#             return min(costs)
        
#         # 选择一天期票
#         cost_1 = self.mincostTickets(days[1:], costs)
        
#         # 选择七天期票
#         seven_tickit_start = 1
#         for i in range(1, len(days)):
#             if days[i] - days[0] < 7:
#                seven_tickit_start = i + 1
#             else:
#                 break
#         # 停止递归的条件, 总之两种情况最小值
#         if seven_tickit_start == len(days):
#             return min(costs[0] + cost_1, costs[1])
#         else:
#             cost_7 = self.mincostTickets(days[seven_tickit_start:], costs)
        
#         # 选择三十天期票
#         thirty_tickit_start = 1
#         for i in range(1, len(days)):
#             if days[i] - days[0] < 30:
#                thirty_tickit_start = i + 1
#             else:
#                 break
#         # 停止递归的条件, 返回三种情况最小值
#         if thirty_tickit_start == len(days):
#             return min(costs[0] + cost_1, costs[1] + cost_7, costs[2])
#         else:
#             cost_30 = self.mincostTickets(days[thirty_tickit_start:], costs)
        
        
#         return min([costs[0] + cost_1, costs[1] + cost_7, costs[2] + cost_30])
        
        
        # 2. 使用数组记忆 dp[i]表示从i开始一直到结束的序列的最低票价
        dp = [-1] * len(days)
        
        def helper(curr_day, costs, index):
            if len(curr_day) == 1:
                return min(costs)
            # 选择一天期票
            if dp[index + 1] > -1:
                cost_1 = dp[index + 1]
            else:
                cost_1 = helper(curr_day[1:], costs, index + 1)
                dp[index + 1] = cost_1
            
            # 选择七天期票
            seven_tickit_start = 1
            for i in range(1, len(curr_day)):
                if curr_day[i] - curr_day[0] < 7:
                   seven_tickit_start = i + 1
                else:
                    break
            # 停止递归的条件, 总之两种情况最小值
            if seven_tickit_start == len(curr_day):
                return min(costs[0] + cost_1, costs[1])
            else:
                if dp[index + seven_tickit_start] > -1:
                    cost_7 = dp[index + seven_tickit_start]
                else:
                    cost_7 = helper(curr_day[seven_tickit_start:], costs, index + seven_tickit_start)
                    dp[index + seven_tickit_start] = cost_7

            # 选择三十天期票
            thirty_tickit_start = 1
            for i in range(1, len(curr_day)):
                if curr_day[i] - curr_day[0] < 30:
                   thirty_tickit_start = i + 1
                else:
                    break
            # 停止递归的条件, 返回三种情况最小值
            if thirty_tickit_start == len(curr_day):
                return min(costs[0] + cost_1, costs[1] + cost_7, costs[2])
            else:
                if dp[index + thirty_tickit_start] > -1:
                    cost_30 = dp[index + thirty_tickit_start]
                else:
                    cost_30 = helper(curr_day[thirty_tickit_start:], costs, index + thirty_tickit_start)
                    dp[index + thirty_tickit_start] = cost_30

            dp[index] = min([costs[0] + cost_1, costs[1] + cost_7, costs[2] + cost_30])
            
            return min([costs[0] + cost_1, costs[1] + cost_7, costs[2] + cost_30])
        
        return helper(days, costs, 0)
        
```

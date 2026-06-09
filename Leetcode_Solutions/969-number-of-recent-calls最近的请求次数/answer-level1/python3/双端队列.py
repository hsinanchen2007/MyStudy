- 示例解读：分别在1,100,3001,3002ms发出了请求（ping）
- 1ms时计算1ms以及1ms之前3000ms的请求数为‘1’(1ms时的ping)
- 100ms时计算100ms以及100ms之前3000s的请求数为‘2’（1ms时的ping和100ms时的ping）
- 3001ms时计算3001ms以及3001ms之前3000s的请求数为‘3’(1ms时的ping、100ms时的ping和3001ms时的ping)
- 3002ms时计算3002ms以及3002ms之前3000s的请求数为‘3’(100ms时的ping、3001ms时的ping和3002ms时的ping)


        from collections import deque  # 通过collections模块导入双端队列deque
        class RecentCounter:
            def __init__(self):
                self.__pingdeque = deque([])  # 定义一个空双端队列

            def ping(self, t: int) -> int:
                self.__pingdeque.append(t)  # 保存ping的时间点t到队列
                while t-self.__pingdeque[0] > 3000:  # 删除t之前3000ms的时间点 
                    self.__pingdeque.popleft()
                return len(self.__pingdeque)  # 返回队列中剩下的时间节点个数即是t到t之前3000ms的ping的次数

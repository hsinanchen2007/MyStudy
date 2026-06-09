```
        """
           是否是一个有效的树, 实际就是判断: 1)是否具有环状结构 2)是否所有点可达

           思路一: 宽搜，只要搜索到中途已经经过的node, 直接返回False, 否则最后检查所有的点是否都已经遍历. 
                  只要是一颗有效的树, 那么肯定从任意一个点都可以直达其它所有点
           思路二: 使用深搜, 也是一个意思
        """

        # # 方法一, 宽搜
        # if n == 1:
        #     return True
        
        # if len(edges) == 0:
        #     return False
        
        # graph = defaultdict(list)
        # for edge in edges:
        #     graph[edge[0]].append(edge[1])
        #     graph[edge[1]].append(edge[0])
        
        # queue = deque([(0,0)])
        # visited = set()
        # visited.add(0)

        # while queue:
        #     pre_node, curr_node = queue.popleft()
            
        #     next_nodes = graph.get(curr_node)
        #     if next_nodes is None:
        #         return False
            
        #     for node in next_nodes:
        #         # 首先不能走回头路
        #         if node != pre_node:
        #             # 在没走回头路的情况下还重新访问到了同一个点, 说明肯定有环
        #             if node in visited:
        #                 return False
        #             else:
        #                 queue.append((curr_node, node))
        #                 visited.add(node)
            
        # # 判断是否所有的点都访问了
        # if len(visited) < n:
        #     return False
        
        # return True
    
        # 方法二，深搜, 同样不能走回头路
        if n == 1:
            return True
        if len(edges) == 0:
            return False
        visited = set()
        visited.add(0)
        graph = defaultdict(list)
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])
        
        def helper(node, pre_node):
            next_nodes = graph.get(node)
            if next_nodes is None:
                return False
            else:
                for sig_node in next_nodes:
                    if sig_node != pre_node:
                        if sig_node in visited:
                            return False
                        else:
                            visited.add(sig_node)
                            # 非常关键的一点, 如果有回路, 则直接返回错
                            if not helper(sig_node, node):
                                return False
            return True

        if not helper(0,0):
            return False
        else:
            if len(visited) < n:
                return False
            else:
                return True
```

完全的BFS经典模型套用。转化成无向图，根节点（第一层）是一个点'0000'，第二层是8个点，第三层是8*8个点，以此类推。找到target即离根节点最近的点，求最少旋转次数就是求root和target的最短距离。

BFS基本套路：
1. 队列左端顶点弹出为vertex
2. vertex的子节点减去已访问节点（即vertex的下一层可访问节点）是否是target
3. yes则返回计数，no则将此层可访问节点补到队列右端，并将vertex计入下次不可访问集合
4. 直到队列为空，返回无法到达target

`class Solution:

    def openLock(self, deadends: List[str], target: str) -> int:

        self.dead = set(deadends)
        self.start = set(['0000'])-self.dead
        self.target = set([target])-self.dead
        self.count = 0


        def nextPath(nodes:set(['1234'])): ## 生成下一层的所有点 
            rst = set()
            for i in nodes:
                for index in range(4):
                    up = i[:index]+str((int(i[index])+1)%10)+i[index+1:]
                    down = i[:index]+str((int(i[index])-1)%10)+i[index+1:]
                    rst.add(up)
                    rst.add(down)
            return rst - self.dead

        queue = [self.start]
        
        while queue:
            
            vertex = queue.pop(0) ## 左端弹出vertex
            
            path = nextPath(vertex) ## 生成vertex下一层可访问节点
            
            if len(path)<1:return -1
            
            self.count += 1
            
            if target in path: ## 判断为Y，返回计数即最短距离
                return self.count
            
            else: ## 判断为N，vertex下一层可访问节点 加入队列，vertex计入下次不可访问集合
                queue.append(path)
                self.dead.update(vertex)
            
        return -1`
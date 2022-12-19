```
class Solution(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        # 如果新的建筑要比现在最高的建筑要高
        # push进去heap中，然后right更新一下
        # 下一个建筑push进来后，如果它的left比right要右边的话，就先处理好所有在新的建筑
        # 左边的建筑撒
        # 如果一栋建筑被另外一栋建筑全包围了，我们就不考虑这建筑了
        # 全包围的概念是下移动建筑的高度和右顶点都在上一栋建筑的左下角
        n = len(buildings)
        heap = []
        res = []
        
        buildings = sorted(buildings, key = lambda x: x[0])
        # 设置一个最后的哨兵
        buildings.append([2 << 31 - 1, 2 << 31, 2 << 31])
        def baowei(building1, building2):
            return True if building1[1] >= building2[1] and building1[2] >= building2[2] else False
            

        # 大顶堆
        def shiftup(heap):
            j = len(heap) - 1
            building = heap[j]
            while j > 0:
                i = ( j - 1) // 2
                if heap[i][2] >= building[2]:
                    break
                else:
                    heap[j] = heap[i]
                    j = i
            heap[j] = building
            return 

        def shiftdown(heap):
            heap[0], heap[-1] = heap[-1], heap[0]
            heap.pop()
            if not heap:
                return 
            building = heap[0]
            i = 0
            while 2*i  + 1 < len(heap):
                j = 2*i  + 1
                if j + 1 < len(heap) and heap[j][2] < heap[j + 1][2]:
                    j += 1
                if building[2] >= heap[j][2]:
                    break
                else:
                    heap[i] = heap[j]
                    i = j
            heap[i] = building
            return 

        for building in buildings:
            while heap and building[0] > heap[0][1]:
                cur_building = heap[0]
                shiftdown(heap)
                while heap and baowei(cur_building, heap[0]):
                    shiftdown(heap)
                if not heap:
                    res.append([cur_building[1], 0])
                else:
                    res.append([cur_building[1], heap[0][2]])
            if not heap:
                res.append([building[0], building[2]])
            if heap and building[2] > heap[0][2]:
                res.append([building[0], building[2]])
            # 如果新的建筑和最高的建筑一样高且在新的建筑的左点在最高的建筑的右边的话，就合并一下最高的建筑的
            if heap and (building[0] <= heap[0][1] and building[2] == heap[0][2]):
                heap[0][1] = building[1]
            else:   
                heap.append(building)
                shiftup(heap)
        # 每个坐标都需要取最高的一点
        res = res[:-1]
        Hash = {}
        for data in res:
            if data[0] not in Hash:
                Hash[data[0]] = data[1]
            else:
                Hash[data[0]] = max(Hash[data[0]], data[1])
        return [[key, value] for key, value in Hash.items()]

        
```

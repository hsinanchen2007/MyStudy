### 解题思路
借用叉乘法思想，但是不把全集放在一起排序，而是只对每一列进行排序。只对每一列最上面和最下面的点做叉乘法。

### 代码

```python3
class Solution:
    def outerTrees(self, points: List[List[int]]) -> List[List[int]]:

        if len(points) < 4:
            return(points)

        cross = lambda p1, p2, p3: (p2[1]-p1[1])*(p3[0]-p1[0]) - (p3[1]-p1[1])*(p2[0]-p1[0])

        x_key_y_value = {}

        for point in points:
            if point[0] in x_key_y_value:
                x_key_y_value[point[0]].append(point[1])
            else:
                x_key_y_value[point[0]] = [point[1]]

        x_sorted = list(x_key_y_value.keys())
        x_sorted.sort()

        if len(x_sorted) < 3:
            return(points)

        left_edge = [[x_sorted[0],i] for i in x_key_y_value[x_sorted[0]]]
        # print('left_edge',left_edge)
        right_edge = [[x_sorted[-1],i] for i in x_key_y_value[x_sorted[-1]]]
        # print('right_edge',right_edge)

        top_edge = []
        for x in x_sorted:
            top_point = [x,max(x_key_y_value[x])]
            while len(top_edge) > 1 and cross(top_edge[-2],top_edge[-1],top_point) < 0:
                top_edge.pop()
            top_edge.append(top_point)
        # print('top_edge',top_edge)
        
        bottom_edge = []
        for x in x_sorted:
            bottom_point = [x,min(x_key_y_value[x])]
            while len(bottom_edge) > 1 and cross(bottom_edge[-2],bottom_edge[-1],bottom_point) > 0:
                bottom_edge.pop()
            bottom_edge.append(bottom_point)
        # print('bottom_edge',bottom_edge)

        edge_points = left_edge + right_edge + top_edge + bottom_edge
        edge_points_str = set([str(p[0]) + ',' + str(p[1]) for p in edge_points])
        edge_points_unique = [[int(p.split(',')[0]),int(p.split(',')[1])] for p in edge_points_str]

        return(edge_points_unique)



            














```
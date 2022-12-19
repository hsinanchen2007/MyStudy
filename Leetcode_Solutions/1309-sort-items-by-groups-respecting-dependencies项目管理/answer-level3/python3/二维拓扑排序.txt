### 解题思路
![image.png](https://pic.leetcode-cn.com/f02f67dc3d9f548613f469dffcb384b4d54f10f17c82621a9df78a4da9233160-image.png)

-   二维的拓扑排序
-   首先建立所有组之间的关系，找出小组能够输出的顺序，如果存在小组间依赖，肯定不能输出，返回空
-   然后按照小组的输出顺序，对组内项目进行拓扑排序，针对每个小组都进行下面的操作
    -   首先将没有小组的项目，并且没有依赖的（入度为0）的加入结果集中，并更新它后续项目的入度
    -   然后处理所有当前小组中的所有的项目，对当前小组中的项目进行拓扑排序，并加入到结果集中，如果小组中依旧有项目的入度依赖其他项目，表示当前小组的项目没办法连续，无法完成排序



### 代码

```python
from collections import defaultdict


class Solution:
    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        # 表示项目的依赖关系
        graph = defaultdict(list)
        # 依赖（入度）为0的项目
        zero_in_degree = set()
        # 项目的入度
        project_in_degree = defaultdict(int)
        # 小组中的项目
        group_project = defaultdict(set)
        # 小组的依赖
        group_graph = defaultdict(set)
        # 小组的入度
        group_in_degree = defaultdict(int)

        ans = []

        for index, (g, before) in enumerate(zip(group, beforeItems)):
            group_project[g].add(index)
            for before_project in before:
                graph[before_project].append(index)
                project_in_degree[index] += 1
                if g != -1 and group[before_project] != -1 and g != group[before_project]:
                    group_graph[group[before_project]].add(g)
        for i in range(n):
            if project_in_degree[i] == 0:
                zero_in_degree.add(i)
        sorted_group = []
        zero_group = set()
        for pre_group, next_groups in group_graph.items():
            for ng in next_groups:
                group_in_degree[ng] += 1
        for i in range(m):
            if group_in_degree[i] == 0:
                zero_group.add(i)
        while zero_group:
            current_group = zero_group.pop()
            sorted_group.append(current_group)
            for next_group in group_graph[current_group]:
                group_in_degree[next_group] -= 1
                if group_in_degree[next_group] == 0:
                    zero_group.add(next_group)

        # 小组之间存在循环依赖
        if len(sorted_group) != m:
            return []

        def update_in_degree(project):
            """
            更新节点的度
            :param project:
            :return:
            """
            for next_project in graph[project]:
                project_in_degree[next_project] -= 1
                if project_in_degree[next_project] == 0:
                    zero_in_degree.add(next_project)

        def process_with_no_group_project():
            """
            处理没有分组并且度为0的节点
            :return:
            """
            while group_project[-1].intersection(zero_in_degree):
                for no_group_project in group_project[-1].intersection(zero_in_degree):
                    ans.append(no_group_project)
                    zero_in_degree.remove(no_group_project)
                    update_in_degree(no_group_project)
                    group_project[-1].remove(no_group_project)

        for current_group in sorted_group:
            process_with_no_group_project()
            while zero_in_degree.intersection(group_project[current_group]):
                for current_group_project in zero_in_degree.intersection(group_project[current_group]):
                    ans.append(current_group_project)
                    zero_in_degree.remove(current_group_project)
                    group_project[current_group].remove(current_group_project)
                    update_in_degree(current_group_project)
            if group_project[current_group]:
                return []
        process_with_no_group_project()

        if len(ans) == n:
            return ans
        return []
```
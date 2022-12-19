## 解题思路
主要抓住这两点：
###### 1、顺序遍历每行的每个结点，如果该节点是1，则**看该节点相邻的四个方向是否有1**，如果有某一个方向有1，则说明这个方向有公共边，不计入总周长
###### 2、如果某一行全是0，且之前已经出现过1，则下面的所有行都不用遍历，根据题目的描述，下面的全是0了。
### 
### 
```python
def island_perimeter(grid):
    counter = 0
    flag = 0  # 标记截止当前遍历到的节点中是否有1的，默认没有
    for rid in range(len(grid)):
        lake = 0  # 判断本行数据是否有1
        for cid in range(len(grid[rid])):
            if grid[rid][cid] == 0:
                continue
            flag = 1  # 标记截止当前是否有1的节点产生
            lake = 1  # 标记本行数据是否有1
            # 查看该元素上面的元素是否是岛屿
            if rid == 0 or grid[rid - 1][cid] == 0:
                counter += 1
                # 查看该元素下面的元素是否是岛屿
            if rid == len(grid) - 1 or grid[rid + 1][cid] == 0:
                counter += 1
                # 查看该元素左面的元素是否是岛屿
            if cid == 0 or grid[rid][cid - 1] == 0:
                counter += 1
            # 查看该元素右面的元素是否是岛屿
            if cid == len(grid[rid]) - 1 or grid[rid][cid + 1] == 0:
                counter += 1
        # 如果截止当前已经有岛屿产生，且是本行的数据全是0（lake=0），则下面的数据不用再遍历了，因为题目给了不存在湖的情况
        if flag == 1 and lake == 0:
            return counter
    return counter
```

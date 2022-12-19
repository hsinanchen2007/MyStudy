Flood Fill这类题型一般都可以使用DFS，BFS和并查集来解决。在这里我们先来分析每种算法解决它的思路，最后再做一个小小的总结。希望这篇文章对您有帮助。

为了方便大家阅读，我把完整代码贴在了文末。


### 深度优先搜索

- 从开始位置`(sr, sc)`出发，依次向它的四个方向进行搜索，搜索之前要先把当前像素点的颜色改为`newColor`。

```cpp
image[r][c] = newColor;
int vx[] = {0, 0, 1, -1};
int vy[] = {1, -1, 0, 0};
for (int i = 0; i < 4; i++) {
    int newr = r + vy[i];
    int newc = c + vx[i];
    dfs(image, newr, newc, newColor, color);
}
```

这样一直搜索下去肯定不行， 要注意 DFS 的结束条件：

1. 当位置（行或列）超过数组的边界时，要结束递归。

```cpp
if (r >= image.size() || c >= image[0].size()) {
    return;
}
```

2. 如果当前位置的颜色值和开始位置`(sr, sc)`的颜色值不同时，我们不能修改它的颜色值，要结束递归。

```cpp
if (image[r][c] != color) {
    return;
}
```

3. 还有一点要注意的是，当要修改的目标颜色值`newColor`和开始位置的颜色值`image[sr, sc]`相同时，我们不需要对`image`做任何改变，原`image`就是最终的`image`.

```cpp
int color = image[sr][sc];
if (color == newColor) {
    return image;
}
```

### 广度优先搜索

- BFS 就是一层一层的往外边搜索边扩张，使用队列来实现。

- 一开始先把开始位置`(sr, sc)`加入队列，并且修改它的颜色值：

```cpp
queue<vector<int>> q;
q.push({sr, sc});
image[sr][sc] = newColor;
```

- 然后队首元素出队列，同时把它上下左右四个方向颜色值为`color`的位置加入到队尾，并修改它们的颜色值为`newColor`。

- 重复操作，直到队列为空。

```cpp
int vx[] = {0, 0, 1, -1};
int vy[] = {1, -1, 0, 0};
while (!q.empty()) {
    vector<int> pos = q.front();
    q.pop();
    // 标注1
    // image[pos[0]][pos[1]] = newColor;
    for (int i = 0; i < 4; i++) {
        int r = pos[0]+vy[i];
        int c = pos[1]+vx[i];
        if (r >= image.size() || c >= image[0].size()) {
            continue;
        }
        if (image[r][c] == color) {
            // 标注2
            image[r][c] = newColor;
            q.push({r, c});
        }
    }
}
```

#### 注意

- 这里特别要提醒的是，**一定要在添加到队尾的同时修改颜色值，不要在出队列时再修改颜色值。** 

- 也就是说修改颜色的代码，要放在`标注2`处，不能放在`标注1`处。

#### 解释

如果等到出队列时再修改颜色值，那对于已经添加到队列中的像素点，虽然他们已经在队列中，但颜色并未及时修改。如果此时出队列的像素点正好位于某个已经在队列中的像素点旁边，那这个已经在队列中的像素点，就会被重复添加到队尾了。

轻则导致耗时增加，严重的话会出现提交超时错误。

### 并查集

- 我们先来看一下 Flood Fill 的定义：漫水填充法是一种用特定的颜色填充**连通区域**，通过设置**可连通像素**的上下限以及**连通方式**来达到不同的填充效果的方法。

- 定义中多次提到连通，而并查集就是用来解决动态连通性问题的！

![来源网络](https://pic.leetcode-cn.com/bff162d8b98c3475a91f51c703f5b36237936299e700a15404c02cf51bc4865f.png)

1. 假设开始位置`(sr, sc)`的颜色为`color`。
2. 我们可以使用并查集把颜色值为`color`并且位置相邻的像素点连通起来，形成一个连通集合。
3. 颜色值不是`color`的每个像素点，单独作为一个集合。

- 例如下面这种情况（圈起来的是开始位置），使用并查集就把它分成了 4 个连通集合。这时我们只需要把所有和开始位置`(sr, sc)`在同一个集合的像素点的颜色改为`newColor`就行了。

![](https://pic.leetcode-cn.com/52a2e3fd532d09a60996f6150debcae0815555d5537196c9f09391aa350df1ad.png)

怎么把它们分成若干个集合呢？

- 我们从`(0, 0)`位置开始依次遍历，这时就不需要同时兼顾上下左右四个方向了，只需要看看它**右边和下面**的像素点颜色是不是和我一样都为`color`，一样就合并。
- 不一样就不管它，让它自己单独作为一个集合。

![动图演示](https://pic.leetcode-cn.com/eab9e878c0865027164812598f5d71a36477b033f4a6f35be645ef220218dde9.gif)

- 提示，这里每个像素点的位置是二维坐标`(row, col)`，为了方便我们需要**将它们的位置映射为一维形式**:`row * colNum + col`。`row`表示行坐标，`col`表示列坐标，`colNum`表示数组的列数。

```cpp
for (int i = 0; i < rowNum; i++) {
    for (int j = 0; j < colNum; j++) {
        if (image[i][j] != color) {
            continue;
        }
        int right = j+1;
        int down = i+1;
        if (right < colNum && image[i][right] == color) {
            u.unio(i*colNum+j, i*colNum+right);
        }
        if (down < rowNum && image[down][j] == color) {
            u.unio(i*colNum+j, (down)*colNum+j);
        }
    }
}
```

- 那么接下来我们就只需要把和开始位置`(sr, sc)`在同一个连通集合的像素点颜色值置为`newColor`就行了。

```cpp
for (int i = 0; i < rowNum; i++) {
    for (int j = 0; j < colNum; j++) {
        if (u.connected(i*colNum+j, sr*colNum+sc)) {
            image[i][j] = newColor;
        }
    }
}
```

### 总结

- 通过上面这道题的分析，我们可以总结出漫水填充算法题型有着这样的特征：空间都是按区域划分的，并且每个区域中的元素都是相邻的。

- 为了扩大它的解题范围，我们可以再进一步抽象，把一个个区域抽象为一个个集合，集合中的元素都存在着某种逻辑上的连通性。最典型的就是[547. 朋友圈](https://leetcode-cn.com/problems/friend-circles/ "547. 朋友圈")。

Flood Fill 这类题还有很多：

- [1020. 飞地的数量](https://leetcode-cn.com/problems/number-of-enclaves/ "1020. 飞地的数量")

- [1254. 统计封闭岛屿的数目](https://leetcode-cn.com/problems/number-of-closed-islands/ "1254. 统计封闭岛屿的数目")

- [547. 朋友圈](https://leetcode-cn.com/problems/friend-circles/ "547. 朋友圈")

如果使用DFS或BFS的话，解决它们的步骤无非就是遍历、标记 加 计数。

如果抽象为集合的话，我们就可以使用并查集对它们进行集合划分，最后只需要对目标集合中的元素进行操作就可以了。


### 代码

#### 深度优先搜素

```cpp
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color == newColor) {
            return image;
        }
        dfs(image, sr, sc, newColor, color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int r, int c, int newColor, int color) {
        if (r >= image.size() || c >= image[0].size()) {
            return;
        }
        if (image[r][c] != color) {
            return;
        }
        image[r][c] = newColor;
        int vx[] = {0, 0, 1, -1};
        int vy[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int newr = r + vy[i];
            int newc = c + vx[i];
            dfs(image, newr, newc, newColor, color);
        }
    }

};
```

#### 广度优先搜素

```cpp
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color == newColor) {
            return image;
        }
        queue<vector<int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        int vx[] = {0, 0, 1, -1};
        int vy[] = {1, -1, 0, 0};
        while (!q.empty()) {
            vector<int> pos = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = pos[0]+vy[i];
                int c = pos[1]+vx[i];
                if (r >= image.size() || c >= image[0].size()) {
                    continue;
                }
                if (image[r][c] == color) {
                    image[r][c] = newColor;
                    q.push({r, c});
                }
            }
        }
        return image;
    }
};
```

#### 并查集

```cpp
class UnionFind {
private:
    int* parent;

public:
    UnionFind(){}
    UnionFind(int n) {
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void unio(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        parent[y] = x;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color == newColor) {
            return image;
        }
        int rowNum = image.size();
        int colNum = image[0].size();
        UnionFind u(rowNum * colNum);
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < colNum; j++) {
                if (image[i][j] != color) {
                    continue;
                }
                int right = j+1;
                int down = i+1;
                if (right < colNum && image[i][right] == color) {
                    u.unio(i*colNum+j, i*colNum+right);
                }
                if (down < rowNum && image[down][j] == color) {
                    u.unio(i*colNum+j, (down)*colNum+j);
                }
            }
        }
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < colNum; j++) {
                if (u.connected(i*colNum+j, sr*colNum+sc)) {
                    image[i][j] = newColor;
                }
            }
        }
        return image;
    }
};
```

#### [点我阅读原文](https://mp.weixin.qq.com/s/nZZW_HIPNkDzIUOAwb5Uhg)
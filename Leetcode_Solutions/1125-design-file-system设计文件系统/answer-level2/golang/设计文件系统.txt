#### 方法一：哈希表

**思路**

`Linux`有一个 `tree` 命令，根据这个命令我们可以很清晰的看到文件的目录结构：
![fig1](https://assets.leetcode-cn.com/solution-static/1166_fig1.png){:width=300}

很显然，我们可以使用树结构记录文件的目录。其实很多文件系统的设计都是使用**树**这个数据结构，所以我们也可以使用树。结构体存储当前路径的值和子路径的集合。子路径的集合可以使用哈希表或者数组，这里使用哈希表效率更高。

**算法**

我们用 `FileSystem` 结构来表示一个目录，`path` 成员是一个哈希表，它保存该路径下的所有子目录，`value` 成员保存该目录对应的值。

`Create` 的时候根据 `/` 切割 `path`，将其转换为数组，得到整个路径的关系。比如 `path = /a/b/c/d`，切割之后的数组为 `["a", "b", "c", "d"]`，其中 `a` 是根目录。最后一个路径为 `d`，我们首先要找到是否存在 `/a/b/c` 这个目录。所以从 `a` 开始不断往下找，直到找到 `c` 目录，如果中间有个目录不存在，返回 `false`，否则，看最后一个 `d` 目录是否存在，若存在，则说明整个路径已经存在，返回 `false`，否则新建一个目录并保存对应的值。

`Get` 的时候使用同样的方法依次按照目录的顺序判断是否存在，如果中间有个目录不存在，返回 `false`，否则，输出最后一个目录存储的值。

**代码**

```Golang []
type FileSystem struct {
    path map[string]*FileSystem
    value int
}

func Constructor() FileSystem {
    return FileSystem{
        path: make(map[string]*FileSystem),
    }
}

func (this *FileSystem) CreatePath(path string, value int) bool {
    if path == "" || path == "/" {
        return false
    }
    paths := strings.Split(path, "/")
    m := this
    for i := 1; i < len(paths) - 1; i++ {
        v, ok := m.path[paths[i]]
        if !ok {
            return false
        }
        m = v
    }
    _, ok := m.path[paths[len(paths)-1]]
    if ok {
        return false
    }
    m.path[paths[len(paths)-1]] = &FileSystem{
        path: make(map[string]*FileSystem),
        value: value,
    }
    return true
}

func (this *FileSystem) Get(path string) int {
    if path == "" || path == "/" {
        return -1
    }
    paths := strings.Split(path, "/")
    m := this
    for i := 1; i < len(paths)-1; i++ {
        v, ok := m.path[paths[i]]
        if !ok {
            return -1
        }
        m = v
    }
    v, ok := m.path[paths[len(paths)-1]]
    if ok {
        return v.value
    }
    return -1
}
```

**复杂度分析**

- 时间复杂度：总时间复杂度为 $O(mn)$，其中 $n$ 为字符串 `path` 的长度，$m$ 为两个函数的总调用次数。`Create` 和 `Get` 的时间复杂度都为 $O(n)$，切割字符串成数组 `paths` 需要遍历一次字符串，复杂度为 $O(n)$，遍历 `paths` 的总时间复杂度也为 $O(n)$。

- 空间复杂度：最坏情况下，所有操作均为`Create`，并且每次都能新建一个路径，即新增 $O(n)$ 的空间，此时总空间复杂度为 $O(mn)$。`Create`和 `Get` 各自的空间复杂度都为 $O(n)$，其中 $n$ 为字符串 `path` 的长度，即创建路径数组存储字符串所占空间。
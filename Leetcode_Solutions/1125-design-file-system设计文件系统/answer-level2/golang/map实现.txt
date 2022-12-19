### 解题思路
此处撰写解题思路

1. path-value使用map[string]path 存储

2. 对于 父路径的判断 采用strings.Split(path,"/")得到一个[]string切片

3. 然后for遍历 判断各个父路径是否存在

### 代码

```golang
type FileSystem struct {
    m map[string]int
}


func Constructor() FileSystem {
    m := make(map[string]int)
    return FileSystem{
        m: m,
    }
}

func (this *FileSystem) Pathexist(path string) bool {
    if path == "" || path == "/" {
        return false
    }
    // 路径存在 或者 父路径不存在 ————>flase
    if _,ok := this.m[path]; ok  {
        return false
    }

    var (
        paths []string
        dir string
    )
    paths = strings.Split(path,"/")
    // 分割后 paths[0] 为空 paths[1] -> paths[len(paths)]
    for i:=1; i < len(paths)-1 ; i++ {
        dir = dir + "/" + paths[i]
        // 父路径不存在
        if _,ok := this.m[dir]; !ok  {
            return false
        }
    }
    return true
}

func (this *FileSystem) CreatePath(path string, value int) bool {
    if this.Pathexist(path) {
        this.m[path] = value
        return true
    }
    return false
}


func (this *FileSystem) Get(path string) int {
    var ok bool
    _,ok = this.m[path] 
    if path == "" || path == "/" || !ok{
        return -1
    }
    return this.m[path]
}


/**
 * Your FileSystem object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.CreatePath(path,value);
 * param_2 := obj.Get(path);
 */
```
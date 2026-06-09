### 解题思路
执行用时 :16 ms, 在所有 Go 提交中击败了66.67% 的用户
内存消耗 :6.1 MB, 在所有 Go 提交中击败了100.00%的用户

type elem struct {
    children map[string]*elem  // 子目录   
    dir     string      // 目录 or 文件名
    value   string      // 文件内容
}
1. 为目录 那么children 不为nil
2. 为文件 那么children 为nil 
3. 通过children map 将各子文件，子目录记录下来

### 代码

```golang
type FileSystem struct {
    root *elem
}


type elem struct {
    children map[string]*elem  // 子目录  
    dir     string      // 目录
    value   string      // 文件
}



func Constructor() FileSystem {
    elem := elem{
        children:   make(map[string]*elem),
        dir:        "/",
        value:      "",
    }
    return FileSystem{
        root: &elem,
    }
}

func split(path string) []string {
    s := strings.Split(path, "/")
    s = s[1:]
    return s
}



func (this *FileSystem) Ls(path string) []string {
   
    var node *elem

    var s []string
    

    p := split(path)
    node = this.root

    if path == "/" {
        goto END
    }


    for _,v := range p {
        
        node = node.children[v]
    }

END:
    // 为目录
    if node.children != nil {
        for k,_ := range node.children {
            s = append(s, k)
        } 
    }else  { //为文件
        if node.value != ""{
             s = append(s, node.dir)
        }
       
    } 
    

    // 按字典序排序
    sort.Strings(s)
    
    return s
}


func (this *FileSystem) Mkdir(path string)  {
    p := split(path)
    node := this.root
    for _,v := range p {
        if _,ok := node.children[v]; !ok{
            node.children[v] = &elem{
                children:   make(map[string]*elem),
                dir:        v,
                value:      "",
            }
        }
        node = node.children[v]
    }
}


func (this *FileSystem) AddContentToFile(filePath string, content string)  {
   p := split(filePath)
    var node *elem
    node = this.root
	
    for _,v := range p {
        if _,ok := node.children[v]; !ok{
            node.children[v] = &elem{
                children:   make(map[string]*elem),
                dir:        v,
                value:      "",
            }
        }
        node = node.children[v]
    }
    if node.children != nil {
    	node.children = nil
	}
    node.value = node.value + content
}


func (this *FileSystem) ReadContentFromFile(filePath string) string {
	paths := split(filePath)
	var node *elem
	node = this.root

	for _,v := range paths {
		if _,ok := node.children[v]; !ok{
			return ""
		}
		node = node.children[v]
	}
	return node.value
}


/**
 * Your FileSystem object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ls(path);
 * obj.Mkdir(path);
 * obj.AddContentToFile(filePath,content);
 * param_4 := obj.ReadContentFromFile(filePath);
 */
```
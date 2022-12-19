```
type LRUCache struct {
    Capi int
    Left int
    Kn map[int]*listNode
    Head *listNode
    Tail *listNode
}

type listNode struct{
    Key int
    Val int
    Pre *listNode
    Next *listNode
}


func Constructor(capacity int) LRUCache {
    head := &listNode{}
    tail := &listNode{}
    head.Next = tail
    tail.Pre = head
    return LRUCache{
        Capi : capacity,
        Left : capacity,
        Head : head,
        Tail :tail,
        Kn : make(map[int]*listNode,capacity),
    }
}


func (this *LRUCache) Get(key int) int {
    if this.Left==this.Capi{
        return -1
    }
    //如果没有直接return -1
    if v,ok := this.Kn[key];!ok{  
        return -1
    }else{  //找到了
        if v==this.Head.Next{  //如果恰好是第一个直接返回
            return v.Val
        }else if v==this.Tail.Pre{  //如果是最后一个
            //将该节点移到头结点就行
            this.Tail.Pre = v.Pre
            v.Pre.Next = this.Tail
            v.Next =  this.Head.Next
            v.Pre = this.Head
            this.Head.Next.Pre = v
            this.Head.Next = v
        }else{  //如果在中间
            //将该点的前后相连
            v.Pre.Next = v.Next
            v.Next.Pre = v.Pre
            //v插到头结点后面
            v.Next = this.Head.Next
            v.Pre = this.Head
            this.Head.Next.Pre = v
            this.Head.Next = v
        }
        
        return v.Val //返回
    }
}

func (this *LRUCache) Put(key int, value int)  {

    //如果结点存在，更新值，插入最前面
    if v,ok:=this.Kn[key];ok{
        v.Val = value
        if v==this.Head{
            return 
        }
        this.move(v)
    }else{
        //结点不存在，则需要new一个结点
        newNode := &listNode{
            Key : key,
            Val : value,
            Pre : nil,
            Next : nil,
        }
        //如果没满
        if this.Left > 0{
            this.Left--
            //将新结点插在头节点
            newNode.Next = this.Head.Next
            newNode.Pre = this.Head
            this.Head.Next.Pre = newNode
            this.Head.Next = newNode
            //加入map
            this.Kn[key] = newNode
        }else{ //满了
            //删除最后一个
            del := this.Tail.Pre
            del.Pre.Next = this.Tail
            this.Tail.Pre = del.Pre
            delete(this.Kn,del.Key)
            //加入新节点
            newNode.Next = this.Head.Next
            newNode.Pre = this.Head
            this.Head.Next.Pre = newNode
            this.Head.Next = newNode
            //加入map
            this.Kn[key] = newNode
        }
    }
   
    
}

func (this *LRUCache)move(v *listNode){
        if v==this.Tail.Pre{  //如果是最后一个
            //将该节点移到头结点就行
            this.Tail.Pre = v.Pre
            v.Pre.Next = this.Tail
            v.Next =  this.Head.Next
            v.Pre = this.Head
            this.Head.Next.Pre = v
            this.Head.Next = v
        }else{  //如果在中间
            //将该点的前后相连
            v.Pre.Next = v.Next
            v.Next.Pre = v.Pre
            //v插到头结点后面
            v.Next = this.Head.Next
            v.Pre = this.Head
            this.Head.Next.Pre = v
            this.Head.Next = v
        }
}
```
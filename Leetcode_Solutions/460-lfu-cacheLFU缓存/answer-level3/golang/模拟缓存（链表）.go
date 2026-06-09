### 代码

```golang
type node struct{
    val int
    key int
    times int
    time int
    next *node
}
type LFUCache struct {
    head *node
    count int
    key int
    num int
}


func Constructor(capacity int) LFUCache {
    p:=LFUCache{}
    p.head=&node{next:nil,val:-2,time:0,times:0,key:-2}
    p.count=capacity
    p.key=0
    p.num=0
    return p
}

func (this *LFUCache) Get(key int) int {
    this.key++
    p:=this.head
    for p.next!=nil{
        if p.next.key==key{
            res:=p.next.val
            n:=&node{
                val:p.next.val,
                key:key,
                times:p.next.times+1,
                time:this.key,
                next:nil,
            }
            p.next=p.next.next
            todo(p,n)
            return res
        }else{
            p=p.next
        }
    }
    return -1
}


func (this *LFUCache) Put(key int, value int)  {

    this.key++
    if this.count==0{
        return
    }
    p:=this.head
    for p.next!=nil{
        if p.next.key!=key{
            p=p.next
        }else{     
            n:=&node{
                val:value,
                key:key,
                times:p.next.times+1,
                time:this.key,
                next:nil,
            }
            p.next=p.next.next
            todo(p,n)
            return
        }
    }
    if this.count>this.num{
        this.num++
    }else{
        this.head.next=this.head.next.next
    }
    n:=&node{
        val:value,
        key:key,
        times:1,
        time:this.key,
        next:nil,
    }
    todo(this.head,n)
}

func todo(head *node,n *node){
    p:=head
    for p.next!=nil{
        if p.next.times>n.times{
            break
        }else{
            p=p.next
        }
    }
    n.next=p.next
    p.next=n   
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
```
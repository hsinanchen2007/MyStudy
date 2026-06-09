### 代码

```golang
type Delete struct{
    times int
    time int
}
type LFUCache struct {
    Val map[int]int
    delete map[int]Delete
    count int
    key int
    num int
}


func Constructor(capacity int) LFUCache {
    p:=LFUCache{}
    p.Val=make(map[int]int,0)
    p.delete=make(map[int]Delete,0)
    p.count=capacity
    p.key=0
    p.num=0
    return p
}


func (this *LFUCache) Get(key int) int {
    
    if v,ok:=this.Val[key];ok{
        this.key++
        this.delete[key]=Delete{time:this.key,times:this.delete[key].times+1}        
        return v
    }
    return -1
}


func (this *LFUCache) Put(key int, value int)  {
    this.key++
    if this.count==0{
        return
    }
    if _,ok:=this.Val[key];ok{
        this.Val[key]=value
        this.delete[key]=Delete{time:this.key,times:this.delete[key].times+1}
        return
    }
    if this.num<this.count{
        this.num++
    }else{
        var kk int=-1
        Time,Times:=1000,10000
        for k,_:=range this.Val{
            if kk==-1||this.delete[k].times<Times||this.delete[k].times==Times&&this.delete[k].time<Time{
                kk=k
                Time=this.delete[k].time
                Times=this.delete[k].times
            }
        } 
        delete(this.Val,kk)
        delete(this.delete,kk)  
    }
    this.Val[key]=value
    this.delete[key]=Delete{time:this.key,times:1}
}


/**
 * Your LFUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
```
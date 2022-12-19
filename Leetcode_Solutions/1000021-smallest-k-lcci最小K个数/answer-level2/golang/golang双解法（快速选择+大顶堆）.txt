## 使用快速选择和大顶堆实现

1.快速选择(如果不清楚，可以先去做315题) T：O:(N)，S：O(K)

```
//快速选择 
func smallestK(arr []int, k int) []int {
    if arr==nil || len(arr)==0{
        return nil
    }
    res:=make([]int,0)
    left,right:=0,len(arr)-1
    for {
        //基准位置
        pos:=quickselect(arr,left,right)
        if pos==k{//如果基准位置在k处，说明前k个元素就是我们需要的结果
            break
        }else if pos < k{//如果小于k，说明所求位置应该在右边
            left=pos+1
        }else{
            right=pos-1//所求位置在左边
        }
    }
    //放入结果集中
    for i:=0;i<k;i++{
        res=append(res,arr[i])
    }
    return res
}
//此处使用的是快速排序的partition方法（注意：不能使用双路或者三路的partition，因为这两种方式找不到基准的准确位置）
func quickselect(arr []int,left,right int)int{
    pivotIndex:=rand.Intn(right-left+1)+left//定义一个随机基准值索引
    arr[pivotIndex],arr[right]=arr[right],arr[pivotIndex]//将基准值与最右边的数交换
    pivot:=arr[right]//以最右边的数为基准
    explodeIndex:=left//分割点，代表所有小于基准值的最右边
    for i:=left;i<right;i++{
        if arr[i] <= pivot{
            arr[explodeIndex],arr[i]=arr[i],arr[explodeIndex]
            explodeIndex++
        }
    }
    //将基准值复位
    arr[right],arr[explodeIndex]=arr[explodeIndex],arr[right]
    return explodeIndex
}
```

2. 大顶堆实现，维持一个大小为k的大顶堆即可  T：O:(NlogN)，S：O(K)

```
//堆排序(大顶堆)
func smallestK(arr []int, k int) []int {
    if arr==nil || len(arr)==0 || k==0{
        return nil
    }
    res:=make([]int,0)
    //构建堆
    h:=&IntHeap{}
    heap.Init(h)
    for i:=0;i<len(arr);i++{
        if h.Len()<k{//维持一个k大小的堆
            heap.Push(h,arr[i])
        }else{//当新加入数时，如果当前堆顶
            //元素大于当前数，把堆顶元素弹出，加入新数
            top:=heap.Pop(h)
            if top.(int) > arr[i]{
                heap.Push(h,arr[i])
            }else{
                heap.Push(h,top)
            }
        }
    }
    for h.Len()!=0{
        res=append(res,heap.Pop(h).(int))
    }
    return res
}


//构建大顶堆
type IntHeap []int

func (h IntHeap)Len()int{
    return len(h)
}

func (h IntHeap)Less(i,j int)bool{
    return h[i]>h[j]
}

func (h IntHeap)Swap(i,j int){
    h[i],h[j]=h[j],h[i]
}

func (h *IntHeap)Push(x interface{}){
    *h=append(*h,x.(int))
}

func (h *IntHeap)Pop()interface{}{
    old:=*h
    x:=old[len(old)-1]
    *h=old[:len(old)-1]
    return x
}
```

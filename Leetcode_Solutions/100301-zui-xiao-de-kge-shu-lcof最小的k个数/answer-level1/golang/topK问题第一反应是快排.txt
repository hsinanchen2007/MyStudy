### 解题思路
topN的问题第一反应应该到快排上，因为它的速度是最快的，而且topN的结果不用排序。

### 代码

```golang
func getLeastNumbers(arr []int, k int) []int {
  beg, end := 0,len(arr)-1
  for{
    proit := partition(arr,beg,end)
    if proit+1 == k{
      break
    }else if proit + 1 < k {
      beg = proit+1
    }else{
      end = proit-1
    }
  }
  return arr[0:k]
}


func partition(arr []int, beg int, end  int) int{
  if beg==end{
    return  end
  }
  proit := arr[beg]
  for ;beg<end;{
    for ;beg<end && arr[end]>=proit; {
      end -= 1
    }
    arr[beg]=arr[end]
    for ; beg<end && arr[beg]<=proit;{
      beg +=1
    }
    arr[end]=arr[beg]
  }
  arr[beg] = proit
  return end
}


```
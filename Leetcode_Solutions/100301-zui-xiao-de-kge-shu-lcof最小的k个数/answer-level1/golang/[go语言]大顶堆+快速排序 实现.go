大顶堆实现
```
func getLeastNumbers(arr []int, k int) []int {
    if k>len(arr) || k==0{
        return nil
    }
   res :=arr[:k]
   n :=len(res)-1
  //数组前k个元素构建大顶堆
   for i:=len(res)/2-1;i>=0;i--{
       build(res,i,n)
   }
  //遍历k之后的元素，调整堆
   for i:=k;i<len(arr);i++{
       if arr[i]<res[0]{
           res[0]=arr[i]
           build(res,0,k-1)
       }
   }
  return res
}


func build(nums[] int,i,n int){
	for{
		index :=2*i+1
		if index>n || index<0{
			break
		}
		if j:=index+1;j<=n&&nums[j]>nums[index]{
			index=j
		}
		if nums[i]>nums[index]{
			break
		}
		nums[index],nums[i]=nums[i],nums[index]
		i=index
	}
}
```



快排实现
```
func getLeastNumbers(arr []int, k int) []int {
    if k>len(arr) || k<=0{
        return nil
    }
   
   start,end :=0,len(arr)-1
   index :=getPartition(arr,start,end)
   for index !=k-1{
       if index >k-1{
           index = getPartition(arr,start,index-1)
       }else{
           index=getPartition(arr,index+1,end)
       }
   }
   return arr[:index+1]
}

func getPartition(arr []int,start,end int) int{

    tmp:=arr[start]
    for start < end {
        for start < end && arr[end]>=tmp{
            end--
        }
        arr[start]=arr[end]
        for start < end && arr[start]<=tmp{
            start++
        }
        arr[end]=arr[start]
    }
    arr[start]=tmp
    return start
}
```




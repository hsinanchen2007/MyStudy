计数排序，分别统计0,1,2的元素个数，再把他们放回到原有的数组即可
```
func sortColors(nums []int)  {
    arr := [3]int{}
    for i:=0;i<len(nums);i++{
        arr[nums[i]]++
    }
    index :=0
    for i:= 0;i<arr[0];i++{
        nums[index] = 0
        index++
    }
    for i:= 0;i<arr[1];i++{
        nums[index] = 1
        index++
    }
    for i:= 0;i<arr[2];i++{
        nums[index] = 2
        index++
    }
}
```

荷兰国旗-三路快排原理
```
func sortColors(nums []int)  {
  
    zero := -1
    two:= len(nums)
    i := 0
    for i<two{
        if nums[i] == 0{
            nums[zero+1],nums[i] = nums[i],nums[zero+1]
            i++
            zero++
        }else{
            if nums[i]==1{
                i++
            }else{
                nums[i],nums[two-1] = nums[two-1],nums[i]
                two--
            }
        }
    }
}
```


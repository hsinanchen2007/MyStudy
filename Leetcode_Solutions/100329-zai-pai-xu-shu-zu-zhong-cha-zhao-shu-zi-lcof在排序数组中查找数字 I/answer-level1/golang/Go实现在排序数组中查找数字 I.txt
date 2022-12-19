

```golang
func search(nums []int, target int) int {
    if len(nums)==0{
        return 0
    }
    l,r := getLeftFirst(nums,target,0,len(nums)-1),getRightFirst(nums,target,0,len(nums)-1)
    if l>-1&&r>-1{
        return r-l+1
    }
    return 0
}

func getLeftFirst(nums []int,k,l,r int)int{
    if l>r{
        return -1
    }
    mid := l+(r-l)/2
    if nums[mid]==k{
        if mid>0&&nums[mid-1]!=k|| mid==0{
            return mid
        }else{
            r = mid-1
        }
    }else if nums[mid]<k{
        l = mid+1
    }else{
        r = mid-1
    }
    return getLeftFirst(nums,k,l,r)
}

func getRightFirst(nums []int,k,l,r int)int{
    if l>r{
        return -1
    }
    mid := l+(r-l)/2
    if nums[mid]==k{
        if mid<len(nums)-1&&nums[mid+1]!=k|| mid==len(nums)-1{
            return mid
        }else{
            l = mid+1
        }
    }else if nums[mid]<k{
        l = mid+1
    }else{
        r = mid-1
    }
    return getRightFirst(nums,k,l,r)
}
```
### 解题思路
![1.png](https://pic.leetcode-cn.com/33782fd3db1ccff08e23c68bc99588940f7b71edb145e0b8bf8aaa299784372b-1.png)

**双指针二分查找法**：设置head与tail作为真正的l,r指针，而l,r指针则分别为了找出head,tail。
大致思路就是先双指针找head，再用双指针找tail，找着了再看下nums[head]是不是我们要找的那个target（如果是，则可以保证nums[tail]也是），如果是target就返回 [head,tail]，否则就返回 [-1,-1]。

### 代码

```golang
func searchRange(nums []int, target int) []int {
    //边界过滤
	if len(nums)==0{
		return []int{-1,-1}
	}
	l:=0
	r:=len(nums)-1
	var (
		head int
		tail int
	)
	//开始找head
	if nums[0]==target{
		head=0
	}else{
		for l<r{
			mid := (l+r)/2
			if nums[mid]>=target{
				r = mid
			}else if nums[mid]<target{
				l = mid
			}
			if l==r-1{
				head=r
				break
			}
		}
	}
	//开始找tail
	l=0
	r=len(nums)-1
	if nums[r]==target{
		tail = r
	}else{
		for l<r{
			mid := (l+r)/2
			if nums[mid]>target{
				r = mid
			}else if nums[mid]<=target{
				l = mid
			}
			if l==r-1{
				tail=l
				break
			}
		}
	}
	//异常处理（无target的情况）
	if nums[head]!=target{
		return []int{-1,-1}
	}else{
		return []int{head,tail}
	}
}
```
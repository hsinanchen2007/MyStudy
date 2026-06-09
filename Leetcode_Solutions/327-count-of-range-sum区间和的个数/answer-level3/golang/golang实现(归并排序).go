### 参考315题实现

#### 思路：
1. 因为求的是区间和，先把前缀和求出来
2. 前缀和需要满足 lower<=S(i)-S(j)<=upper,i>=j
3. 参考315题思路，315求解的是左边比右边小的个数，那本题求的就是右边-左边在一个区间范围内的个数
4. 所以同样采用归并排序

```
//归并排序
func countRangeSum(nums []int, lower int, upper int) int {
    if nums==nil || len(nums)==0{
        return 0
    }
    //辅助数组
    tmp:=make([]int,len(nums)+1)
    //求前缀和
    s:=make([]int,len(nums)+1)
    for i:=1;i<=len(nums);i++{
        s[i]=s[i-1]+nums[i-1]
    }
    //注意这要写为len(nums)，而不要写成len(nums)-1，不然打死找不出来哪错了
    return mergesort(s,0,len(nums),tmp,lower,upper)
}

func mergesort(s []int,left,right int,tmp []int,lower,upper int)int{
    if left>=right{
        return 0
    }
    res:=0
    mid:=(right+left)/2
    res+=mergesort(s,left,mid,tmp,lower,upper)
    res+=mergesort(s,mid+1,right,tmp,lower,upper)
    //求满足区间的区间和的个数
    l:=left
    low,upp:=mid+1,mid+1
    for l<=mid{
        //在右边找到第一个大于等于lower的值
        for low<=right && s[low]-s[l]<lower{
            low++
        }
        //在右边找到第一个大于upper的值
        for upp<=right && s[upp]-s[l]<=upper{
            upp++
        }
        //两个一剪便是区间和的个数
        res+=upp-low
        //左指针++
        l++
    }
    //求完以后，执行合并操作
    merge(s,tmp,left,mid,right)
    return res
}
//合并还是归并的合并
func merge(s []int,tmp []int,left,mid,right int){
    l:=left
    r:=mid+1
    index:=left
    for l<=mid && r<=right{
        if s[l]<=s[r]{
            tmp[index]=s[l]
            l++
            index++
        }else{
            tmp[index]=s[r]
            r++
            index++
        }
    }
    for l<=mid{
        tmp[index]=s[l]
        l++
        index++
    }
    for r<=right{
        tmp[index]=s[r]
        r++
        index++
    }
    for i:=left;i<=right;i++{
        s[i]=tmp[i]
    }
}
```
本题难点就是那一小段如何求区间和的思路：写的时候是否有个错觉，为啥lower和upper要从右边开始，而不是left+1的位置？？？？
个人理解：像一颗二叉树一样，先执行了后序遍历，直接到叶子节点，如到[5] [6] ，那计算满足区间的区间和个数当然从右边开始，执行完以后进行merge操作，接着执行下一段，当执行到最后一块时，前面的都已经计算好了，当然还是从右边开始。（归并的还是没学好）

#### 以上仅为本人观点，如有错误还望不吝赐教
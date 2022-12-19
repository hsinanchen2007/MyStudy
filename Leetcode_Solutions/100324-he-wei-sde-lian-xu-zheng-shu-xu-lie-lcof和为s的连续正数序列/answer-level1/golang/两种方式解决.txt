# 暴力法
```
//暴力法
func findContinuousSequence(target int) [][]int {
    if target<=0{
        return nil
    }
    res:=make([][]int,0)
    for i:=1;i<=target/2;i++{
        target2:=target
        tmp:=make([]int,0)
        for j:=i;j<=target;j++{
            if target2 > 0{
                tmp=append(tmp,j)
                target2-=j
            }else if target2==0{
                res=append(res,tmp)
                break
            }else{
                break
            }
        }
    }
    return res
}

}
```

# 双指针（滑动窗口），本质来源于求和公式（sum=(l+r)(r-l+1)/2）
```
//双指针实现(滑动窗口)
func findContinuousSequence(target int) [][]int {
    if target<=0{
        return nil
    }
    res:=make([][]int,0)
    tmp:=make([]int,0)
    l,r:=1,2//左右边界
    for l<r{
        //求和公式
        sum:=(l+r)*(r-l+1)/2
        //sum>target:当前以l开头的不存在和为target的序列
        //寻找下一个左边界
        if sum > target{
            l++
            //sum<target:说明sum小，需要向后移窗口
        }else if sum < target{
            r++
        }else{
            //相等则放入切片
            for i:=l;i<=r;i++{
                tmp=append(tmp,i)
            }
            res=append(res,tmp)
            //清空切片
            tmp=[]int{}
            //左边界右移
            l++
        }
    }
    return res
```
### 829题，连续整数求和和这个题目类似

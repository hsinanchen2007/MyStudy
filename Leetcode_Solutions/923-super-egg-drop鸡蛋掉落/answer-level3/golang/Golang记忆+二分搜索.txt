### 解题思路
本题的第一个难点首先是理解题目所讲的是什么：
1.给K个鸡蛋，在N层楼中间跑来跑去测试。鸡蛋高于某一层F的时候会被摔碎（而我们不知道F）。
2.题目所说的“最坏的情况”，也就是这个F值是一个最坏的情况。它通过我们在楼层i（任意一层）测试时，鸡蛋碎或者没碎来体现。
> getMax(helper(K,N-i,mem),helper(K,i-1,mem)) // $1表示没碎，那就去更高层。$2表示碎了，那就去更低层

3.而题目所说的最小移动次数由我们每次试验选择的楼层所决定

> getMin(res,getMax(helper(K,N-i,mem),helper(K,i-1,mem))) //res表示从其它可用层开始搜索的情况下的最小尝试次数，如果从当前层i开始搜索的最小尝试数比res小，则替换

### 代码

```golang
func superEggDrop(K int, N int) int {
    if K == 1 {
        return N
    }
    if K == 0 {
        return 0
    }
    mem := make(map[string]int)
    res := helper(K,N,&mem)
    return res
}

func helper(K int,N int,mem *map[string]int) int {
    if K == 1 {
        return N
    }
    if N == 0 {
        return 0
    }
    var (
        res = math.MaxInt32
        temp = fmt.Sprintf("%d,%d",K,N)
        l = 1
        r = N
    )
    if (*mem)[temp] != 0 {
        return (*mem)[temp]
    }
    for l <= r{
        i := l + (r-l) >> 1
        notbroken := helper(K,N-i,mem)
        broken := helper(K-1,i-1,mem)
        res = getMin(res,getMax(notbroken,broken)+1)
        if notbroken > broken {
            l = i + 1
        }else {
            r = i - 1
        }
    }
    (*mem)[temp] = res
    return res
}

func getMin(i,j int)int{
    if i < j {
        return i
    }
    return j
}

func getMax(i,j int) int {
    if i < j {
        return j
    }
    return i
}
```
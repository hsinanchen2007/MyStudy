# 本题可以理解为84题的变形题，所用思路有两种
##1、使用单调栈实现（推荐）
##2、使用动态规划实现
## 本题可以使用典型的动态规划实现（我推不出来），看了答案才看懂，实在是有点不好理解
## 此时如果使用单调栈实现，和84题的思路很类似。区别只是将矩阵的每一行进行84题的处理即可
## 而且单调栈的方法可以解决84、85、221题，一个方法通吃三个题，还是很划算的，而且和动态规划的复制度差别不大
## 在面试时，与其去想动态规划，不如使用单调栈实现。当然掌握两种方法那就更好了

```
//单调栈实现
func maximalRectangle(matrix [][]byte) int {
    if matrix==nil || len(matrix)==0{
        return 0
    }
    //保存最终结果
    max:=0
    //行数，列数
    m,n:=len(matrix),len(matrix[0])
    //高度数组（统计每一行中1的高度）
    height:=make([]int,n)
    for i:=0;i<m;i++{
        for j:=0;j<n;j++{
            //每一行去找1的高度
            //如果不是‘1’，则将当前高度置为0
            if matrix[i][j]=='0'{
                height[j]=0
            }else{
                //是‘1’，则将高度加1
                height[j]=height[j]+1
            }
        }
        //更新最大矩形的面积
        max=int(math.Max(float64(max),float64(maxRectangle(height))))
    }
    return max
}
//使用84题的结果
func maxRectangle(heights []int)int{
    //最大矩形面积
    maxarea:=0
    //定义栈
    stack:=make([]int,0)
    //放入-1在栈底是为了:如果矩形包括索引为0处的柱子，则左边界为0的左边，方便计算左边界的索引
    stack=append(stack,-1)
    for i:=0;i<len(heights);i++{
        //当下一个柱子的高度小于当前栈顶柱子的高度
        for stack[len(stack)-1]!=-1 && heights[stack[len(stack)-1]]>=heights[i]{
            //得到当前栈顶元素的索引
            tmp:=stack[len(stack)-1]
            //出栈
            stack=stack[:len(stack)-1]
            //更新面积
            maxarea=int(math.Max(float64(maxarea),float64(heights[tmp]*(i-stack[len(stack)-1]-1))))
        }
        //当新加入柱子的高度大于栈顶柱子的高度（满足升序）
        stack=append(stack,i)
    }
    //当遍历完数组时，判断栈是否为空
    for stack[len(stack)-1]!=-1{
        //得到当前栈顶元素索引
        tmp:=stack[len(stack)-1]
        //出栈
        stack=stack[:len(stack)-1]
        //更新面积
        maxarea=int(math.Max(float64(maxarea),float64(heights[tmp]*(len(heights)-1-stack[len(stack)-1]))))
    }
    return maxarea
}

```


```
//动态规划（太菜了，照着官方解释看懂的，估计过几天又忘了）
func maximalRectangle(matrix [][]byte) int {
    if matrix==nil || len(matrix)==0{
        return 0
    }
    //保存结果
    maxarea:=0
    m,n:=len(matrix),len(matrix[0])
    height:=make([]int,n)
    left:=make([]int,n)
    right:=make([]int,n)
    //初始化
    for i:=0;i<n;i++{
        right[i]=n
    }
    for i:=0;i<m;i++{
        cur_left,cur_right:=0,n
        //更新height
        for j:=0;j<n;j++{
            if matrix[i][j]=='1'{
                height[j]++
            }else{
                height[j]=0
            }
        }
        //更新left
        for j:=0;j<n;j++{
            if matrix[i][j]=='1'{
                left[j]=int(math.Max(float64(left[j]),float64(cur_left)))
            }else{
                left[j]=0
                cur_left=j+1
            }
        }
        //更新right
        for j:=n-1;j>=0;j--{
            if matrix[i][j]=='1'{
                right[j]=int(math.Min(float64(right[j]),float64(cur_right)))
            }else{
                right[j]=n
                cur_right=j
            }
        }
        //更新最大面积
        for j:=0;j<n;j++{
            maxarea=int(math.Max(float64(maxarea),float64(height[j]*(right[j]-left[j]))))
        }
    }
    return maxarea
}
```

## 代码如有问题，欢迎指正



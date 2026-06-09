### 解题思路
接完雨水，很容易看出这个数组有什么特点，就像一个山峰一样。
在最大值左边不严格递增，右边不严格递减。
因此只需要把原数组变成符合这样要求的数组就行了，改变的量就是接的雨水。

具体实现只需要先找到最大值索引，左右各自遍历一遍
两边都维护一个值来表示之前的最大值以保证单调性，
如果比最大值小，雨水量就加上这个差值，
如果大于等于，就更新最大值。

作者：duan-she-chi-8
链接：https://leetcode-cn.com/problems/trapping-rain-water/solution/zhao-gui-lu-tou-guo-xian-xiang-kan-ben-zhi-by-duan/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


"我来解释一下答主的思路，原谅我的理解能力，，，刚开始确实没太看懂答主啥意思。 解释：题中给出了图片,类似柱状图一样，当接雨水完毕后，从左到最高的柱子是一非严格增高的,从最高的柱子到最右边又是非严格降低的。非严格递增的在这里就是允许存在height[i]=height[i+1]，但决不允许height[i]>height[i+1]。"

### 代码

```golang
//找到最大值
//最大值左边非严格递增
//最大值右边非严格递减
func trap(height []int) int {
    n:=len(height)
    if n == 0 {
        return 0
    }
    m:=max(height)

    water:=0

    //从0到最大值
     left:=height[0]
     for i:=1;i<m;i++ {
         if left > height[i] {
             water += left - height[i]
         }else {
             left = height[i]
         }
     }

     //从最大值到结尾
     right:=height[n-1]
     for j:=n-2;j>m;j-- {
         if right > height[j] {
             water+=right-height[j]
         }else {
             right=height[j]
         }
     }

return water
}

func max(arr []int) int {
    m:=0
    index:=0
    for k,v:=range arr {
        if v>m {
            m = v
            index = k
        }
    }
    return index
}
```
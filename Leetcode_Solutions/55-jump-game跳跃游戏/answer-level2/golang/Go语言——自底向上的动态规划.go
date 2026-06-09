### 解题思路
参考官方思路中自底向上的动态规划接法，给出Go语言代码
算法思路：
    从低端开始查找，每到一个位置，首先判断从这个位置开始可以跳到的最远距离，然后搜索这段距离中是否有可以跳到终点的位置，如果有，则标记这个位置为Good，没有，则此位置还是UnKnow，最后判断arr[0]的状态。
算法步骤：
    1.选定初始条件,最后一个位置一定可以跳到自身arr[len(nums)-1]==true
    2.开始动态规划：
        2.1 对每一个位置i，首先判断从这个位置开始可以跳到的最远距离further
        2.2 对从这个位置的下一个位置j开始，到最远距离，判断是否有可到达终点的位置j，如果有，将这个位置i标记成Good
    3.结束条件，第一个位置是否为Good

### 代码

```golang
type state uint8  //go语言的枚举实现方式
const (
    Good state = iota
    UnKnow
)

func canJump(nums []int) bool {
    arr:=make([]state,len(nums))
    for i,_:=range arr{
        arr[i]=UnKnow
    }
    //1 初始条件
    arr[len(nums)-1]=Good
    //2 开始动态规划
    for i:=len(nums)-2;i>=0;i--{
        //2.1 i位置的最远距离
        further:=min(i+nums[i],len(nums)-1)
        //2.2 i——further这段是否有可到终点的位置
        for j:=i+1;j<=further;j++{
            if arr[j]==Good{
                arr[i]=Good
            }
        }
    }
    return arr[0]==Good
}

func min(a,b int) int{
    if a<b{
        return a
    }
    return b

}

```
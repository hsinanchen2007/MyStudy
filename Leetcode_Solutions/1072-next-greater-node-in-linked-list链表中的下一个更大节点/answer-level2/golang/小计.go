    本道题算是在力扣上正式的第一题，记录一下思路。题目意思大概就是找出本值后面第一个大于本值的数作为对应下标的结果，如果没有则为0。
    给我的第一个感觉就是用简单粗暴的嵌套遍历，但是想着第一次做题，不能用太粗暴的方式，于是想了想，就是发现从左至右，是没有思考出比较友好的方式，但是从右至左进行遍历就不一样了。从右至左开始进行遍历的话，是能够知道右边已经遍历的每个元素，以及右边遍历的每个元素后面第一个大于本值的元素值。把这个发现用数学公式给表述出来就有如下几种结果，用n[],r[]分表表示元素与结果，元素长度为k，当遍历至i时，说明i、i+1--k元素的结果都已经得到，如果n[i]<n[i+1]则，r[i]=n[i+1],如果n[i+1]<n[i]<r[i+1]，则r[i]=r[i+1]，如果n[i]>r[i+1]，则在将n[i]与n[i+2]以及r[i+2]进行比较，直到n[k]，如果没有找到则r[i]=0
    在最后一次提交中引用了最大值，如果n[i]>max，直接说明r[i]=0，这个会在一些条件下极大的缩短运行时间。

var max int
func nextLargerNodes(head *ListNode) []int {
    var next *ListNode
    next=head
    vars:=make([]int,0)
    for ;next!=nil;{
        vars=append(vars,next.Val)
        next=next.Next
    }
    length:=len(vars)
    result:=make([]int,length)
    result[length-1]=0
    max=vars[length-1]
    for index:=length-2;index>-1;index--{
        if vars[index]>max{
            result[index]=0
            max=vars[index]
            continue
        }
        for k:=index;k<length-1;k++{
            if vars[index]<vars[k+1]{
                result[index]=vars[k+1]
                break
            }

            if vars[index]<result[k+1]{
                result[index]=result[k+1]
                break
            }
        }
    }
   return result
}
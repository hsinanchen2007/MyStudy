### 解题思路
本题要求用三种方法解答，由于需要循环移动，所以k有可能大于len(nums),所以k需要对len(nums)取余.
方法一。
使用一个临时数组，长度为原来的二倍，将原数组拷贝两次。比如[1,2,3,4,5,6,7],变成[1,2,3,4,5,6,7,1,2,3,4,5,6,7]，且k=3，然后从len(nums)-k的位置开始拷贝len(nums)个数据到nums中。

### 代码

```golang
func rotate(nums []int, k int)  {
    k=k%len(nums)

    res:=[]int{}
    res=append(res,nums...)
    res=append(res,nums...)

    j:=0
    for i:=len(nums)-k;i<len(nums)*2-k;i++{
        nums[j]=res[i]
        j++
    }
}
```
时间：O(n)
空间：O(2n)

方法二。
将原数组拷贝一遍，从len(nums)-k的位置开始复制到nums中，复制到尾端后，从拷贝后的数组中重新复制。
```
func rotate(nums []int, k int)  {
    k=k%len(nums)
    back:=make([]int,len(nums))
    copy(back,nums)

    j:=0
    for i:=len(nums)-k;i<len(nums);i++{
        nums[j]=back[i]
        j++
    }
    a:=0
    for i:=j;i<len(nums);i++{
        nums[i]=back[a]
        a++
    } 
}
```
时间:O(n)
空间:O(n)

方法三。
不拷贝原数组，从len(nums)-k处开始，依次将数据移到数组首位置，使用双指针，i记录要移入的位置，j记录需要的数据的位置，然后将i与j之间的数据向后移动一次，完成之后i++,j++。
```
func rotate(nums []int, k int)  {
    i:=0;
    k=k%len(nums)
    for beg:=len(nums)-k;beg<len(nums);beg++{
        tmp:=nums[beg]
        for j:=beg;j>i;j--{
            nums[j]=nums[j-1]
        }
        nums[i]=tmp
        i++
    }
}
```
时间：O(n)
空间：O(1)


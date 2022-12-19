### 解题思路
用n1、n2分别记录前、后节的1的个数
每当遇到0的时候，数值平移，n2=n1，n1=0（n2接收n1的值，n1初始化重新开始计数）
这样如果接连遇到2个0就会全部重置为0，间隔1个0的话就会在遇到下个0的时候仍存储前后的1个数
所以，每次遇到0的时候判断最多的1的个数max就可以了
### 代码

```golang
func reverseBits(num int) int {
    max,n1,n2:=0,0,0
    for {
        if num&1==1{
            n1++
        }else{
            if 1+n1+n2>max {max=1+n1+n2}
            if num==0 {break}
            n2=n1
            n1=0
        }
        num>>=1
    }
    return max
}
```
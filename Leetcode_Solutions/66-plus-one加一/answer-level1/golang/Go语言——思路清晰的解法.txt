### 解题思路
本题的难点在于进位的处理。如果没有进位，只需在末位加一即可，对于有进位的情况，首先需要用一个标志位记录下进位值，然后对于[9,9,9]这样的数组，末位加一后变成[1,0,0,0]四位数，本题采用的形式是预先申请多一位的切片，如果最后flag==1,将切片首位填1.如果flag==0，将切片首位填0。算法有些冗杂，下面做一下梳理。
算法过程：
1. 申请len(digits)+1的切片
2. 对最后元素进行加1，并记下标志位的状态flag
3. 开始从倒数第二个开始对flag+digits[i]的值进行判断，跟新flag和res
4. 对于的flag若等于1，将res[0]=1;若flag==0，将res[0]=0

### 代码

```golang
func plusOne(digits []int) []int {
    //1 申请预定义数组
    res:=make([]int,len(digits)+1)
    if len(digits)<=0{
        return []int{}
    }
    //2 对最后一个数加1，并更新flag和res的值
    flag:=0
    if digits[len(digits)-1]+1>=10{
        flag=1
        res[len(digits)]=digits[len(digits)-1]+1-10
    }else{
        flag=0
        res[len(digits)]=digits[len(digits)-1]+1
    }
    //3 从倒数第二个开始对flag+digits[i]进行判断
    for i:=len(digits)-2;i>=0;i--{
        if flag+digits[i]>=10{
            res[i+1]=flag+digits[i]-10
            flag=1
        }else{            
            res[i+1]=flag+digits[i]
            flag=0
        }
    }
    //4 对剩余的flag进行判断
    if flag==1{
        res[0]=1
        return res
    }else{
        return res[1:]
    }
}
```
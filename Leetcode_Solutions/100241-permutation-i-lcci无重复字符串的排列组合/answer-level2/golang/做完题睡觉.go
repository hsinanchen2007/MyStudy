### 解题思路
搜索，好像是离散数学中的一种路径集合啥的，忘记了
大概就是  abcd组成：
a|b|c|d---->a|b|c|d---->...--->a|b|c|d
选第i个字母时候从前往后判断当前字母是否使用过，没使用过就使用，否则判断后一个字母，
直到所有字母都选择了，得到一个元素
每次得到一个元素后进行回溯
（效率不是很好）

### 代码

```golang
// 结果集
var a []string
//判断第 i 个字符是否使用过
var tmp []bool
//字符串长度
var length int
func permutation(S string) []string {
   tmp=make([]bool,10) 
   a=make([]string,0)
   length=len(S)
    slice:=[]byte(S)
    s:=make([]byte,length)
    Todo(slice,s,0)
    return a

}

func Todo(slice,s []byte,num int){
    if num==length{
        a=append(a,string(s))
        return
    }
    for i:=0;i<length;i++{
        if !tmp[i]{
            tmp[i]=true
            //选择第 i 个字符作为当前元素的第 num 个字母
            s[num]=slice[i]
            Todo(slice,s,num+1)
            //改回原来的状态，回溯
            tmp[i]=false
        }
    }
}


```
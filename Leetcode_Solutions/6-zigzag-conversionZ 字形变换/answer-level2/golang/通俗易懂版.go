第一次写题解，有问题可评论~~
如例所示：
![捕获.PNG](https://pic.leetcode-cn.com/b0936dfc42c0fcf7d71132db371cd2a08925ec085aa541415c046b3e46b843a9-%E6%8D%95%E8%8E%B7.PNG)

可将 **PAYP**看成一个周期，**ALIS**一个周期，**HIRI**一个周期...
每个周期看成两步：
1. 第一步为往下走，如PAY,ALI,HIR...
2. 第二步为往回走，如P,S,I...

因此可遍历s的每一个字符，一个周期一个周期，依次将每个字符加入每一行的字符串的末尾。
```
func convert(s string, numRows int) string {
    length:=len(s)
    //numRows行空字符
    rows:=make([]string,numRows)
    i:=0
    for i<length{
        //往下走，注意下标起止，并且不能越界
        for j:=0;j<numRows&&i<length;j++{
            rows[j]+=s[i:i+1]
            i++
        }
        //往回走，注意下标起止，不能越界
        for j:=numRows-2;j>0&&i<length;j--{
            rows[j]+=s[i:i+1]
            i++
        }
    }
    res:=""
    //合成最终字符串
    for i=0;i<numRows;i++{
        res+=rows[i]
    }
    return res
}
```

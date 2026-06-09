### 解题思路
动态规划思路，根据官方题解的提示实现答案。

二维dp数组，纵轴表示的想要寻找的回文子串的长度，横轴表示以这个下标为最后一个元素的子串，
那么：dp[l][end] 表示这个长度为 l , 并且以s[end] 结尾的子串是否为回文子串。

初始化，dp[0][end] 的值均为false

边界处理:
1.len(s) == 0 单独处理，直接返回；

2.寻找 l = 1 时的子串，每个都为true

3.寻找 l = 2 时的子串，只需要判断相邻的两个是否相同

4.寻找 l >= 3 的子串，此时先判断头尾是否相同，
若相同则判断位于首尾之间的 dp[l-2][end-1]的情况，若dp[l-2][end-1]=true则dp[l][end]=true,否则为false；
若不相同，则直接为false；

注意：因为二维数组长度设置的问题，实现中: l=0 即表示长度为1，l=2即表示长度为2.。。
可以按自己实际设置的二维数组的情况具体处理。

### 代码

```golang
func longestPalindrome(s string) string {
    if len(s) == 0{
        return s
    }
    //创建dp数组记录子串情况
    //y轴为length:子串长度
    //x轴为end:记录以这个下标为最后一个字符的子串
    //dp含义:每个格子表示-->以end结尾的长度为length的子串是否为回文子串
    dp := make([][]bool,len(s))
    y := 0
    x := 0
    for i:=0;i<len(s);i++ {
        tmp := make([]bool,len(s))
        if i == 0 {
            for j:=0;j<len(s);j++{
                //初始化dp表
                //回文子串长度为1的情况
                tmp[j] = true
            }
        }
        dp[i] = tmp
    }
    //l为纵轴，子串长度
    //end为横轴，子串结束下标
    //
    for l:=1;l<len(s);l++ {
        for end:=l;end<len(s);end++ {
            if s[end] != s[end-l] {
                dp[l][end] = false
            } else {
                //寻找长度为2的回文子串
                if l < 2 {
                    dp[l][end] = true
                    y = l
                    x = end
                } else if dp[l-2][end-1] { //寻找长度大于等于3的回文子串
                    dp[l][end] = true
                    //更新x 和 y，因为每一趟的 l 只会大于等于之前的y，所以更新的y必是最大
                    y = l
                    x = end
                }
            }
        }
    }
    res := s[x-y:x+1]
    return res
}
```
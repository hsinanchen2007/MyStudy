### 解题思路
![2.PNG](https://pic.leetcode-cn.com/a1e8e9742aff37e94a15a1bacd30b2b5e0aa29db5ef90b17d5fdcccdc04670b0-2.PNG)

首先建立一个map，统计每个字母出现的次数，然后遍历map，value只要能被2除，我们就把value/2的结果记录下来，这都是可以拼凑在回文串两边的字符，然后我们只需要判断有没有单数，有的话就是记录的结果乘二加一，没有的话直接结果乘二即可。

### 代码

```golang
func longestPalindrome(s string) int {
    map1 := make(map[byte]int)
    for i:=0;i<len(s);i++{
        map1[s[i]]+=1
    }
    flag:=0
    sum :=0
    for _,value:= range map1{
        sum+=value/2
        if value%2==1{
            flag=1
        }
    }
    return 2*sum+flag
}
```
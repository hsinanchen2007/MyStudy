### 解题思路
依题意：
按照字符串首字母进行匹配；
设置一个map，分别存放以a-z首字母开头的字符串；
设置一个sort二维数组，sort[i][j]表示长度为i的字符串位于原words数组的位置。
这样就很方便按字符串长度从大到小进行判断。
如例子：
["cat","banana","dog","nana","walk","walker","dogwalker"]
得到这样的map:
[b:[banana] c:[cat] d:[dog dogwalker] n:[nana] w:[walk walker]]
这样的sort:
[[] [] [] [0 2] [3 4] [] [1 5] [] [] [6]]
设置一个哨兵max，在建立map和sort的就记录字符串的最长长度，这个例子max = 6.

然后从len(words[i]) = 6 的字符串开始进行判断:
即为： dogwalker。
首字母为d，则在d:[dog dogwalker]，此时为防止找到错误将自己也当作是组成单词的一部分，在判断某个字符串是不是最长单词时，先将判断的这个字符串删除处理，于是有：
d:[dog ""]
而且删除之后的元素不需要再恢复，因为我们总是判断这个时候最长的字符串符不符合条件，所以这个串是永远不可能组成其他串的，所以可以放心删除。
找到dog <-> dog walker 之后，将dogwalker拆分，再查找walker是否符合要求。
w:[walk walker]：存在walker，能够组成walker，于是返回dogwalker。
注意：按照字典序输出结果，在长度相等的情况下进行字典序比较，否则总是输出最长的。


递归分析:
    递归--将大问题分解成小问题，并将小问题的解返回拼凑成最终解。
终止条件:当字符串s长度为0，即完全能够被分解，就返回true，否则返回false；
每一个子递归向上返回自己拆分的情况，都为true则返回true；
有一个为false，若上一级字符串还能有拆分的情况，则继续拆分，不能拆分则返回false给上上一级


![image.png](https://pic.leetcode-cn.com/5502b338ea5d80f2327df9404dd759e805a25ea52b00493f4778100f09646d3d-image.png)



### 代码

```golang
func longestWord(words []string) string {

    m := make(map[string][]string)
    sort := make([][]int,10000)

    max := 0
    res := ""

    for k,v := range words {
        if len(v)>0 {
            m[v[0:1]] = append(m[v[0:1]],v)
            sort[len(v)] = append(sort[len(v)],k)
            if max < len(v) {
                max = len(v)
            }
        }
    }

    for i:=max;i>0;i-- {
        for _,v := range sort[i] {
            s := words[v]
            //先在m中删除需要判断的这个字符串
            //因为是按照长度从大到小进行判断，所以判断的此时最长的串就可以丢弃
            c := s[0:1]
            for k,j := range m[c] {
                if j == s {
                    m[c][k] = ""
                }
            }
            if Run(m,s) {
                if len(s) < len(res) {
                    return res
                }
                res = CompareString(res,s)
            }
        }
    }
    return res
}

func Run(m map[string][]string,s string) bool {

    if len(s) == 0{
        return true
    }
    flag := false
    c := s[0:1]
    for _,v := range m[c] {
        if v == "" || len(v) > len(s) || s[:len(v)] != v{
            continue
        }
        t := s[len(v):]
        flag = Run(m,t)
        if flag {
            return true
        }
    }
    return flag
}
func CompareString(i,j string) string {
    if len(i) > len(j) {
        return i
    } else {
        return j
    }
    if i!="" && j!="" {
        if i<j {
            return i
        } else {
            return j
        }
    } else if i == "" && j!="" {
        return j
    } else if i != "" && j=="" {
        return i
    }
    return ""
}

```
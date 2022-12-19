### 解题思路

![image.png](https://pic.leetcode-cn.com/1722b95147134c8034419e8d66ada72e5f6753e5f4cce9df3357c1ddc3507a05-image.png)

### 代码
```golang
func permutation(S string) []string {
    var SS []string
    Per(&SS,[]byte(S),0)
    return SS
}
func Per(SS*[]string,S []byte , index int ){
    if index == len(S){
        *SS = append(*SS,string(S))
        return 
    }
    for i:= index;i<len(S);i++{
        S[i],S[index] = S[index],S[i]
        Per(SS,S,index + 1)
        S[i],S[index] = S[index], S[i]
    }
}
```
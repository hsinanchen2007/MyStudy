### 解题思路
若 n \& 1 = 1n&1=1 ，则 nn 二进制 最右一位 为 11 
### 代码

```golang
func hammingWeight(num uint32) int {
    ans := 0
    for ;num >0;num = num >> 1{
        if num & 1 == 1{
            ans++
        }
    }
    return ans
    
}
```
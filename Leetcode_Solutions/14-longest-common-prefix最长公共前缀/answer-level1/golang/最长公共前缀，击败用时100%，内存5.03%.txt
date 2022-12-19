### 解题思路
1. 首先思路因为是最长前缀，因此需要遍历字符串数组，从每个字符串第一位开始比对
2. 空数组判断
3. 使用rune来遍历字符串。因为在字符串不同的遍历中（for range , for i, 直接字符串取位等等）可能存在取出来的字符是不同类型(int32, uint8等)
4. 简单粗暴两个循环遍历
5. 比对过程发现超过下标的、或不相同的，直接返回，完成

执行用时 :0 ms, 在所有 Go 提交中击败了100.00% 的用户
内存消耗 :6.3 MB, 在所有 Go 提交中击败了5.03%的用户


### 代码

```golang
func longestCommonPrefix(strs []string) string {
    result := []rune{}
    if len(strs) == 0{
        return ""
    }
	LOOP1:for key, value := range []rune(strs[0]){
		for _, v := range strs{
			if key+1 > len(v){
				break LOOP1
			}

			if value != []rune(v)[key]{
				break LOOP1
			}
		}
		result = append(result, value)
	}
    return string(result)
}
```
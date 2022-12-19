### 解题思路
![TIM图片20200405101614.png](https://pic.leetcode-cn.com/af524cc293eba3c6e9b4a2e1c2858acd2000eddefce82745d9507982315f2d97-TIM%E5%9B%BE%E7%89%8720200405101614.png)


### 代码

```golang
func longestCommonPrefix(strs []string) string {
	var result string
	if len(strs) == 0 {
		return result
	}
	if len(strs)<2 {
		return strs[0]
	}
	result = strs[0]
	for i:=1; i<len(strs); i++{
		if len(strs[i])<len(result){
			result = strs[i]
		}
	}
	var j = len(result)
	LOOP:
	for j>=0{
		for k:=0;k<len(strs) ;k++  {
			if !compare(result[:j], strs[k]) {
				j--
				goto LOOP
			}
		}
		return result[:j]
	}
	return result
}

func compare(str1 string, str2 string) bool{
	for i:=0;i<len(str1) ;i++{
		if str1[i] != str2[i] {
			return false
		}
	}
	return true
}
```
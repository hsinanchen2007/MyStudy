### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/40e1db71a90dd12f5d08e5a3b34e073853ceaa1923f6a9973722158083225988-image.png)

### 代码

```golang
func compressString(S string) string {
	var ans = make([]string,0)
	var before = 0
	var mid = 1
	var count = 1
	var after = len(S)
    var str = ""
	for before < after{
		if mid == after{
			ans = append(ans,string(S[before]))
			ans = append(ans,strconv.Itoa(count))
			break
		}
		if mid<after && S[before]!=S[mid]{
			ans = append(ans,string(S[before]))
			ans = append(ans,strconv.Itoa(count))
			count = 1
			before = mid
			mid++
		}else{
			mid++
			count++
		}
	}
	if len(S)<=len(ans){
		return S
	}else{
		for i:=0;i<len(ans);i++{
			str = str + ans[i]
		}
	}
	return str
}
```
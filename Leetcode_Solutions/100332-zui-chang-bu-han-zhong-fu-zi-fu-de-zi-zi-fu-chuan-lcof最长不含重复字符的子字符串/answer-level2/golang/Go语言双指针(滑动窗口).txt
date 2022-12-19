### 解题思路
此处撰写解题思路

### 代码

```golang
func lengthOfLongestSubstring(s string) int {
	if len(s) == 1||len(s)==0{//特殊情况
		return len(s)
	}
	 var lenofs = len(s)
	 var sliceLen = make([]int,0)


	 	 var mid = 0
		 var tempstr = string(s[mid])
	 	var fast = mid+1
	 	for fast < lenofs{
	 		if strings.Contains(string(tempstr), string(s[fast])){
	 			sliceLen = append(sliceLen,len(tempstr))
	 			mid ++
	 			fast = mid + 1
	 			tempstr = string(s[mid])
			}else{
	 				tempstr = contact(string(tempstr), string(s[fast]))
	 				fast++
	 				if fast == lenofs{
						sliceLen = append(sliceLen,len(tempstr))
					}

			}
		}

	 sort.Ints(sliceLen)
	 return sliceLen[len(sliceLen)-1]
}

func contact(str1,str2 string) string{
	return str1+str2
}
```
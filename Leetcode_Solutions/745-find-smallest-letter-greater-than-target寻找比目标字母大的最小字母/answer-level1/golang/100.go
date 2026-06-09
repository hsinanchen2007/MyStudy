### 解题思路
此处撰写解题思路

### 代码

```golang
func nextGreatestLetter(letters []byte, target byte) byte {

	tmp:=letters[0]
	count:=byte(26)
	flag:=false
	for !flag{
		for i:=0;i< len(letters);i++{
			if letters[i]-target>0{
                //当 找到 比target大的字符的时候，置为 true，则下次可以跳出最外层循环
				flag=true
				if count>letters[i]-target{
					tmp=letters[i]
					count=letters[i]-target
				}
			}
		}
        //当在 数组中没有找到比 target大的字符的 时候，由于数组中字符都是循环的，可以看做所有字符增加26，也就是target减少26
		target-=26
	}
	return tmp
}
```
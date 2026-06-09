### 解题思路
用一个指针停在开始值，然后另外一个指针遍历，减少遍历次数
这种方法重复情况分两种，一种是第一个指针和当前指针的值重复，这种情况直接求指针位置差，就可以得到子串长度，对比当前最大子串长度，如果比当前的大则替换之
第二种情况是指针值不重复，但指针中间的值重复，这种情况，通过map key值唯一性进行判断
最后，根据重复的位置值和第一个指针的位置，判断是将指针右移一位，还是直接跳到当前位置，从新截取字符串长度。
最后返回 最终长度。缺点是字符串长度小于三的时候需要单独判断，并且如果直到最后一个值都没有重复，还要判断最后的值

### 代码

```golang
func lengthOfLongestSubstring(s string) int {
if len(s)==0{
		return 0
	}
	if len(s)==1 {
		return 1
	}
	if len(s)==2 {
		if s[0:1]==s[1:] {
			return 1
		}
		return 2
	}
	enum := make(map[string]int)
	/*a a a a a b c d f b b
	0 1 2 3 4 5 6 7*/
	/*a b */
	var length = 0
	var pos = 0
	for i:=1;i< len(s);i++  {
		if s[pos:pos+1]==s[i:i+1] {
			if i-pos >=length {
				length = i-pos
			}
			pos++
		}
		if _,ok:=enum[s[i:i+1]];ok{
				if i-pos >=length&&enum[s[i:i+1]]>pos {
					length = i-pos
				}
			if enum[s[i:i+1]]>pos {
				pos = enum[s[i:i+1]]+1
			}

		}
		if len(s)-1==i&&s[pos:pos+1]!=s[i:i+1] {
			if i-pos+1>length{
				length=i-pos+1
			}
		}
		enum[s[i:i+1]]=i
	}
	return length
}
```
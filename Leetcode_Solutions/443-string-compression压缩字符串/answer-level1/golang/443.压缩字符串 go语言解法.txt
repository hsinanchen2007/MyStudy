### 解题思路

双指针法，size代表压缩的当前位置。

### 代码

```golang
func compress(chars []byte) int {
	var left,right,size int = 0,0,0
	for ; right <= len(chars); right++ {
		if (right == len(chars) || chars[right] != chars[left]) {
			chars[size] = chars[left]
			size++
			if (right - left > 1) {
				l := strconv.Itoa(right-left)
				for i,_ := range l{
					chars[size] = l[i]
					size++;
				}
			}
			left = right;
		}
	}
	return size;
}
```
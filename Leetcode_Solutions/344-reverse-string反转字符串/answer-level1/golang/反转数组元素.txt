### 解题思路
利用双指针，一个从第一个元素开始，另一个从最后一个元素开始。持续交换他们所指向的元素，直到这两个指针相遇。

### 代码

```golang
func reverseString(s []byte)  {
    l := len(s)
	if l < 2 {
        fmt.Println(s)
	}

	top, bottom := 0, l-1

	for top < bottom {
		s[top], s[bottom] = s[bottom], s[top]
		top++
		bottom--
	}

	fmt.Println(s)
}
```
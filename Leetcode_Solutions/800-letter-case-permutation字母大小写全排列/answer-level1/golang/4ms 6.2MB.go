### 完整代码
```
func letterCasePermutation(S string) []string {
	f := func(i byte)(lower, upper byte){
		if 'a'<= i && i <= 'z'{
			return i, i - 32
		}
		return i, i + 32
	}

	resultBuffer := make([]*bytes.Buffer, 0, len(S) )
	for i :=0; i < len(S); i++ {
		if  '0' <= S[i] && S[i] <= '9' { //数字
			if len(resultBuffer) == 0 {
				buf := &bytes.Buffer{}
				buf.WriteByte(S[i])
				resultBuffer = append(resultBuffer, buf)
				continue
			}
			for _, v := range resultBuffer{
				v.WriteByte(S[i])
			}
			continue
		}
		// 字符串
		lower, upper := f(S[i])
		if len(resultBuffer) == 0 { //初始化
			b := bytes.Buffer{}
			b.WriteByte(lower)
			b1 := bytes.Buffer{}
			b1.WriteByte(upper)
			resultBuffer = append(resultBuffer, &b, &b1)
			continue
		}
		appendResult := make([]*bytes.Buffer, len(resultBuffer), len(resultBuffer))
		for index, v := range resultBuffer {
			v1 := bytes.Buffer{}
			v1.WriteString(v.String())
			v.WriteByte(lower)
			v1.WriteByte(upper)
			appendResult[index] = &v1
		}
		resultBuffer = append(resultBuffer, appendResult...)
	}
	result := make([]string, len(resultBuffer), len(resultBuffer) )
	for index , v := range resultBuffer {
		result[index] = v.String()
	}
	return result
}
```
### 执行结果
![image.png](https://pic.leetcode-cn.com/dd9980efa37a7efa5071467303ac3a0338d94bf9adc3c788495098a5c0271376-image.png)


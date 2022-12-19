### 解题思路
![image.png](https://pic.leetcode-cn.com/fba0794fee6343e4ef2b3b3cce1d753d0111d789146befe03d0d6fe8f3c4cec6-image.png)

感觉是考递归吧，我刚学go不太熟 格式转换费点事 可能是用了buffer 所以内存消耗比较大 
主要想法就是调用n-1(就是上一次)的结果然后查数，记录 

### 代码

```golang
func countAndSay(n int) string {
	if n==1{
		return "1"
	}else{
		last := countAndSay(n-1)
		first := last[0]
		num := 1
		var buffer bytes.Buffer
		for i:=1;i<len(last);i++{
			if last[i] == first{
				//相等,计数就可以
				num++
			}else{
				//不相等,将上个记录的值和数写入buffer,更新新的值和数
				buffer.WriteString(strconv.Itoa(num))
				buffer.WriteString(string(first))
				first = last[i]
				num = 1
			}
		}
		//将最后记录写入
		buffer.WriteString(strconv.Itoa(num))
		buffer.WriteString(string(first))
		return buffer.String()
	}
} 
```
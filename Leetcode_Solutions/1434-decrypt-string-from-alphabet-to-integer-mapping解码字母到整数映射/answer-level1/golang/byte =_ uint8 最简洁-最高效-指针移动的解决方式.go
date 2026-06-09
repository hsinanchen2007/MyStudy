### byte 运算
![微信截图_20200111001624.png](https://pic.leetcode-cn.com/51ec52366651626550e154b53c3b0a8f5800d73962e5361c12fec5e9119dd7b6-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200111001624.png)

- 指针条约
- byte 是uint8 可以计算大小

### 代码

```golang
func freqAlphabets(s string) string {
	res := []byte{}
	ln := len(s)
	for i:=0;i<len(s);i++{
		if s[i] != '#' && i+2 < ln && s[i+2] == '#' {
			// 两位数字+# 模式
			nns := s[i:i+2]
			nn,_ := strconv.Atoi(nns)

			cb := 'j' + byte(nn-10)
			res = append(res,cb)
			//移动指针
			i+=2

		}else {
			//纯数字模式
			nb := s[i]-'1' + 'a'
			res = append(res,nb)
		}
	}
	return string(res)
}


```
### 解题思路
![微信截图_20200329182546.png](https://pic.leetcode-cn.com/b19cd622d8eaefd23b006f5b4e985ac882f99351a1b549a6fb2334f905f8db46-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200329182546.png)


- 比较较长的字符串
- 遍历较长字符串byte
- byte + byte
- 处理加法进位问题
- 特殊处理最高位进位
- []bytes -> string

### 代码

```golang

func addStrings(num1 string, num2 string) string {
	//指定num1是较长字符串
	ln1 := len(num1)
	ln2 := len(num2)
	if ln1 < ln2 {
		t := num1
		num1 = num2
		num2 = t

		tn := ln1
		ln1 = ln2
		ln2 = tn
	}
	//在num1的基础上预留一位
	ans := make([]byte, ln1+1)
	//进位 默认值 byte(0)
	var ten byte
	//num1 num2倒叙遍历
	for i := ln1 - 1; i >= 0; i-- {
		var a0 byte
		//num2 对应index
		j := i - (ln1 - ln2)
		if j >= 0 {
			ten, a0 = byteAdd(num1[i]+ten, num2[j])
		} else {
			//num2 byte ='0' 补足
			ten, a0 = byteAdd(num1[i]+ten, '0')
		}
		ans[i+1] = a0
	}
	//最高位进位值修剪
	if ten > 0 {
		ans[0] = '1'
		return string(ans)
	} else {
		//修剪多余的0
		return string(ans[1:])
	}
}

//两个byte相加
//返回值 进位值 int (1 or 0)
//acsii byte
func byteAdd(a, b byte) (byte, byte) {
	ans := a + b - '0' - '0'
	if ans >= 10 {
		return 1, ans + '0' - 10
	}
	return 0, ans + '0'
}

```
# 1. 思路

利用栈的思想。

- 用四个变量辅助：`stack, tmp, n, op`

-  `stack` ： 由于加减法的优先级没有乘除法高，当先出现加减法，再出现乘除法的时候，就用 `stack` 保存已经遍历过的加减法。

- `tmp`：存储已经遍历到的表达式。视情况(`op`)决定是否将其追加到`stack` 末尾

- `n`：存储当前遍历到的数字。

- `op`：存储的是上一个计算符，如果有的话。

  - `op` 是乘除符号，而当前遍历到加减法：说明`tmp` 里的表达式已有乘除法，需要计算`tmp = cal_tmp_cc(tmp)` 
  - `op` 是加减符号，而当前遍历到加减法：直接将当前遍历到的元素添加到`tmp` 
  - `op` 是乘除符号，而当前遍历到乘除法：同样计算整合`tmp` 里表达式的计算结果
  - `op` 是加减符号，而当前遍历到乘除法：当前遍历的表达式优先级高于之前遍历到的，于是将`tmp` 里的内容追加到`stack` 里，待最后再做加减法；而`tmp` 则用于存储当前优先级更高的表达式。
  - 每次遍历到`op`，都需要将`n` 添加到`tmp`里，并且置零，好用于之后的累加。
  - 加减法和乘除法的计算单独写了两个函数。

  

```
def calculate(s):
	s = "".join(s.split())
	stack, tmp = [], []
	n, op = 0, ''
	for c in range(len(s)) :
		if s[c] in  ["*", "/"]:

			if op in ["*", "/"]:
				tmp.append(n)
				tmp = cal_tmp_cc(tmp)
			elif tmp:
				stack += tmp
				tmp = []
				tmp.append(n)
			else: 
				tmp.append(n)

			op = s[c]
			n = 0
			tmp.append(s[c])
		elif s[c] in ["+", "-"]:
			if op in ["*", "/"]:
				tmp.append(n)
				tmp = cal_tmp_cc(tmp)
			else:
				tmp.append(n)
			op = s[c]
			tmp.append(s[c])
			n = 0
		elif "0" <= s[c] <= "9":
			n = n * 10 + int(s[c])
		print(s[c], n, op, stack, tmp)
	tmp.append(n)
	if op in ["*", "/"]:
		tmp = cal_tmp_cc(tmp)
	stack += tmp
	print(stack, tmp)
	return cal_tmp_jj(stack)


def cal_tmp_cc(tmp):
	if tmp[1] == "*":
		return [int(tmp[0]) * int(tmp[2])]
	else:
		return [int(tmp[0]) / int(tmp[2])]


def cal_tmp_jj(tmp):
	res = 0
	n = 0
	op = 1
	for t in range(len(tmp)):
		if tmp[t] == "+":
			res += n * op
			op = 1
			n = 0 
		elif tmp[t] == "-":
			res += n * op
			op = -1
			n = 0
		elif tmp[t] != "(":
			n = n * 10 + int(tmp[t])
	res += n * op
	return str(res)


```


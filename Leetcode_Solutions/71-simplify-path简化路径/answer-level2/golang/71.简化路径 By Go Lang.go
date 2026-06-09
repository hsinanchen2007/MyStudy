### 解题思路
用stack模拟目录的进退。
1. 用split分割一下。
2. 为空或者为"."，则skip。
3. ".."的情况，如果stack里面有值，则Pop栈顶。
4. 其余则Push入栈。
5. 最后Join一下。

### 代码

```golang

func simplifyPath(path string) string {
	buf := strings.Split(path, "/")
	var stack []string

	for i := 0; i < len(buf); i++ {
		if buf[i] == "" || buf[i] == "." {
			continue
		}
		if buf[i] == ".." {
			if len(stack) > 0 {
				stack = stack[0 : len(stack)-1]
			}
		} else {
			stack = append(stack, buf[i])
		}
	}

	return "/" + strings.Join(stack, "/")
}

```
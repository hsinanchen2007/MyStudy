1、只有当前不在注释块（注释行不算）内，才有必要往结果数组中添加；
2、非注释内容应该是有效位置到注释前的拼接；
这两点理解之后就比较简单了，其他无非就是对不同注释的处理操作。

```
func removeComments(source []string) []string {
	var strArr []string
	isBlock, str :=  false, ""
	for i := 0; i < len(source); i++ {
		isComment, index := false, 0
		if len(source[i]) >= 2 {
			for j := 0; j < len(source[i]) - 1; j++  {
				// 判断有效的注释行
				if source[i][j:j + 2] == "//" && !isBlock && j >= index {
					isComment = true
					str += source[i][index:j]
					index = len(source[i]) // 下一个有效位置
					break
				}

				// 判断有效的注释块开始
				if source[i][j:j + 2] == "/*" && !isBlock && j >= index{
					isComment, isBlock = true, true
					str += source[i][index:j]
					fmt.Printf("'`%s'\n", str)
					index = j + 2 // 下一个有效位置
				}

				// 判断有效的注释块结束
				if source[i][j:j + 2] == "*/" && isBlock && j >= index {
					isComment, isBlock = true, false
					index = j + 2 // 下一个有效位置
				}
			}
		}

		//不在注释块中才写入
		if !isBlock {
			if !isComment {
				strArr = append(strArr, source[i])
			} else {
				if 0 < index && index < len(source[i]) {
					str += source[i][index:len(source[i])]
				}
				if str != "" {
					strArr = append(strArr, str)
					str = ""
				}
			}
		}
	}
	return strArr
}
```

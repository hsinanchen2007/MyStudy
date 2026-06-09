
// 解法1：递归
// 从字符串末尾开始删除有效字符串，对剩余的字符串进行下一次删除，直到字符串变成空串

```
bool check(char* s, int len)
{
	// base case
	// 空串判断
	if (len == 0) {
		return true;
	} 
	if (len <= 2) {
		return false;
	}

	int pos = -1;   //  记录有效字符串的起始位置('a'的位置)
	// 从后往前找有效字符串，找到则将起始位置保存在pos，跳出for循环
	for (int i = len - 3; i >= 0; i--) {
		if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
			pos = i;
			break;
		}
	}
	// 如果遍历完s都没找到，那么说明无效
	if (pos == -1) {
		return false;
	}

	// 如果找到，那么就把"abc"以后的子串(包括结束符'\0')提前到pos的位置，相当于删除"abc"
	// s[len]就是'\0'
	for (int i = pos; i <= len - 3; i++) {
		s[i] = s[i + 3];
	}

	// 递归处理子串
	return check(s, len - 3);  // 删除"abc"以后，子串长度比原来小3
}

bool isValid(char * S)
{
	int len =  strlen(S);

    return check(S, len);
}
```

// 解法2：栈
// 遍历字符串，将除了'c'以外的字符入栈，直到遇到'c'，就弹栈，
// 弹出元素应该依次为'b'、'a'
// 栈stack只包含'a'和'b'，但个数不限

```
bool isValid(char * S)
{
	int len =  strlen(S);

	char stack[20000] = {0};
	int top = 0;

	for (int i = 0; i < len; i++) {
		// 将除了'c'以外的字符入栈
		if (S[i] != 'c') {
			stack[top++] = S[i];
		} else {	// 遇到'c'
			top--;  // 第一次弹栈
			if (top < 0 || stack[top] != 'b') {
				return false;
			}
			top--;  // 第二次弹栈
			if (top < 0 || stack[top] != 'a') {
				return false;
			}
		}
	}

	// 匹配完成，stack应为空栈
	return top ? false : true;
}
```

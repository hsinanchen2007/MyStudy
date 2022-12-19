### 解题思路
用栈模拟

### 代码
```golang []
func isValid(S string) bool {
	stack := make([]rune, 0)

	for _, c := range S {
		if c == 'c' {
			if len(stack) > 1 && stack[len(stack)-1] == 'b' && stack[len(stack)-2] == 'a' {
				stack = stack[:len(stack)-2]
			} else {
				return false
			}
		} else {
			stack = append(stack, c)
		}
	}
	return len(stack) == 0
}
```

```c []
bool isValid(char *S) {
    char *p = S;
    int len = 0;
    while (*p) {
        len++;
        p++;
    }
    char stack[len];
    int i = -1;
    p = S;
    while (*p) {
        if (*p == 'c') {
            if (i >= 1 && stack[i] == 'b' && stack[i - 1] == 'a') {
                i -= 2;
            } else {
                return false;
            }
        } else {
            stack[++i] = *p;
        }
        p++;
    }
    return i == -1;
}
```

```java []
class Solution {
    public boolean isValid(String s) {
        char[] stack = new char[s.length()];
        int i = -1;
        for (char c : s.toCharArray()) {
            if (c == 'c') {
                if (i >= 1 && stack[i] == 'b' && stack[i - 1] == 'a') {
                    i -= 2;
                } else {
                    return false;
                }
            } else {
                stack[++i] = c;
            } 
        }
        return i == -1;
    }
}
```
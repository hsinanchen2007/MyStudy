### 解题思路
此处撰写解题思路

### 代码

```c
bool findInStack(char buff[], int top, int val)
{
    for (int i = 0; i <= top; i++) {
        if (buff[i] == val) {
            return true;
        }
    }
    return false;
}
char* removeDuplicateLetters(char *s)
{
    if (s == NULL) {
        return NULL;
    }

    int i;
    int len = strlen(s);
    int hash[26] = { 0 };
    int used[26] = { 0 };
    char stack[26] = { 0 };
    int top = -1;

    for (i = 0; i < len; i++) {
        hash[s[i]-'a']++;
    }

	for (i = 0; i < len; i++) {
        if (used[s[i] - 'a'] == 1) {
            hash[s[i] - 'a']--;
            continue;
        }

        // 当前栈不为空，且即将加入数据比栈顶数据小，且栈顶数据个数不止一个（即后面还有栈顶元素），那么就将栈顶元素先抛弃，
        // 依次寻找，直到即将加入数据满足要求（要么当前数据比栈顶大，或者当前栈顶元素已经是唯一的一个）
        while (top > -1 && stack[top] > s[i] && hash[stack[top] - 'a'] >= 1) {
            used[stack[top] - 'a'] = 0;
            top--;
        }
        
        stack[++top] = s[i];
        used[s[i] - 'a'] = 1;
        hash[stack[top] - 'a']--;
	}

    char *rlt = (char *)malloc(sizeof(char) *(top + 2));
    for (i = 0; i <= top; i++) {
        rlt[i] = stack[i];
    }
    rlt[top + 1] = 0;
    return rlt;
}

```
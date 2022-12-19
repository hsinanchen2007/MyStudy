![image.png](https://pic.leetcode-cn.com/42e73a2eec855816e2e837a93bbd8f6d384fa823e6547a29d558da77eb64bf1b-image.png)

```
bottom 的长度范围在 [2, 8]。
allowed 的长度范围在[0, 200]。
方块的标记字母范围为{'A', 'B', 'C', 'D', 'E', 'F', 'G'}。



通过状态压缩，实现暴力穷举找到第一条可行的递归路径。

1. 只有7个字母 {'A', 'B', 'C', 'D', 'E', 'F', 'G'}, 可以使用一个字节来表示每个字母
    00000001 => 'A'
    00000010 => 'B'
    00000100 => 'C'
    00001000 => 'D'
    00010000 => 'E'
    00100000 => 'F'
    01000000 => 'G'

2. 创建一个二维数组g_state[65][65] 来记录 前两个字母可以转换成第三个字母的所有可能
    比如 
    g_state[00000001('A')][00000010('B')] = 00000001('A')             // 表示记录了ABA
    g_state[00000001('A')][00000010('B')] = 00000101('A' | 'C')       // 表示记录了ABA ABC
    g_state[00000001('A')][00000010('B')] = 10000101('A' | 'C' | 'G') // 表示记录了ABA ABC ABG

3. 有了g_state记录着前两个字母转换的所有可能, 就可以进行DFS穷举遍历了, 具体思路如下

    用例： bottom = "BCD", allowed = ["BCG", "CDE", "GEA", "BCF"]
    g_state的内容为
        g_state[00000010('B')][00000100('C')] = 01100000('G' | 'F')
        g_state[00000010('C')][00000100('D')] = 00010000('E')
        g_state[00000010('G')][00000100('E')] = 00000001('A')

    进行DFS遍历
        BCD  前两个字符BC可以转换的可能为 01100000('G' | 'F')。 
            取出最右侧的1, 取log, 再加'A'  取出'F'   =>  此时第一个字符换成 'F' => FCD
                接着考虑 CD 可以转换成E              =>  此时第二个字符换成 'E' => FED
                    已经不能再取出两个字符了, 说明进入了下一层, len为2, 字符串为 FE
                        FE不能转换成别的, 进行回溯

            删掉最右侧的1（上一次递归已经取过了）, 取出最右侧的1, 取log, 再加'A'  取出'G'   =>  此时第一个字符换成 'G' => GCD
                接着考虑 CD 可以转换成E              =>  此时第二个字符换成 'E' => GED
                    已经不能再取出两个字符了, 说明进入了下一层, len为2, 字符串为 GE
                        GE能转换成'A'
                            字符串长度变成了1, 说明可以到塔尖, 返回true
```


```c
#define SIZE 65
uint32_t g_state[SIZE][SIZE];

#define GET_RIGHT_MOST_BIT(x_) ((x_) & (-x_))
#define DEL_RIGHT_MOST_BIT(x_) ((x_) &= (x_ - 1))
#define POWER2(x_) (1 << (x_))

unsigned int Log2(unsigned int num)
{
    unsigned int log2 = (num & 0xAAAAAAAA) != 0;
    log2 |= ((num & 0xFFFF0000) != 0) << 4;
    log2 |= ((num & 0xFF00FF00) != 0) << 3;
    log2 |= ((num & 0xF0F0F0F0) != 0) << 2;
    log2 |= ((num & 0xCCCCCCCC) != 0) << 1;
    return log2;
}

bool Dfs(char* str, int index, int len)
{
    if (len == 1) {
        return true;
    }
    if (index == len - 1) {
        return Dfs(str, 0, len - 1);
    }
    int i;
    int state;
    char newChar, oldChar;
    for (i = index; i < len - 1; ++i) {
        if (!g_state[POWER2(str[i] - 'A')][POWER2(str[i + 1] - 'A')]) {
            return false;
        }
        state = g_state[POWER2(str[i] - 'A')][POWER2(str[i + 1] - 'A')];
        oldChar = str[i];
        do {
            newChar = Log2(GET_RIGHT_MOST_BIT(state)) + 'A';
            str[i] = newChar; 
            if (Dfs(str, i + 1, len)) {
                return true;
            }
            str[i] = oldChar;
            DEL_RIGHT_MOST_BIT(state);
        } while (state);
    }
    return false;
}

bool pyramidTransition(char * bottom, char ** allowed, int allowedSize){
    if (bottom == NULL || allowed == NULL) {
        return false;
    }
    int len = strlen(bottom);
    if (len == 1) {
        return true;
    }
    memset(g_state, 0, sizeof(g_state));
    int i;
    for (i = 0; i < allowedSize; ++i) {
        g_state[POWER2(allowed[i][0] - 'A')][POWER2(allowed[i][1] - 'A')] |= POWER2(allowed[i][2] - 'A');
    }
    return Dfs(bottom, 0, len);
}

```
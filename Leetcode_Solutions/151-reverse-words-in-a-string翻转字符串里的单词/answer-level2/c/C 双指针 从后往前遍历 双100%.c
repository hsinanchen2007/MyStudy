![Snipaste_2020-04-10_11-06-25.png](https://pic.leetcode-cn.com/b0a47f4965fde95e0192a2cb5d1e85acd68abe0b75b8edc78b80f17568b05c87-Snipaste_2020-04-10_11-06-25.png)


### 解题思路
1. `i` **从后往前**遍历 `s` ，每次遇到**第一个非空格字符**（word的最后一位），`i` 赋予 `rear` ，每次遇到**第一个word后的空格字符**， `i + 1` 赋予 `front` ；

2. `front` 可以不重置，但 **`rear` 必须置零**，以便判断是否为第一个空格；

3. 插入空格：**先插入空格再复制word**。因此一开始需要判断， new_s 是否有word了，如果没有，不能插入空格。

4. 特殊情况：`s` 前面没有空格，如“an example   ”，因为我的步骤是遇到空格才回头复制word，如果没有对这种情况的考虑，会导致 `s` 的第一个word会漏掉。解决办法就是**遇到 `i == 0` 且 `s[0]` 非空格时，同样回头遍历复制这个word**。当然 `i` 回增时不能超过 `size` ，因为有特例如“aaaa”，完全没有空格的 `s` 存在。


### 代码

```c
char * reverseWords(char * s){
    int size = strlen(s);
    char* new_s = (char*)malloc(sizeof(int) * (size + 1));
    memset(new_s, 0, sizeof(int) * (size + 1));
    int i = size - 1, j = 0;  //i从后到前遍历s，j指向new_s新增字符
    int front = 0, rear = 0;  //遍历s过程中，rear指向一个word的最后一位，front指向同个word的第一位
    while (i >= 0) {
        if (s[i] != ' ') {
            if (rear == 0) {  //“前”一个字符是空格
                if (new_s[0]) new_s[j++] = ' '; //还没有单词入new_s时，不能插入空格，否则每隔一个单词插入一个空格
                rear = i;  //rear赋值，暂时不变，指向word的最后一位
            }
            if (i == 0) {  //特殊情况：s前面没有空格，此时需单独回头遍历直至空格或结束
                while (i < size && s[i] != ' ') {
                    new_s[j++] = s[i++];
                }
                break;
            }
        }
        else {
            if (rear != 0) {  //此时rear还保留着，说明“前”一个字符非空格
                front = i + 1;  //front赋值，指向word第一位
                while (front <= rear) {  //回头遍历到rear停止
                    new_s[j++] = s[front++];
                }
                rear = 0;  //rear置零
            }
        }
        i--;
    }
    return new_s;
}
```
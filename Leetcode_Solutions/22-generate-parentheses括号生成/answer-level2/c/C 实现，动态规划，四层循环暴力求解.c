![2019-10-02_01-29.png](https://pic.leetcode-cn.com/324f8dfafafb336692d19092ce3d48ad1cff42ed5d6a82bd7fb00ef35438be17-2019-10-02_01-29.png)

动态规划的原理参考精选题解

```c
// 一个 Group 用来存储一个 n 对应的所有排列组合情况
struct Group {
    char ** table; // 所有排列组合用一个 table 存储，结构为 {"(())", "()()"}
    int len;       // table 的长度，即所有排列组合的个数
    int size;      // 每种排列里括号字符的个数，size = n << 1
};

char ** generateParenthesis(int n, int* returnSize){
    // 我们从 0 开始考虑，因此实际上需要考虑 n + 1 层
    n++;
    // Group 数组，存储每层的数据指针
    struct Group * groups = (struct Group *) malloc(sizeof(struct Group) * n);
    // 初始化 n == 0 的情况，table 为 ["\0"]
    char ** table = (char **) malloc(sizeof(char *) * 1);
    table[0] = (char *) malloc(sizeof(char));
    table[0][0] = 0;
    groups[0].table = table;
    groups[0].len = 1;
    groups[0].size = 0;

    // 记录第 i 层一共有多少种组合
    int len;
    for (int i = 1; i < n; i++) {
        len = 0;
        // 括号中间有 j 个 ()，右边有 (i - j - 1) 个 ()
        // 第 j 层和 (i - j - 1) 层已经算出，则针对 j 组合数为两个组合数的乘积
        for (int j = 0; j < i; j++)
            len += groups[j].len * groups[i - j - 1].len;
        // 为第 i 层分配内存
        groups[i].table = (char **) malloc(sizeof(char *) * len);
        groups[i].len = len;
        groups[i].size = i << 1;
        table = groups[i].table;
        // 恐怖的四层循环。不！是五层
        // 这个 j 和上面是一个意思
        for (int j = 0; j < i; j++) {
            // k 是遍历中部的括号组合数
            for (int k = 0; k < groups[j].len; k++) {
                // l 是遍历右侧的括号组合数
                for (int l = 0; l < groups[i - j - 1].len; l++) {
                    // 为一种组合分配内存，长度加 1 是为了存储末尾的 '\0'
                    *table = (char *) malloc(sizeof(char) * (groups[i].size + 1));
                    // 不想做索引计数了，直接用 offset 做指针偏移吧
                    char * offset = *table;
                    // 先存上 '('
                    *offset++ = '(';
                    // 存括号中部的组合
                    for (int a = 0; a < groups[j].size; a++)
                        *offset++ = groups[j].table[k][a];
                    // 存 ')'
                    *offset++ = ')';
                    // 存括号右侧的组合
                    for (int b = 0; b < groups[i - j - 1].size; b++)
                        *offset++ = groups[i - j - 1].table[l][b];
                    // 字符串末尾用 0 封尾
                    *offset = 0;
                    // 移到下一个组合
                    table++;
                }
            }
        }
    }
    // 除了第 n 层外，释放其它层的内存
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < groups[i].len; j++) {
            free(groups[i].table[j]);
        }
        free(groups[i].table);
    }
    char ** ret = groups[n - 1].table;
    *returnSize = groups[n - 1].len;
    free(groups);
    return ret;
}
```

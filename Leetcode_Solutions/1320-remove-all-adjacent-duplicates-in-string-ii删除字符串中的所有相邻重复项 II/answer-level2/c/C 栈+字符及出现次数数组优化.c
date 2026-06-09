1、依次遍历源数据，记录每个字符连续出现的次数；
2、第一次出现，压栈；
3、非第一次出现，则在top节点对出现的次数+1；如果达到指定次数，则从栈中弹出；

stack中的character和num是按照最大字符个数申请的，此处可优化为动态链表，但注意逐一释放；

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int     top;
    char    *character;
    char    rsv[3];
    int     *num;
}Stack;

static Stack   g_stack;

static bool StackInit(const int sLen)
{
    g_stack.top = 0;
    g_stack.character = (char *)malloc((sLen + 1) * sizeof(char));  /* 字符多申请一个位置 */
    if (g_stack.character == NULL) {
        return false;
    }
    memset(g_stack.character, 0, (sLen + 1) * sizeof(char));

    g_stack.num = (int *)malloc(sLen * sizeof(int));
    if (g_stack.num == NULL) {
        free(g_stack.character);
        return false;
    }
    memset(g_stack.num, 0, sLen * sizeof(int));

    return true;
}

static void push(const char ch)
{
    /* 第一个元素的加入不需要top++ */
    if (g_stack.num[0] != 0) {
        g_stack.top++;
    }

    g_stack.character[g_stack.top] = ch;
    g_stack.num[g_stack.top] = 1;

    return;
}

static void removeTop()
{
    g_stack.num[g_stack.top] = 0;
    g_stack.character[g_stack.top] = 0;
    g_stack.top > 0 ? g_stack.top-- : g_stack.top;
    return;
}

static void addTopNum()
{
    g_stack.num[g_stack.top]++;
    return;
}

void outputString(char *output, int outputLen)
{
    int loop;
    int cnt;
    
    for (loop = 0; loop <= g_stack.top; loop++) {
        for (cnt = 0; cnt < g_stack.num[loop]; cnt++) {
            *output++ = g_stack.character[loop];
        }
    }

    return;
}

char * removeDuplicates(char * s, int k) {
    int sLen = strlen(s);
    char    ch;
    char    *output = NULL;

    output = (char *)malloc((sLen + 1) * sizeof(char));
    if (output == NULL) {
        return "";
    }
    memset(output, 0, (sLen + 1) * sizeof(char));

    if (true != StackInit(sLen)) {
        return "";
    }

    while ((ch = *s++) != '\0') {
        if (ch != g_stack.character[g_stack.top]) {
            push(ch);
        }
        else {
            addTopNum();

            /* k>=2 */
            if (g_stack.num[g_stack.top] == k) {
                removeTop();
            }
        }
    }

    outputString(output, sLen + 1);

    free(g_stack.character);
    g_stack.character = NULL;
    free(g_stack.num);
    g_stack.num = NULL;

    printf("%s\n", output);

    return output;
}

int main()
{
    char    s[] = "pbbcggttciiippooaais";
    int     k = 2;
    removeDuplicates(s, k);
    return 0;
}




# 简要描述
leetcode的BFS模板（https://leetcode-cn.com/explore/learn/card/queue-stack/217/queue-and-bfs/870/）采用层次遍历的方式。

个人认为标准BFS的实现更易理解和记忆。

下面代码是：内嵌简易的循环队列，使用distance数组记录起点到每个节点的距离，每次循环仅仅出队一个点，入队若干个点。

# 代码如下
```C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ELE_NUM 10000

typedef struct Pattern {
    char p[5];
}Pattern;

int g_dead[MAX_ELE_NUM] = {0};

int StrToInt(char *p)
{
    return (p[0]-'0') * 1000 + (p[1]-'0') * 100 + (p[2]-'0') * 10 + p[3] - '0';
}

int openLockHandle1(Pattern target, Pattern curPattern)
{
    // 1. 变量定义
    // 指示是否访问过
    int visited[MAX_ELE_NUM] = {0};
    // 当前计算获得的距离
    int distance[MAX_ELE_NUM] = {-1};
    // 简易循环队列，元素最多MAX_ELE_NUM就够了
    Pattern q[MAX_ELE_NUM] = {0};
    // head和tail相等时，队列为空
    int head = 0;
    int tail = 0;

    // 2. 初始化：add 第一个节点到队列
    q[tail] = curPattern;
    tail = 1;
    visited[0] = 1;
    distance[0] = 0;

    // 3. BFS
    while (head != tail) {
        int curHead = head;
        head = (head + 1) % MAX_ELE_NUM;
        Pattern p1 = q[curHead];
        int headK = StrToInt(p1.p);

        // 针对该节点的邻节点：8个
        int dir[2] = {1, -1};
        for (int l = 0; l < 2; ++l) {
            for (int i = 0; i < 4; ++i) {
                Pattern p = q[curHead];
                char curP = p.p[i];
                p.p[i] = '0' + (curP - '0' + 10 + dir[l]) % 10;
                int k = StrToInt(p.p);;

                // 针对每个邻节点，如果没有访问过，且不是禁止的，则进行入队操作
                if (visited[k] == 0) {
                    visited[k] = 1;
                    if (g_dead[k] == 0) {
                        if (strcmp(p.p, target.p) == 0) {
                            return distance[headK] + 1;
                        }
                        distance[k] = distance[headK] + 1;
                        q[tail] = p;
                        tail = (tail + 1) % MAX_ELE_NUM;
                    }
                }
            }
        }
    }

    return -1;
}

/*  输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
    输出：6
    解释：
    可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
    注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
    因为当拨动到 "0102" 时这个锁就会被锁定。
 */
int openLock(char ** deadends, int deadendsSize, char * target){
    memset(g_dead, 0, sizeof(g_dead));
    for (int i = 0; i < deadendsSize; ++i) {
        char *p = deadends[i];
        int k = StrToInt(p);
        g_dead[k] = 1;
    }

    if (g_dead[0] == 1) {
        return -1;
    }

    Pattern p1 = {{target[0], target[1], target[2], target[3]}};
    Pattern p2 = {"0000"};
    int num = openLockHandle1(p1, p2);
    return num;
}

int main() {
    char *arr[] = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    openLock(arr, sizeof(arr) / sizeof(arr[0]), "8888");
    return 0;
}

```

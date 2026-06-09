### 解题思路
1. 维护滑动窗口，窗口内的字符都是一样的 （即当*head == *tail时，tail++）；检查窗口的大小，并记录最大的窗口到变量max中。
2. 如果碰到一个不一样的字母，并且从未交换过:
    2.1  优先尝试从头找一个位置，并且该位置不在窗口内（changsrc = strchr (text, *head);，并且changsrc < head），就进行一次交换，继续尝试扩大窗口
    2.2  如果2.1没找到，尝试从尾巴找一个位置，并且该位置不在窗口内（changsrc = strrchr(text, *head);，并且changsrc > tail），就进行一次交换，继续尝试扩大窗口    
3. 如果第二步未找到可交换位置，或者已经交换过一次，本次扩展结束，滑动窗口移到最后一次交换的位置（如果产生过交换）或者tail（本窗口没有交换过）的位置，并恢复曾经交换过的字符。
4. 从第一步不断循环，直至tail的位置指向text的末尾。

窗口位置移动，需要注意下面这种用例：
"aababaaa"

运行效果如下：
![image.png](https://pic.leetcode-cn.com/9459b915c66a98cca41d9dd0cf39539d9e0f14a3c47e633e896d63a4d057a61f-image.png)

### 代码

```c
int maxRepOpt1(char* text)
{
    char* head;
    char* tail;
    int max = 0;
    int changeFlag = 0;
    char* changed = NULL;
    char* changsrc = NULL;
    int len = 0;

    head = tail = text;

    while (*tail != '\0')
    {
        if (*head == *tail)
        {
            len = tail - head + 1;
            if (len > max)
            {
                max = len;
            }

            tail++;
        }
        else
        {
            if (changeFlag == 0)
            {
                // 从前往后找
                changsrc = strchr (text, *head);
                if (changsrc < head)
                {
                    changeFlag = 1;
                    changed = tail;
                    *changsrc = *tail;
                    *tail = *head;
                    continue;
                }
                else
                {
                    // 从后往前找
                    changsrc = strrchr(text, *head);
                    if (changsrc > tail)
                    {
                        changeFlag = 1;
                        changed = tail;
                        *changsrc = *tail;
                        *tail = *head;
                        continue;
                    }
                }
            }
            else
            {
                // 恢复
                *changed = *changsrc;
                *changsrc = *head;
                changeFlag = 0;
                tail = changed;
            }

            // 找下一个
            head = tail;
        }
    }

    return max;
}

```



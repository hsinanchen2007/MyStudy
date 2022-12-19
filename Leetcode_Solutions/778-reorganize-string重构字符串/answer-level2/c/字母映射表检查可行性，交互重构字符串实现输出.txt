### 解题思路
![image.png](https://pic.leetcode-cn.com/46499ddf4ba51a164a69c5bd0f94c7ff67cf664e6f0b6662e3d5aa5cd3a9fd6f-image.png)

【第一步】先判断可行性
先通过统计目标串中所有字母的数量，获取数目最多的字母的数目maxCount
如果maxCount的数目比剩下的字母的数目大于1以上，则该串必然无法重新排布。
<解释> 这个地方比较特别，需要思索一下，举例，最极限的情况，以字母a为例，其中x表示其他字母，最极限的情况为axaxaxa..xa，所以之要a的数目不超过x的数目+1,必然能放得下。
【第二步】通过从前往后，从后往前，两次交互，把邻居的字母，更换为不同的字母（这个比较暴力）
比如：aaabbbccc
从前往后交换:
abababccc
再从后往前交换:
ababcacbc

### 代码

```c
#define MAX_ALPHA 26
char * reorganizeString(char * S){
    int table[MAX_ALPHA] = {0};
    int slen = strlen(S);
    int i;
    int j;
    int maxCount = 0;
    
    if (slen<= 2) {
        return S;
    }

    for (i=0; i<slen; i++) {
        j = S[i] - 'a';
        table[j]++;
        if(table[j] > maxCount) {
            maxCount = table[j];
        }
    }

    if ((maxCount-1) > (slen - maxCount)) {
        S[0] = '\0';
        return S;
    }

    // 从前往后
    for(i=1; i<slen; i++) {
        //相同，需要替换
        if (S[i] == S[i-1]) {
            for(j = i+1; j<slen; j++) {
                if (S[j] != S[i]) {
                    S[i] = S[j];
                    S[j] = S[i-1];
                    break;
                }
            }
        }
    }

    // 从后往前
    for(i=slen - 2; i > 0; i--) {
        //相同，需要替换
        if (S[i] == S[i+1]) {
            for(j = i-1; j>=0; j--) {
                if (S[j] != S[i]) {
                    S[i] = S[j];
                    S[j] = S[i+1];
                    break;
                }
            }
        }
    }    

    return S;    
}
```
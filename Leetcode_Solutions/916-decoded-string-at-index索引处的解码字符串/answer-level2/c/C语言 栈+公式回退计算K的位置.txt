### 解题思路
注意的地方：
1. 纯粹是一道数学推理题，根据K推算扩展之前的位置。因为有多次扩展，需要不断的回退扩展。
2. 要用数学计算的方式而不能直接扩展成完整的串，否则存储不下...
根据题目，自己构建一些用例也很关键，个人构建用例如下：
/*
"a22"
3
"a22"
1
"a22"
4
"a22b"
5
"a22b2"
6
"a22b2"
8
"a22b2c"
9
"a22b2c"
10
"a22b2c2"
12
"a22b2c2"
22
*/

思路如下：
将未扩展前的字符串抽象如下
s1n1s2n2s3n3...

扩展后如下:
[[[s1s1...s1]s2[s1s1...s1]s2...[s1s1...s1]s2]s3[[s1s1...s1]s2[s1s1...s1]s2...[s1s1...s1]s2]s3...[[s1s1...s1]s2[s1s1...s1]s2...[s1s1...s1]s2]s3]
我们用[]表示一次翻倍的操作（对应ni），我们可以推断出如下的公式：
L[i] = strlen(s);  
N[i] = repeat num
E[i] = D[i-1]+L[i]  //表示在前一个串重复后加上本串，如果i==2，则表示[s1s1...s1]s2；
D[i] = E[i]*N[i]    //表示当前串的重复，如果i==2，则表示[[s1s1...s1]s2[s1s1...s1]s2...[s1s1...s1]s2]；

判断K的位置时：
如果K小于E[i]，并且大于D[i-1]，则K的位置为si中的位置，其下标为：K-D[i-1]
如果K大于E[i]，并且小于D[i]，  则K的位置必然是E[i]扩展的，K在重复前的值应该为K = (K - 1) % E[i] + 1; //这里需要重点理解，老费劲了。。。
如果K小于D[i-1]，K的情况，需要根据E[i-1]和D[i-1]来计算；另i=i-1即可
重复以上过程，直至K落到某个si中。

代码步骤：
1. 解题时，先根据输入构建L和N的列表，（为了快速退出，可以不用把整个串过滤完，当我们遇到特别大的N时，例如Ni已经超过了K，则肯定不需要继续看后面的了）。
2. 根据L和N，开始构建E和D
3. 根据K在E和D之间位置，计算新的K，直至K落到某个si的位置即L[i]的位置（也就是D[i-1]和E[i]之间）

### 代码

```c

#define MAX_STACK 100
#define CHARS     0
#define NUMS      1
char *decodeAtIndex(char *S, int K)
{
    int Str[MAX_STACK];  //记录子串开始的位置，即S中的下标
    unsigned long L[MAX_STACK];
    unsigned long N[MAX_STACK];
    unsigned long E[MAX_STACK];
    unsigned long D[MAX_STACK];
    int i = 0;
    int j = 0;
    int slen = strlen(S);

    memset(Str, 0, sizeof(Str));
    memset(L, 0, sizeof(L));
    memset(N, 0, sizeof(N));
    memset(E, 0, sizeof(E));
    memset(D, 0, sizeof(D));

    int flag = CHARS;

    for (j = 0; j < slen; j++) {
        if ((S[j] >= 'a') && (S[j] <= 'z')) {
            if (flag == CHARS) {
                L[i]++;
            } else {
                i++;
                flag = CHARS;
                Str[i] = j;
                L[i] = 1;
                N[i] = 1;
            }
        }

        if ((S[j] >= '1') && (S[j] <= '9')) {
            if (flag == NUMS) {
                N[i] = N[i] * (S[j] - '0');
            } else {
                flag = NUMS;
                N[i] = S[j] - '0';
            }
        }

        if (N[i] >= K) {
            break;
        }
    }

    int count = i + 1;

    if (K <= L[0]) {
        S[K] = '\0';
        return &S[K - 1];
    }

    /*
    E[0] = L[0];
    D[0] = E[0] * N[0];
    */
    for (i = 0; i < count; i++) {
        if (i == 0) {
            E[0] = L[0];
            D[0] = E[0] * N[0];
        } else {
            E[i] = D[i - 1] + L[i];
            D[i] = E[i] * N[i];
        }
        if (K <= E[i]) {
            S[(Str[i] + K - D[i - 1])] = '\0';
            return &S[(Str[i] + K - D[i - 1] - 1)];
        } else if (K <= D[i]) {
            break;
        }
    }

    while (i > 0) {
        if ((K <= E[i]) && (K > D[i - 1])) {
            S[(Str[i] + K - D[i - 1])] = '\0';
            return &S[(Str[i] + K - D[i - 1] - 1)];
        } else if ((K <= D[i]) && (K > D[i - 1])) {
            K = (K - 1) % E[i] + 1;
            continue;
        }
        i--;
    }

    if (K > E[0]) {
        K = (K - 1) % E[0] + 1;
    }
    S[Str[0] + K] = '\0';
    return &S[Str[0] + K - 1];
}
```

目前看，效果不错，双100
![image.png](https://pic.leetcode-cn.com/133b2beec939dc3f74359395fa48cbe10a9e53bbcff6222bf3ba86239c2c787e-image.png)

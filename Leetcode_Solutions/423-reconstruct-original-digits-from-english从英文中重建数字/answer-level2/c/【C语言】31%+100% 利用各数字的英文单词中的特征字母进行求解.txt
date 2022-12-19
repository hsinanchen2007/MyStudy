### 解题思路
1.思路：
（1）统计字符串源中各个字母出现的次数，统计结果存在numscount中；
（2）观察数字0~9的英文单词可以发现，z、w、u、x、h这5个字母在整个0~9的单词中，分别只会在0、2、4、6、8中出现，因此，只需要统计这几个字母在字符串中出现的次数，即可得到0、2、4、6的个数：
        "**z**ero",
        "one",
        "t**w**o",
        "three",
        "fo**u**r",
        "five",
        "si**x**",
        "seven",
        "eight",
        "nine"
（3）数字0、2、4、6、8已经完成统计，将这些数字对应单词所需要的字母个数从numscount中减出。剩余的就是未统计的数字的字母个数。通过这种“特征字母”，可以连带的剔除非特征字母的个数。例如，通过z字母的个数，可以将e字母中用于zero组成的e的个数剔除。那么剩下的就是未完成统计的数字的单词中e的个数。这些剩下的e就是用于组成one、five等数字单词的字母个数。
（4）经过第（2）、（3）步，0、2、4、6、8已经完成统计，继续在剩下的数字的单词范围内寻找数字的“特征字母”，可以发现，r、s、o分别是数字3、7、1对应单词的特征字母，使用（3）中同样的方法，完成字母个数的减出。
        "**o**ne",
        "th**r**ee",
        "five",
        "**s**even",
        "nine"
（5）此时，只剩下5和9,5和9对应单词所组成的字母中，属于5的“特征字母”是v，继续用（3）的方法统计出数字5的个数，最终剩下的就是9。
        "five",
        "nine"
（6）此时完成了各个数字个数的统计并将结果存入ret中，最后通过qsort完成从小到大的排序。

2.corner condition：
（1）.有些数字会重复；
3.知识点总结：
字符串数组的定义：
char * a[] = {
       "aaaaaa",
       "bbbbbb",
}。
4.耗时：long...~，需要加强算法设计能力。主要耗时点：
（1）第一版设计算法在考虑重复数字统计时，一次将一个数字以及它的重复数也统计进去，这会导致后面的数字没有统计进去，结果错误-----算法设计考虑不全；
（2）第二版的时候，按照0~9对应的单词，一遍一遍的去遍历整个输入串s，这会导致算法的时间消耗是O（n^3），导致超时------算法设计未考虑到耗时

![image.png](https://pic.leetcode-cn.com/72cf675a319959a20e1a4de8cf767b65d6b00939d92607cca44ab2147397e7e6-image.png)

///////
更新：有人问为什么分配的内存大小是16667个char。很简单，题目所给的字符串长度是50000个char，而数字0~9中最短的单词是3个字母，那么相当于这个字符串实际“包含”的最多的数的个数是50000/3 = 16666.666666~,约等于16667。

### 代码

```c
int cmpf(const void *a, const void *b)
{
    return (*((char *)a)) > (*((char *)b));
}

void countalpha(char *s, int len, int *numscount)
{
    int i = 0;
    for (i = 0; i < len; i++) {
        if (s[i] == 'a') {
            numscount[0]++;
        } else if (s[i] == 'b') {
            numscount[1]++;
        } else if (s[i] == 'c') {
            numscount[2]++;
        } else if (s[i] == 'd') {
            numscount[3]++;
        } else if (s[i] == 'e') {
            numscount[4]++;
        } else if (s[i] == 'f') {
            numscount[5]++;
        } else if (s[i] == 'g') {
            numscount[6]++;
        } else if (s[i] == 'h') {
            numscount[7]++;
        } else if (s[i] == 'i') {
            numscount[8]++;
        } else if (s[i] == 'j') {
            numscount[9]++;
        } else if (s[i] == 'k') {
            numscount[10]++;
        } else if (s[i] == 'l') {
            numscount[11]++;
        } else if (s[i] == 'm') {
            numscount[12]++;
        } else if (s[i] == 'n') {
            numscount[13]++;
        } else if (s[i] == 'o') {
            numscount[14]++;
        } else if (s[i] == 'p') {
            numscount[15]++;
        } else if (s[i] == 'q') {
            numscount[16]++;
        } else if (s[i] == 'r') {
            numscount[17]++;
        } else if (s[i] == 's') {
            numscount[18]++;
        } else if (s[i] == 't') {
            numscount[19]++;
        } else if (s[i] == 'u') {
            numscount[20]++;
        } else if (s[i] == 'v') {
            numscount[21]++;
        } else if (s[i] == 'w') {
            numscount[22]++;
        } else if (s[i] == 'x') {
            numscount[23]++;
        } else if (s[i] == 'y') {
            numscount[24]++;
        } else if (s[i] == 'z') {
            numscount[25]++;
        }
    }
    return;
}

char *originalDigits(char *s)
{
    char *alpha_tbl = "abcdefghijklmnopqrstuvwxyz";
    int numscount[26] = {0};
    int len = strlen(s);
    int i = 0;
    int j = 0;
    char *ret = NULL;

    ret = (char *)malloc(16667 * sizeof(char));
    memset(ret, 0x00, 16667 * sizeof(char));

    countalpha(s, len, numscount);
    // hanle 0 zero
    for (i = 0; i < numscount[25]; i++) {
        ret[i] = '0';
    }
    numscount[4] = numscount[4] - numscount[25];
    numscount[17] = numscount[17] - numscount[25];
    numscount[14] = numscount[14] - numscount[25];
    numscount[25] = numscount[25] - numscount[25];
    j = i;
    // hanle 2 two
    for (i = i; i < j + numscount[22]; i++) {
        ret[i] = '2';
    }
    numscount[19] = numscount[19] - numscount[22];
    numscount[14] = numscount[14] - numscount[22];
    numscount[22] = numscount[22] - numscount[22];
    j = i;

    // handle 4 four
    for (i = i; i < j + numscount['u' - 'a']; i++) {
        ret[i] = '4';
    }
    numscount['f' - 'a'] = numscount['f' - 'a'] - numscount['u' - 'a'];
    numscount['o' - 'a'] = numscount['o' - 'a'] - numscount['u' - 'a'];
    numscount['r' - 'a'] = numscount['r' - 'a'] - numscount['u' - 'a'];
    numscount['u' - 'a'] = numscount['u' - 'a'] - numscount['u' - 'a'];
    j = i;

    // handle 6 six
    for (i = i; i < j + numscount[23]; i++) {
        ret[i] = '6';
    }
    numscount[18] = numscount[18] - numscount[23];
    numscount[8] = numscount[8] - numscount[23];
    numscount[23] = numscount[23] - numscount[23];
    j = i;

    // handle 8 eight
    for (i = i; i < j + numscount[6]; i++) {
        ret[i] = '8';
    }
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['g' - 'a'];
    numscount['i' - 'a'] = numscount['i' - 'a'] - numscount['g' - 'a'];
    numscount['h' - 'a'] = numscount['h' - 'a'] - numscount['g' - 'a'];
    numscount['t' - 'a'] = numscount['t' - 'a'] - numscount['g' - 'a'];
    numscount['g' - 'a'] = numscount['g' - 'a'] - numscount['g' - 'a'];
    j = i;


    // handle 3 three
    for (i = i; i < j + numscount['r' - 'a']; i++) {
        ret[i] = '3';
    }
    numscount['t' - 'a'] = numscount['t' - 'a'] - numscount['r' - 'a'];
    numscount['h' - 'a'] = numscount['h' - 'a'] - numscount['r' - 'a'];
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['r' - 'a'];
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['r' - 'a'];
    numscount['r' - 'a'] = numscount['r' - 'a'] - numscount['r' - 'a'];
    j = i;

    // handle 7 seven
    for (i = i; i < j + numscount['s' - 'a']; i++) {
        ret[i] = '7';
    }
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['s' - 'a'];
    numscount['v' - 'a'] = numscount['v' - 'a'] - numscount['s' - 'a'];
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['s' - 'a'];
    numscount['n' - 'a'] = numscount['n' - 'a'] - numscount['s' - 'a'];
    numscount['s' - 'a'] = numscount['s' - 'a'] - numscount['s' - 'a'];
    j = i;

    // handle 1 one
    for (i = i; i < j + numscount['o' - 'a']; i++) {
        ret[i] = '1';
    }
    numscount['n' - 'a'] = numscount['n' - 'a'] - numscount['o' - 'a'];
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['o' - 'a'];
    numscount['o' - 'a'] = numscount['o' - 'a'] - numscount['o' - 'a'];
    j = i;

    // handle 5 five
    for (i = i; i < j + numscount['v' - 'a']; i++) {
        ret[i] = '5';
    }
    numscount['f' - 'a'] = numscount['f' - 'a'] - numscount['v' - 'a'];
    numscount['i' - 'a'] = numscount['i' - 'a'] - numscount['v' - 'a'];
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['v' - 'a'];
    numscount['v' - 'a'] = numscount['v' - 'a'] - numscount['v' - 'a'];
    j = i;

    // handle 9 nine
    for (i = i; i < j + numscount['i' - 'a']; i++) {
        ret[i] = '9';
    }
    numscount['n' - 'a'] = numscount['n' - 'a'] - numscount['i' - 'a'];
    numscount['n' - 'a'] = numscount['n' - 'a'] - numscount['i' - 'a'];
    numscount['e' - 'a'] = numscount['e' - 'a'] - numscount['i' - 'a'];
    numscount['i' - 'a'] = numscount['i' - 'a'] - numscount['i' - 'a'];
    j = i;

    qsort(ret, j, sizeof(char), cmpf);
    return ret;
}

```
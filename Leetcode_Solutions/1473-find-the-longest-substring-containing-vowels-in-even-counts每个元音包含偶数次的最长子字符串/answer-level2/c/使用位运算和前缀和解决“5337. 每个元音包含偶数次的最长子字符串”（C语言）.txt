### 解题思路
经典的前缀和问题，这里给出C语言解法。利用前缀和快速计算子串是否包含偶数个元音。

问题关键在于，使用异或运算进行每个元音是否偶数的判断，从而将二维状态压缩一维。

注意从尾部开始查找最长子序列，并且根据max进行剪枝

1.对于每一个字符获得当前元音是否偶数的状态（mask）

2.从头开始遍历，查找最长符合要求的子序列，判断条件为masks[j] - masks[i] == 0

![image.png](https://pic.leetcode-cn.com/76fe1dc219cf650723cef41beb1733acbcd109a960b888f221993419251488ff-image.png)


### 代码

```c

void symb2msk(char symb, int *msk) {
    if(symb == 'a' || symb == 'e' || symb == 'i' || symb == 'o' || symb == 'u') {
        *msk ^= 1 << (symb - 'a');
    }
}

int findTheLongestSubstring(char * s){
    int slen = strlen(s);
    int *masks  = (int *)calloc(slen, sizeof(int));
    int mask = 0;

    int max = 0;
    //计算0~i的mask累计值
    for(int i = 0; i < slen; i++) {
        symb2msk(s[i], &mask);
        masks[i] = mask;
        if(mask == 0 && i + 1 > max) {
            max = i + 1;
        }
    }

    for(int i = 0; i < slen; i++) {
        //根据max进行剪枝
        if(max > slen - 1 - i) {
            break;
        }

        for(int j = slen - 1; j >= i; j--) {
            //根据max进行剪枝
            if(max >= j - i) {
                break;
            }

            if(masks[j] - masks[i] == 0 && j - i > max) {
                max = j - i;
                break;
            }
        }
    }

    return max;
}
```
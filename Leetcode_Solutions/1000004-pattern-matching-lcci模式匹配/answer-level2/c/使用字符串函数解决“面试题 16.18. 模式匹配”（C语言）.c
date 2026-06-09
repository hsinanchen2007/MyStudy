### 解题思路
虽然C代码实现字符串处理略长，但处理思路非常清晰。

1.将pattern统一为a开头形式

2.统计a,b个数

3.遍历a的可能长度，确定b的长度，然后调用子函数，判断当前a，b是否成立

注意b==0时单独处理，因为计算b的长度，要除以b，这里可以有更简洁的写法。

![image.png](https://pic.leetcode-cn.com/b90ffad971438b0e05da5d2da4670b46bcf8b39fcdcaedf20934d7a37e346bb5-image.png)


### 代码

```c
#define STR_LEN     1000

//根据输入模式，进行匹配
bool helper(char *a, char *b, char *p, int plen, char *v, int vlen)
{
    int alen = strlen(a);
    int blen = strlen(b);

    int vid = 0;
    for(int i = 0; i < plen; i++)
    {
        if(p[i] == 'a')
        {
            if(strncmp(a, &v[vid], alen) != 0)
            {
                return false;
            }
            vid += alen;
        }
        else
        {
            if(strncmp(b, &v[vid], blen) != 0)
            {
                return false;
            }
            vid += blen;
        }
    }

    return true;
}

//用于临时存储a和b
char aa[STR_LEN];
char bb[STR_LEN];

//【算法思路】字符串。找到a，b对应的字符串，判断是否合理
//1.遍历a可能中的一种
//2.根据a的可能，找到b（a确定，则b确定）
//3.检查该情况下，是否可以完成匹配
//4.重复1~3
//注意，pattern必须以a开头，否则翻转pattern
bool patternMatching(char* pattern, char* value){
    int plen = strlen(pattern);
    int vlen = strlen(value);

    if(vlen == 0 && plen < 2)
    {
        return true;
    }
    else if(vlen == 0 || plen == 0)
    {
        return false;
    }

    //翻转pattern
    if(pattern[0] == 'b')
    {
        for(int i = 0; i < plen; i++)
        {
            pattern[i] = pattern[i] == 'a'? 'b' : 'a';
        }
    }

    //-------------确定a,b------------------
    //确定a,b的个数
    int anum = 0;
    int bnum = 0;
    for(int i = 0; i < plen; i++)
    {
        if(pattern[i] == 'a')
        {
            anum++;
        }
        else
        {
            bnum++;
        }
    }

    //printf("%s, anum = %d, bnum = %d\n", pattern, anum, bnum);

    //没有b的特殊情况，单独处理
    if(bnum == 0)
    {
        if(vlen % anum != 0)
        {
            return false;
        }

        int alen = vlen / anum;

        //获取a
        strncpy(aa, value, alen);
        aa[alen] = '\0';

        //printf("a = %s, alen = %d\n", aa, alen);

        bool ret = helper(aa, "", pattern, plen, value, vlen);

        return ret;
    }

    //没有a的特殊情况，单独处理

    //遍历所有a，b的可能，并判断结果。ar表示a的右边界
    for(int alen = 0; alen <= vlen / anum; alen++)
    {
        //判断b的长度,无法整除则跳过
        if((vlen - alen * anum) % bnum != 0)
        {
            continue;
        }

        int blen = (vlen - alen * anum) / bnum;

        //获取a
        strncpy(aa, value, alen);
        aa[alen] = '\0';

        //获取b
        //先获得b的开始位置
        int bid = 0;
        for(int i = 0; i < plen; i++)
        {
            if(pattern[i] == 'a')
            {
                bid += alen;
            }
            else
            {
                break;
            }
        }

        strncpy(bb, &value[bid], blen);
        bb[blen] = '\0';

        if(strcmp(aa, bb) == 0)
        {
            continue;
        }

        //printf("a = %s, b = %s, alen = %d, blen = %d\n", aa, bb, alen, blen);

        bool ret = helper(aa, bb, pattern, plen, value, vlen);

        if(ret == true)
        {
            return true;
        }
    }

    return false;
}
```
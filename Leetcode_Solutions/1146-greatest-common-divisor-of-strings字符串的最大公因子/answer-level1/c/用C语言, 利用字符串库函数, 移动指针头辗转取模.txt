### 解题思路
使用c语言解题,在字符串处理上会比较麻烦.因为不想开辟多余的空间,多使用比较函数.
原理就是利用辗转取模,不过这里通过移动字符串指针头的方法,就可以实现.
![image.png](https://pic.leetcode-cn.com/87fe3fc8c74695b2c5f3eab42d1286e3e1c0364a565aebb343ce3635eeab489c-image.png)

一开始没有考虑@滥意的示例, 经提醒已经修改, 但是判题的示例没有这一类也是有问题的


### 代码

```c
char *gcdOfStrings(char *str1, char *str2)
{
    //if (strstr(str1, str2) == NULL && strstr(str2, str1) == NULL) 原答案
    if (!(strstr(str1, str2) == str1 || strstr(str2, str1) == str2))
        return "";
    int p_a = 0, p_b = 0, cmp = 0;
    do
    {
        cmp = strcmp(str1 + p_a, str2 + p_b);
        cmp > 0 ? (p_a += strlen(str2 + p_b)) : (p_b += strlen(str1 + p_a));
        //if (strstr(str1 + p_a, str2 + p_b) == NULL && strstr(str2 + p_b, str1 + p_a) == NULL)
        if (!(strstr(str1 + p_a, str2 + p_b) == (str1 + p_a) || strstr(str2 + p_b, str1 + p_a) == (str2 + p_b)))
            return "";
    } while (cmp);
    return str1 + p_a;
}
```
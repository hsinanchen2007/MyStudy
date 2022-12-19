### 解题思路
该题思路较为简单，将字符串转化为整型数组即可，解决思路如下：
* 入参检查，判断两个字符是否等长
* 将两个字符串转化为整形数组
* 对两个整型数组进行冒泡排序
* 判断排序后的数组是否相等

本题的时间复杂度为O(N),空间复杂度为O(N)。

### 代码

```c
bool CheckPermutation(char* s1, char* s2)
{
    //入参检查
    if(strlen(s1) != strlen(s2))
    {
        return false;
    }

    //将两个字符串转化为整形数组
    int len = strlen(s1);
    int arrA[len];
    int arrB[len];

    int i = 0;
    for(i=0;i<len;i++)
    {
        arrA[i] = s1[i] - 'a';
        arrB[i] = s2[i] - 'a';
    }

    //数组排序，冒泡排序
    int temp = 0;
    for(i=len-1;i>=0;i--)
    {
        for(int j=0; j<i;j++)
        {
            if(arrA[j] > arrA[j+1])
            {
                temp = arrA[j+1];
                arrA[j+1] = arrA[j];
                arrA[j] = temp;
            }

            if(arrB[j] > arrB[j+1])
            {
                temp = arrB[j+1];
                arrB[j+1] = arrB[j];
                arrB[j] = temp;
            }
        }
    }

    //判断数组是否完全一样
    for(i=0;i<len;i++)
    {
        if(arrA[i] != arrB[i])
        {
            return false;
        }
    }
    return true;
}
```
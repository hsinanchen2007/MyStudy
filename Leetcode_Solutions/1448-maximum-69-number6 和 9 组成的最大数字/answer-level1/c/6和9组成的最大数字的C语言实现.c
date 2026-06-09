### 解题思路
本题思路较为清晰，只需将num中从左向右的第一个6翻转为9，即是所求最大值。解题思路如下：
* 由于num中只含有6和9，因此考虑将num各数字分解并放入数组中
* num的最后一位要么是6 要么是9，因此利用求余和整数除法的方式，获取每一位的数字
* 从后向前遍历数组，将遇到的第一个6反转为9
* 从前向后遍历数组，利用pow函数将数组中各元素加和为一个整数

### 代码

```c
int judge69Number(int num, int *arr)
{
    int i =0;
    while(num > 10)
    {
        if((num-9) % 10 == 0)
        {
            num = (num-9)/10;
            arr[i] = 9;
        }
        else if((num-6)%10 == 0)
        {
            num = (num-6)/10;
            arr[i] = 6;
        }
        i++;
    }
    arr[i] = num;
    return i;
}

int maximum69Number (int num)
{
    int arr[10] = {0};

    //将num转化为数组，并返回数组长度
    int len = judge69Number(num,arr);

    //从后向前遍历数组，遇到第一个6，将其赋值位9，并跳出循环
    int i =len;
    while(i>=0)
    {
        if(arr[i] == 6)
        {
            arr[i] = 9;
            break;
        }
        i--;
    }

    //将数组中的数重新组合为整型
    int rel = 0;
    for(int j = 0; j<=len;j++)
    {
        rel += arr[j]*pow(10,j);
    }
    return rel;
}
```
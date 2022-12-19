### 解题思路

#### 解法一
由于C语言中并不存在字符串和字典类型，因此该题将字符串转化为**整型数组**并利用**桶排序**求解，解决思路如下：
* 入参检查，检查字符串长度是否为0
* 将字符串中各字符减去'a'，即可得到对应的数字（0~26）
* 循环遍历整型数组，将arr[i]的值作为bucket数组的索引，且将该索引对应的数组元素加1
* 桶排序完成后，循环遍历bucket数组中的元素，如果某值>1，则返回false，否则返回true

本解法的时间复杂度为O(n)，空间复杂度也为O(n)。该解法思路简单，易于实现，但并不是最优解法。

### 代码

```c
//解法一代码实现
bool isUnique(char* astr)
{
    bool rel = true;
    //入参检查
    if(strlen(astr) == 0)
    {
        rel = true;
    }
    else
    {
        //建立整形数组
        int len = strlen(astr);
        int arr[len];

        //将字符串转换为字符数组
        for(int i=0; i<len;i++)
        {
            arr[i] = astr[i] - 'a';
        }

        //利用桶排序
        int bucket[26] = {0};
        for(int j=0; j<len;j++)
        {
            bucket[arr[j]]++;
        }
        //遍历整形数组中各元素是否存在大于1的元素
        for(int k=0;k<26;k++)
        {
            if(bucket[k] >1)
            {
                rel = false;
                break;
            }
        }
    }
    return rel;
}
```

#### 解法二
利用位运算解决该题，解决思路如下：
* 入参判断，检查字符串长度是否位0
* 创建mark和move_bit
* 计算字符串中每个字符与'a'的差值，并将差值左移1位，形式上代表该字符。例如：'a'的差值为0，左移1为得到0001；b为0010；c为0100 ...
* 将左移后的数据与mark**按位与**，如果按位与结果==0，则该字符未出现
* 如果字符未出现过，将mark与左移后的数据**按位或**，该操作是用于记录该字符曾出现过，便于下次比较
* 如果按位与结果!=0,则该字符出现过，跳出循环，并返回false

本解法的时间复杂度为O(n),空间复杂度为O(1)。该解法需要熟悉位运算，有些难度，是目前能想出的最优解法。

### 代码

```c
//解法二代码实现
bool isUnique(char* astr)
{
    bool rel = true;
    //入参检查
    if(strlen(astr) == 0)
    {
        rel = true;
    }
    else
    {
        int mark = 0;
        int move_bit = 0;
        //将字符串转换为字符数组
        for(int i=0; i<strlen(astr);i++)
        {
            move_bit = astr[i] - 'a';
            //将move_bit左移1位，并与mark 按位与
            if((mark & (1<<move_bit)) != 0)
            {
                rel = false;
                break;
            }
            else
            {
                //利用位运算的 按位或 将astr[i]记录在mark中
                mark |= (1<<move_bit);
            }
        }
    }
    return rel;
}
```
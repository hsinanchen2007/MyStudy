这道题让我们求两个字符串数字的相乘，输入的两个数和返回的数都是以字符串格式储存的，这样做的原因可能是这样可以计算超大数相乘，可以不受 `int` 或 `long` 的数值范围的限制，那么该如何来计算乘法呢，小时候都学过多位数的乘法过程，都是每位相乘然后错位相加，那么这里就是用到这种方法，举个例子，比如 `89 x 76`，那么根据小学的算术知识，不难写出计算过程如下：

```c
    8 9  <- num2
    7 6  <- num1
-------
    5 4
  4 8
  6 3
5 6
-------
6 7 6 4
```

再写些例子出来，比如 125 x 48，计算过程如下：

```c
      1 2 5  <- num2
        8 8  <- num1
-----------
        4 0
      1 6
      8 
      4 0
    1 6
    8
-----------
  1 1 0 0 0
```


不难发现，以下三点：
- 两数相乘得到的乘积的长度不会超过两个数字的长度之和，若` num1 `长度为`length1`，`num2` 长度为`lenght2`，则 `num1 x num2` 的长度不会超过 `length1 + length2`
- 还有就是乘的时候需要错位的原因，比如`6 x 8`得到的 48 为啥要跟`6 x 9`得到的 54 错位相加，因为 8 是十位上的数字，其本身相当于80，所以错开的一位实际上末尾需要补的0
- `num1` 和 `num2` 中任意位置的两个数字相乘，得到的两位数在最终结果中的位置是确定的，比如 `num1` 中位置为`i`的数字乘以 `num2` 中位置为`j`的数字，那么得到的两位数字的位置为 `i+j` 和 `i+j+1`，这也是由错位相乘引起的

首先开辟两个空间，一个用来存储错位相乘的中间结果，int类型，另外一个作为最终返回的结果，char类型。需要注意的是后一个指针需要比`totalLength`多一个字符用来在C语言当中指示字符串数组的结束，对于int类型的中间结果初始化为0。

由于要从个位上开始相乘，所以从 `num1` 和 `num2 `字符串的尾部开始往前遍历，分别提取出对应位置上的字符，将其转为整型后相乘，将`num1[i]`与`num[j]`相乘的结果累加存储在`value[i+j+1]`当中，注意这里是累加。以上面的 `89 x 76 `为例，`num1[1] x num2[0]`的结果 48 是需要与`num1[0] x num2[1]`的结果 63相加以后一并存储在`value[2]`当中再进入下一步的处理工序的。

在进入下一道工序之前，我们先看看下面这段代码运行以后的结果：

```c
    for(int i = length1  - 1; i >= 0; i--)
    {
        for(int j = length2 - 1; j >= 0; j--)
        {
            value[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
 ```
 依然以 `89 x 76 `为例，运行以后`value`数组的存储结构如下：
 
 ```c
    0     1     2     3
  -----------------------
 |  0  |  56 | 111 |  54 |
  -----------------------
 ```
 
 后面就是要对`value`数组进行修改，改保留的保留，改相加的相加，改进位的进位 ，通过以下三行代码：
 
 ```c
    for(int i= totalLength - 1; i > 0; i--)                 //获取每个位置上面的数字并处理进位
    {
        value[i - 1] += value[i] / 10;
        value[i] %= 10;
    }
 ```
 
 最终得到的`value`数组如下：
 ```c
    0     1     2     3
  -----------------------
 |  6  |  7  |  6  |  4  |
  -----------------------
 ```

这三行代码主要做了两件事，首先依然从数组的尾部开始遍历，将第`i`位的高位通过`/`累加到第`i-1`位，然后通过`%`求余获得当前位的数字。

后面在将数字转化成字符拷贝到待返回的结果之前需要将多余的 0 去掉。

具体的代码如下：


```c []
char * multiply(char * num1, char * num2)
{
    int length1 = strlen(num1);
    int length2 = strlen(num2);
    int totalLength = length1 + length2;                     //获取相乘后字符串的总有效位数
    
    int charIndex = 0;                                       //定义负责索引字段
    int valueIndex = 0;
    
    int *value = (int *)malloc(sizeof(int) * totalLength);
    memset(value, 0, sizeof(int) * totalLength);
    
    char *result = (char *)malloc(sizeof(char) * (totalLength + 1));
    
    
    for(int i = length1  - 1; i >= 0; i--)
    {
        for(int j = length2 - 1; j >= 0; j--)
        {
            value[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    
    for(int i= totalLength - 1; i > 0; i--)                 //获取每个位置上面的数字并处理进位
    {
        value[i - 1] += value[i] / 10;
        value[i] %= 10;
    }
    
    
    
    while(value[valueIndex] == 0 && valueIndex < totalLength -1 ) 
    {
        valueIndex++;                                        //忽略掉前面多余的0，但是最高位也就是唯一的一位0不能忽略
    }
    while(valueIndex < totalLength)
    {
        result[charIndex++] = value[valueIndex++] + '0';
    }
    
    result[charIndex] = '\0';                                //默认补上字符串的终止符
    
    return result;
    
    
}

```

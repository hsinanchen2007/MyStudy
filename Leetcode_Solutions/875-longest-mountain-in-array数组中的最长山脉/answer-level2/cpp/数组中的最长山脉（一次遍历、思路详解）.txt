### 解决方案：

- **写在前头：**

虽然可以用暴力的方法去解决此题，但效率肯定是不理想的，所以在这里我就不介绍暴力的方法了，同时也不推荐暴力的方法。看别人的解决方案总感觉少些什么，我就在此写些个人的想法与思路，希望能对大家有所帮助。

- **思路与分析：**

此时请假象一下你现在正处于某一座山的任意位置处，那么，你如何才能得知此时自己是在上山（面对山顶）还是下山呢（面对山脚），或者说，判断自己所处位置需要哪些信息呢？

这很容易想出：通过比较自己眼前的地面相对自己所处地面即可知道现在是上山（前方地面高于所处地面）、下山或平地前进。

所以，对于此题，我们仅需要一步步走过每个点，并进行以下操作，即可知道最长的山脉有多长：

- 上山时，开始测量自己所走的路程（水平）。
- 再一次上山时，结束本次测量，并开始再一次的测量（可能）。

而对于如何区分是否为第一次上山（开始测量）与在一次上山（结束测量），仅需要知道，在此本次测量中，是否有过下山即可。

- 得初步代码如下：

```csharp []
public int LongestMountain(int[] A) 
{
    //标记此时处于上山或下山的任意一中状态（上山为 真 ，反之）
    //由于第一次必然是上山，所以值为 真
    bool sign = true;
    //存储每一次测量的数据
    int length = 1;
    //记录截至最新的测量中的最大长度
    int max = 1;
    //开始“登山”（默认此时处于第一个点）
    for (int i = 1; i < A.Length; i++)
    {
        // i - 1 代表当前位置
        // i  代表眼前位置
        if (A[i] > A[i - 1] && sign)//上山中
            length++;
        else if (A[i] < A[i - 1] && length > 1)//下山中（并且题目要求，最小山脉长度为 3，所以下山之前必须上山一次）
        {
            //标记此时为下山状态
            sign = false;
            length++;
            //下山更新最大长度即可
            max = length > max ? length : max;
        }
        else if (A[i] == A[i - 1])//平地，结束登山
        {
            sign = true;
            length = 1;
        }
        else if (!sign)//结束登山，但注意：上一个山脉登山最后的一部分可能是另一个山脉的一部分
        {
            i--; 
            sign = true;
            length = 1;
        }
    }
    return max > 2 ? max : 0;
}
```
```cpp []
int longestMountain(vector<int>& A) 
{
    //标记此时处于上山或下山的任意一中状态（上山为 真 ，反之）
    //由于第一次必然是上山，所以值为 真
    bool sign = true;
    //存储每一次测量的数据
    int length = 1;
    //记录截至最新的测量中的最大长度
    int max = 1;
    //开始“登山”（默认此时处于第一个点）
    for (unsigned int i = 1; i < A.size(); i++)
    {
        // i - 1 代表当前位置
        // i  代表眼前位置
        if (A[i] > A[i - 1] && sign)//上山中
            length++;
        else if (A[i] < A[i - 1] && length > 1)//下山中（并且题目要求，最小山脉长度为 3，所以下山之前必须上山一次）
        {
            //标记此时为下山状态
            sign = false;
            length++;
            //下山更新最大长度即可
            max = length > max ? length : max;
        }
        else if (A[i] == A[i - 1])//平地，结束登山
        {
            sign = true;
            length = 1;
        }
        else if (!sign)//结束登山，但注意上一个山脉登山最后的一部分可能是另一个山脉的一部分
        {
            i--; 
            sign = true;
            length = 1;
        }
    }
    return max > 2 ? max : 0;
}
```
```java []
public int longestMountain(int[] A) 
{
    //标记此时处于上山或下山的任意一中状态（上山为 真 ，反之）
    //由于第一次必然是上山，所以值为 真
    boolean sign = true;
    //存储每一次测量的数据
    int length = 1;
    //记录截至最新的测量中的最大长度
    int max = 1;
    //开始“登山”（默认此时处于第一个点）
    for (int i = 1; i < A.length; i++)
    {
        // i - 1 代表当前位置
        // i  代表眼前位置
        if (A[i] > A[i - 1] && sign)//上山中
            length++;
        else if (A[i] < A[i - 1] && length > 1)//下山中（并且题目要求，最小山脉长度为 3，所以下山之前必须上山一次）
        {
            //标记此时为下山状态
            sign = false;
            length++;
            //下山更新最大长度即可
            max = length > max ? length : max;
        }
        else if (A[i] == A[i - 1])//平地，结束登山
        {
            sign = true;
            length = 1;
        }
        else if (!sign)//结束登山，但注意上一个山脉登山最后的一部分可能是另一个山脉的一部分
        {
            i--; 
            sign = true;
            length = 1;
        }
    }
    return max > 2 ? max : 0;
}
```

初步代码显然有所冗长，可以进一步精简代码如下：

```csharp []
public int LongestMountain(int[] A)
{
    bool sign = true;
    int length = 1;
    int max = 1;
    for (int i = 1; i < A.Length; i++)
    {
        if (A[i] > A[i - 1] && sign)
            length++;
        else if (A[i] < A[i - 1] && length > 1)
        {
            sign = false;
            length++;
            max = length > max ? length : max ;
        }
        else//结束登山只有两种可能，并且代码又所重复，精简如下
        {
            if (!sign)
                i--; ;
            sign = true;
            length = 1;
        }
    }
    return max > 2 ? max : 0;
}
```
```cpp []
int longestMountain(vector<int>& A) 
{
    bool sign = true;
    int length = 1;
    int max = 1;
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] > A[i - 1] && sign)
            length++;
        else if (A[i] < A[i - 1] && length > 1)
        {
            sign = false;
            length++;
            max = length > max ? length : max ;
        }
        else//结束登山只有两种可能，并且代码又所重复，精简如下
        {
            if (!sign)
                i--; ;
            sign = true;
            length = 1;
        }
    }
    return max > 2 ? max : 0;
}
```
```java []
public int longestMountain(int[] A)
{
    boolean sign = true;
    int length = 1;
    int max = 1;
    for (int i = 1; i < A.length; i++)
    {
        if (A[i] > A[i - 1] && sign)
            length++;
        else if (A[i] < A[i - 1] && length > 1)
        {
            sign = false;
            length++;
            max = length > max ? length : max ;
        }
        else//结束登山只有两种可能，并且代码又所重复，精简如下
        {
            if (!sign)
                i--; ;
            sign = true;
            length = 1;
        }
    }
    return max > 2 ? max : 0;
}
```

**写在最后：**

如有错误，望各位大佬能不吝指教！

（话说这题好似是要用到双指针的……）




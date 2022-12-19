### 摘要：

**规则：**

- 累加数是一个字符串，组成它的数字可以形成累加序列。

- 一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。

- 额外要求：解决整数溢出的情况

——*累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。*

**简要分析：**

1. 累加数可以形成一个累加序列（1 2 3，1 + 2 = 3），所以可以将解决思路概括为：取某前两个的和与当前数进行比较，如果皆符合条件，即为累加数。

2. 字符串几乎可以表示任意大的一个整数，所以累加数中的某个数多少有可能会超出程序中表示整数的类型内存的内存范围，对此可以通过实现字符串上的加法来解决整数溢出的情况。

### 解决方案：

**写在前头：**

我总感觉这代码要比我用文字表述的要好得多，所以注释是非常值得一看的。

**思路分析：**

很显然，在检验某个数是否为累加数时，必须得知道累加数最前面的两个数。但我以为在解决此题时，不妨先不考虑这前两个数究竟是哪两个数。

- 所以，现在假设已知前两个数，然后进行验证累加数的操作。

这时，仅需要判断前两个数相加和的字符串形式是否等于剩余字符串的开头即可。那么，如何进行字符串上的加法运算呢？

字符串整数的加法运算算法有点像[两数相加](https://leetcode-cn.com/problems/add-two-numbers/)。而对于字符串，只需要从字符串后开始拆解为一位一位的个位上的运算即可（想想一下用笔在纸上的加法运算）。

得初步代码如下（暂且不考虑优化）：

```csharp []
private string GetSum(string n1, string n2)
{
    //从后往前加
    StringBuilder sum = new StringBuilder();
    //进位
    int carry = 0;
    //注意哦，i 的初始值为 1 。
    for (int i = 1; i <= n1.Length || i <= n2.Length; i++)
    {
        int n = carry;
        //从后向前取字符串每个下标的字符
        //根据美国信息交换标准代码（即常称的 ASCII ）可知，字符 0 的十进制码表示为 48，所以在此需要减去 48 。
        n += i <= n1.Length ? n1[n1.Length - i] - 48 : 0;
        n += i <= n2.Length ? n2[n2.Length - i] - 48 : 0;
        carry = n / 10;
        n %= 10;
        //将整数转换为字符，所以加上 48 。
        //如果在这采用 StringBuilder 的 Append 实例方法，所得数将是反向的。
        //这里用 Insert 方法将字符插入开头。
        sum.Insert(0, (char)(n + 48));
    }
    if (carry > 0)
        sum.Insert(0, '1'); ;
    return sum.ToString();
}
```
```cpp []
string getSum(string n1, string n2) {
    //从后往前加
    string sum;
    //进位
    int carry = 0;
    //注意哦，i 的初始值为 1 。
    for (unsigned int i = 1; i <= n1.length() || i <= n2.length(); i++)
    {
        int n = carry;
        //从后向前取字符串每个下标的字符
        //根据美国信息交换标准代码（即常称的 ASCII ）可知，字符 0 的十进制码表示为 48，所以在此需要减去 48 。
        n += i <= n1.length() ? n1[n1.length() - i] - 48 : 0;
        n += i <= n2.length() ? n2[n2.length() - i] - 48 : 0;
        carry = n / 10;
        n %= 10;
        //将整数转换为字符，所以加上 48 。
        //（在开头插入 1 个字符）
        sum = sum.insert(0,1,char(n + 48));
    }
    if (carry > 0)
        sum = sum.insert(0,1, '1'); ;
    return sum;
}
```

再进行两数和与剩余字符的判断。

得初步代码如下：

```csharp []
//private string GetSum(string n1, string n2)：出于某种神奇的考虑

// previousNumber 表示两个数中的前一个数，other 表示剩余字符串
private bool Verify(string previousNumber, string currentNumber, string other)
{
    string sum = GetSum(previousNumber, currentNumber);
    //剩余字符串长度小于表示和的字符串长度肯定不相等
    if (other.Length < sum.Length)
        return false; ;
    int i;
    //如果 GetSum 方法出于某种考虑所得和为反向的表达，这里可以反向遍历
    for (i = 0; i < sum.Length; i++)
    {
        //依次比较每个下标的字符是否相等
        if (sum[i] != other[i])
            return false; ;
    }
    //此时说明这玩意是个累加数，因为已经没有可比较的字符串了
    //值得注意的是，i 此时等于 sum.Length
    if (i == other.Length)
        return true; ;
    //当前数变为上一个数，下一个数变成当前数（此时）
    return Verify(currentNumber, other.Substring(0, i), other.Substring(i, other.Length - i));
}
```
```cpp []
//string getSum(string n1, string n2)：出于某种神奇的考虑

// previousNumber 表示两个数中的前一个数，other 表示剩余字符串
bool verify(string previousNumber, string currentNumber, string other)
{
    string sum = getSum(previousNumber, currentNumber);
    //剩余字符串长度小于表示和的字符串长度肯定不相等
    if (other.length() < sum.length())
        return false; ;
    int i;
    //如果 getSum 方法出于某种考虑所得和为反向的表达，这里可以反向遍历
    for (i = 0; i < sum.length(); i++)
    {
        //依次比较每个下标的字符是否相等
        if (sum[i] != other[i])
            return false; ;
    }
    //此时说明这玩意是个累加数，因为已经没有可比较的字符串了
    //值得注意的是，i 此时等于 sum.length()
    if (i == other.length())
        return true; ;
    //当前数变为上一个数，下一个数变成当前数（此时）
    return verify(currentNumber, other.substr(0, i), other.substr(i, other.length() - i));
}
```

有了以上代码，解决此题便方便得多。

（嗯……要如何说呢？感觉这表述还不及代码来的轻快）

得初步代码如下：

```csharp []
public bool IsAdditiveNumber(string num)
{
    //直接排除
    if (num.Length < 3)
        return false; ;
    //第一个数肯定是不可以超过整个累加数的一半的
    //诸如 1991，991100，9981999
    for (int i = 0; i < num.Length / 2; i++)
    {
        string firstNumber = num.Substring(0, i + 1);
        //第一个数字也可能就是 0 ，但一旦出现 01 之类，后续必然不符要求
        if (firstNumber[0] == '0' && firstNumber.Length > 1)
            return false; ;
        //第二个数显然也不可以超过一半
        //诸如 09999,199100
        for (int j = 0; j < num.Length / 2; j++)
        {
            string secondNumber = num.Substring(i + 1, j + 1);
            //第二个数字开头为零的话显然无论如何向后增长都改变不了，所以直接跳出当前循环
            if (secondNumber[0] == '0' && secondNumber.Length > 1)
                break; ;
            //如果第一个数和第二个数是累加数第一个数第二个数（或干脆不存在），肯定符合后续所有要求
            if (Verify(firstNumber, secondNumber, num.Substring(i + 1 + j + 1, num.Length - (i + 1 + j + 1))))
                return true; ;
        }
    }
    return false;
}

private bool Verify(string previousNumber, string currentNumber, string other)
{
    string sum = GetSum(previousNumber, currentNumber);
    if (other.Length < sum.Length)
        return false; ;
    int i;
    for (i = 0; i < sum.Length; i++)
    {
        if (sum[i] != other[i])
            return false; ;
    }
    if (i == other.Length)
        return true; ;
    return Verify(currentNumber, other.Substring(0, i), other.Substring(i, other.Length - i));
}

private string GetSum(string n1, string n2)
{
    StringBuilder sum = new StringBuilder();
    int carry = 0;
    for (int i = 1; i <= n1.Length || i <= n2.Length; i++)
    {
        int n = carry;
        n += i <= n1.Length ? n1[n1.Length - i] - 48 : 0;
        n += i <= n2.Length ? n2[n2.Length - i] - 48 : 0;
        carry = n / 10;
        n %= 10;
        sum.Insert(0, (char)(n + 48));
    }
    if (carry > 0)
        sum.Insert(0, '1'); ;
    return sum.ToString();
}
```
```cpp []
string getSum(string n1, string n2) {
	string sum;
	int carry = 0;
	for (unsigned int i = 1; i <= n1.length() || i <= n2.length(); i++)
	{
		int n = carry;
		n += i <= n1.length() ? n1[n1.length() - i] - 48 : 0;
		n += i <= n2.length() ? n2[n2.length() - i] - 48 : 0;
		carry = n / 10;
		n %= 10;
		sum = sum.insert(0,1,char(n + 48));
	}
	if (carry > 0)
		sum = sum.insert(0,1, '1'); ;
	return sum;
}

bool verify(string previousNumber, string currentNumber, string other)
{
    string sum = getSum(previousNumber, currentNumber);
    if (other.length() < sum.length())
        return false; ;
    int i;
    for (i = 0; i < sum.length(); i++)
    {
        if (sum[i] != other[i])
            return false; ;
    }
    if (i == other.length())
        return true; ;
    return verify(currentNumber, other.substr(0, i), other.substr(i, other.length() - i));
}

public:
    bool isAdditiveNumber(string num)
    {
        //直接排除
        if (num.length() < 3)
            return false; ;
        //第一个数肯定是不可以超过整个累加数的一半的
        //诸如 1991，991100，9981999
        for (int i = 0; i < num.length() / 2; i++)
        {
            string firstNumber = num.substr(0, i + 1);
            //第一个数字也可能就是 0 ，但一旦出现 01 之类，后续必然不符要求
            if (firstNumber[0] == '0' && firstNumber.length() > 1)
                return false; ;
            //第二个数显然也不可以超过一半
            //诸如 09999,199100
            for (int j = 0; j < num.length() / 2; j++)
            {
                string secondNumber = num.substr(i + 1, j + 1);
                //第二个数字开头为零的话显然无论如何向后增长都改变不了，所以直接跳出当前循环
                if (secondNumber[0] == '0' && secondNumber.length() > 1)
                    break; ;
                //如果第一个数和第二个数是累加数第一个数第二个数（或干脆不存在），肯定符合后续所有要求
                if (verify(firstNumber, secondNumber, num.substr(i + 1 + j + 1, num.length() - (i + 1 + j + 1))))
                    return true; ;
            }
        }
        return false;
    }
```

(代码好似是偏长了一些……)

在初步代码中有许多截取字符串的操作，但是字符串的截取并不是高效的，同时也不是必须的，对此，可以利用传递下标来优化代码。

得代码如下：

```csharp []
public bool IsAdditiveNumber(string num)
{
    if (num.Length < 3)
        return false; ;
    for (int i = 0; i < num.Length / 2; i++)
    {
        if (num[0] == '0' && i > 0)
            return false; ;
        for (int j = 0; j < num.Length / 2; j++)
        {
            if (num[i + 1] == '0' && j > 1)
                break; ;
            if (Verify(0, i + 1, i + 2 + j, num))
                return true; ;
        }
    }
    return false;
}

private bool Verify(int firstIndex, int secondIndex, int rightEdge, string num)
{
    string sum = GetSum(firstIndex, secondIndex, rightEdge, num);
    if (num.Length - rightEdge < sum.Length)
        return false; ;
    int i;
    for (i = 0; i < sum.Length; i++)
    {
        if (sum[i] != num[rightEdge + i])
            return false; ;
    }
    if (i == num.Length - rightEdge)
        return true; ;
    return Verify(secondIndex, rightEdge, rightEdge + i  , num);
}

private string GetSum(int firstIndex, int secondIndex, int rightEdge, string num)
{
    StringBuilder sum = new StringBuilder();
    int carry = 0;
    for (int i = 1; i <= secondIndex - firstIndex || i <= rightEdge - secondIndex; i++)
    {
        int n = carry;
        n += i <= secondIndex - firstIndex ? num[secondIndex - i] - 48 : 0;
        n += i <= rightEdge - secondIndex ? num[rightEdge - i] - 48 : 0;
        carry = n / 10;
        n %= 10;
        sum.Insert(0, (char)(n + 48));
    }
    if (carry > 0)
        sum.Insert(0, '1'); ;
    return sum.ToString();
}
```
```cpp []
bool verify(int firstIndex, int secondIndex, int rightEdge, string num)
{
    string sum = getSum(firstIndex, secondIndex, rightEdge, num);
    if (num.length() - rightEdge < sum.length())
        return false; ;
    int i;
    for (i = 0; i < sum.length(); i++)
    {
        if (sum[i] != num[rightEdge + i])
            return false; ;
    }
    if (i == num.length() - rightEdge)
        return true; ;
    return verify(secondIndex, rightEdge, rightEdge + i  , num);
}

string getSum(int firstIndex, int secondIndex, int rightEdge, string num)
{
	string sum;
	int carry = 0;
    for (unsigned int i = 1; i <= secondIndex - firstIndex || i <= rightEdge - secondIndex; i++)
    {
        int n = carry;
        n += i <= secondIndex - firstIndex ? num[secondIndex - i] - 48 : 0;
        n += i <= rightEdge - secondIndex ? num[rightEdge - i] - 48 : 0;
        carry = n / 10;
        n %= 10;
        sum.insert(0,1,char(n + 48));
    }
	if (carry > 0)
		sum = sum.insert(0,1, '1'); ;
	return sum;
}

public:
    bool isAdditiveNumber(string num)
        {
        if (num.length() < 3)
            return false; ;
        for (int i = 0; i < num.length() / 2; i++)
        {
            if (num[0] == '0' && i > 0)
                return false; ;
            for (int j = 0; j < num.length() / 2; j++)
            {
                if (num[i + 1] == '0' && j > 1)
                    break; ;
                if (verify(0, i + 1, i + 2 + j, num))
                    return true; ;
            }
        }
        return false;
    }
```

其实如果用递归的话也许会更加高效，但在此就不做介绍了。

（话说我改初步代码的时候晕乎乎的……）






### 摘要：

给定一个整数数组，数组中恰好有**两个元素只出现一次**，其余**所有元素均出现两次**。 找出只出现一次的那两个元素。

这道题与[只出现一次的数字](https://leetcode-cn.com/problems/single-number/)十分相似，如果没有做过这道题（只出现一次的数字）的话，推荐先做一下。

***

### 解决方案：

**一、排序法解决：**

如果将数组进行排序后，相同的元素必然相邻，所以只需要判断某一元素是否与其相邻元素想相同即可获得唯一元素。

将数组排序的方法有很多，在这便不细究排序方法了，代码如下：

（排序法要比想象中的要繁琐……非常不推荐，代码又臭又长）

```csharp []
public int[] SingleNumber(int[] nums) 
{
    // C# 的 Sort 方法在最坏情况下时间复杂度为 On (log n)*1
    Array.Sort(nums);
    int[] result = new int[2];
    //通过标记给返回结果数组中下标为 0 或 1 的元素赋值
    bool sign = true;
    //判断首元素是否为唯一的数
    if (nums[0] != nums[1])
    {
        result[0] = nums[0];
        sign = false;
    }
    //判断尾元素是否为重复的数
    if (nums[nums.Length - 1] != nums[nums.Length - 2])
    {
        result[sign ? 0 : 1] = nums[nums.Length - 1];
        //尾元素和倒数第二个元素可能均为唯一数
        if(nums.Length > 2 && nums[nums.Length - 2] != nums[nums.Length - 3])
        {
            result[1] = nums[nums.Length - 2];
            return result;
        }
    }
    for (int i = 1; i < nums.Length - 1; i++)
    {
        //唯一数必然不等同于左右两边元素
        if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
        {
            result[sign ? 0 : 1] = nums[i];
            sign = false;
        }
    }
    return result;
}
```
```cpp []
vector<int> singleNumber(vector<int>& nums) 
{
    // C++ 的 sort 函数时间复杂度约为 On (log n)*2
    sort(nums.begin(), nums.end());
    vector<int> result;
    unsigned int length = nums.size();
    //判断首元素是否为唯一的数
    if (nums[0] != nums[1])
        result.push_back(nums[0]);;
    //判断尾元素是否为重复的数
    if (nums[length - 1] != nums[length - 2])
    {
        result.push_back(nums[length - 1]);
        //尾元素和倒数第二个元素可能均为唯一数
        if (length > 2 && nums[length - 2] != nums[length - 3])
        {
            result.push_back(nums[length - 2]);
            return result;
        }
    }
    for (int i = 1; i < length - 1; i++)
    {
        //唯一数必然不等同于左右两边元素
        if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
            result.push_back(nums[i]);;
    }
    return result;
}
```

*1：引自[C# Array.Sort ](https://docs.microsoft.com/zh-cn/dotnet/api/system.array.sort?view=netframework-4.8)
*2：引自[C++ sort](http://www.cplusplus.com/reference/algorithm/sort/)


**二、哈希集（HashSet）解决：**

因为所给数组所有重复元素均出现两次，而哈希集是不包含重复元素的集合，所以运用它来解决此题是十分合适的。

在此便直接列出代码，思路没啥好讲的了：

```csharp []
public int[] SingleNumber(int[] nums)
{
    HashSet<int> numbers = new HashSet<int>();
    foreach (int number in nums)
    {
        //在 C# 中，通过 HashSet 实例的 Add 方法添加元素时
        //如果添加元素已存在哈希集中，方法返回 False
        //注意逻辑非(!)操作符
        if (!numbers.Add(number))
            numbers.Remove(number); ;//重复便移除
    }
    return numbers.ToArray();
}
```
```cpp []
vector<int> singleNumber(vector<int>& nums) 
{
    unordered_set<int> numbers;
    for (int number : nums)
    {
        //在 C++ 中，通过 unordered_set 的 insert 方法添加元素时
        //将返回一个 pair<iterator, bool> 对象
        //其 second 为一布尔类型的值，标识是否添加成功
        //注意逻辑非(!)操作符
        if (!numbers.insert(number).second)
            numbers.erase(number);;//重复便移除
    }
    //还要转换一下
    vector<int> result(numbers.begin(),numbers.end());
    return result;
}
```

**三、位运算解决：**

在诸事之前，若还不了解按位异或操作符，请先了解一下按位异或操作符（Xor）的性质：

- 如果a、b两个值不相同，则异或结果为1。如果a、b两个值相同，异或结果为0（这里假设a、b 只能包含 1、0 两值，但别忘了，每个比特恰好是表示零和一的。也可以这么说：真 xor 假 = 真；真 xor 真 = 假；假 xor 假 = 假）。
- 满足交换律。
 
进而
1. 有a、b不等两值
2. a xor a = 0
3. b xor 0 = b
3. 所以：a xor b xor a = (a xor a) xor b = b xor 0 = b

通过按位异或操作符将数组中的每个数进行累加的异或操作便可以得出唯一的两个不同数的按位异或值。

如果对于按位异或操作符还是不大了解，可以看下我在只出现一次的数字的题解[按位异或操作符解析](https://leetcode-cn.com/problems/single-number/solution/cou-yi-pian-ti-jie-hua-shuo-ti-jie-hen-hao-wan-by-/)

但是，数组中有两个唯一元素，而非一个，通过依次遍历对每个元素进行单一的按位异或运算肯定取不到两个不同的数。

那么，如果能否将两个不同的数区分开来，分别进行按位异或运算呢？

当然可以！不要忘了，那是两个不同的数。也就是说，其异或结果于二进制的表达上，任意一个值为一的比特位便表示了两个数的不同（如果a、b两个值不相同，则异或结果为1。如果a、b两个值相同，异或结果为0）。

（注意，依次按位异或后，其值等于两个不同的数的异或值）

可以验算一下：
| 值 | 二进制 | 不同位 |
| ------ | ------ | ------ |
| 8 | 00001000 | 00001000 | 
| 3 | 00000011 | 00000011 |       
|按位异或|00001011|00001011|
| 13 | 00001101 | 00000100 | 
| 9 | 00001001 | 00000000 |       
|按位异或|00000100|00000100|

通过表格可知，任意两值的异或结果于二进制表达上，恰好包含了两值的不同值为一的位。所以，通过取得异或结果中任意值为一的比特位，判断每个数是否含有这个位（且位上的值为一）进行分组运算（包含与不包含的关系必然将数组区分为分别包含一个唯一数的两部分，并且，两部分除去唯一数后，其剩余元素均有重复），这样便可以得到不同的两个数了。

可是如何得到两个数按位异或结果的不同位呢？

显然，如保留一个位的话，必须要确保其它所有的位的值均为零。而使得所有位均为零的操作便是将值所有位经行取反操作，然后进行按位与（and）操作。

| 运算\值 | 10 | 9 |
| ------ | ------ | ------ |
| 二进制 | 00001010 | 00001001 | 
| 取反 | 11110101 | 11110110 |       
| 初值与取反按位与 | 00000000 | 00000000 | 

但是这还是不够的。按位与操作后所得值为零，不含任何一个值。但是，通过观察可以发现，如果将某一个值得取反值加一个一后，在进行按位与操作，所得位恰好为初始值的最低位为所代表得值。

| 运算\值 | 10 | 9 |
| ------ | ------ | ------ |
| 二进制 | 00001010 | 00001001 | 
| 取反 | 11110101 | 11110110 | 
| 取反后加一 | 11110110 | 11110111 |       
| 原值和取反加一的按位与结果 | 00000010 | 00000001 | 

（这里不知道怎么说才好，可以观察一下 10 和 9 二进制上得末位（最右边），然后再观察下取反值的末位。取反加一的话便要么末位由 0 变 1，要么进位。）

终于，通过一系列操作取得了异或结果中某一比特位所代表的值。并且，以上操作正好是计算机中正数到负数的转换过程。

| 运算\值 | 10 | 9 |
| ------ | ------ | ------ |
| 二进制 | 00001010 | 00001001 |
| 取反 | 11110101 | 11110110 | 
| 取反后加一 | 11110110 | 11110111 |  
| 0 - 值 | 11110110 | 11110111 |   

综上所述，得代码如下：

```csharp []
public int[] SingleNumber(int[] nums)
{
    int sign = 0;
    //取得数组中两个唯一数的按位异或结果
    for (int i = 0; i < nums.Length; i++)
    {
        sign ^= nums[i];
    }
    //获取区分两个唯一数的比特位所代表的值
    //也可以写成：sign &= (~sign) + 1
    sign &= -sign;
    int[] result  = new int[2];
    //通过标识，区分两个数组
    for (int i = 0; i < nums.Length; i++)
    {
        if ((nums[i] & sign) == sign)
            result[0] ^= nums[i];
        else
            result[1] ^= nums[i]; ;
    }
    return result;
}
```
```cpp []
vector<int> singleNumber(vector<int>& nums) 
{
    int sign = 0;
    //取得数组中两个唯一数的按位异或结果
    for (int i = 0; i < nums.size(); i++)
    {
        sign ^= nums[i];
    }
    //获取区分两个唯一数的比特位所代表的值
    //也可以写成：sign &= (~sign) + 1
    sign &= -sign;
    int n1 = 0, n2 = 0;
    //通过标识，区分两个数组
    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums[i] & sign) == sign)
            n1 ^= nums[i];
        else
            n2 ^= nums[i]; ;
    }
    return { n1,n2 };
}
```

***

**结尾：**

希望对大家能有所帮助！如有不足，恳请您斧正。


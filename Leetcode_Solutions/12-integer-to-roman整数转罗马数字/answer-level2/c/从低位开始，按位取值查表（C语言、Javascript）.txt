# 从低位开始，按位取值查表（C语言、Javascript）

先用 JS 快递构建基本算法验证算法可行性，再逐步使用 C语言 重写并进行负优化，最终最好情况下可以达到

- 执行用时 ***0ms***，击败 ***100%*** C 用户\*
- 内存消耗 ***6.9MB***，击败 ***92.27%*** C 用户\*

*数据来源：力扣 提交执行结果。*

## 题目分析

*由题目描述，可得*
罗马数字包含 7 种字符 `I`、`V`、`X`、`L`、`C`、`D`、`M`
罗马数字最大值为 **3999**
罗马数字最长值为 **MMM DCCC LXXX VIII** 即 **3888**

*所以可得*
表达 10 的 n次方 的数共有 4 个
表达 5 × 10 的 n次方 的数共有 3 个
因字符串需要以 `\0` 结尾，存储字符串的 char 数组长度最长需要 16 位

*如果*
*10 的 n次方 使用 B 表示，*
*10 的 n+1次方 使用 T 表示，*
*5 × 10 的 n次方 使用 F 表示，*
*可得对应关系*
|阿拉伯数字|罗马数字|
|-|-|
|0|无|
|1|B|
|2|BB|
|3|BBB|
|4|BF|
|5|F|
|6|FB|
|7|FBB|
|8|FBBB|
|9|BT|
其中 n 范围为 0-2 的整数

很明显，这样就可以通过构建一个大表查表来轻松搞定
这样不会太咸鱼了么？

## JS实现

观察表
可得 8、7、6 和 3、2、1 几个数都由 `x mod 5` 个 B 组成，即 8 包含 `8%5=3` 个 B，即 2 包含 `2%5=2` 个 B

JS 语言，使用 switch 进行上述实现，并对 4、5、6、9 进行单独处理，可得

```JavaScript
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
  const romanCharFive = ['V', 'L', 'D']
  const romanCharOne = ['I', 'X', 'C', 'M']
  let pointer = 0
  let result = ''
  while (num > 0) {
    const digits = num % 10
    switch (digits) {
      case 1:
      case 2:
      case 3:
        result = `${romanCharOne[pointer].padStart(
          digits,
          romanCharOne[pointer]
        )}${result}`
        break
      case 4:
        result = `${romanCharOne[pointer]}${romanCharFive[pointer]}${result}`
        break
      case 5:
        result = `${romanCharFive[pointer]}${result}`
        break
      case 6:
      case 7:
      case 8:
        result = `${romanCharFive[pointer]}${romanCharOne[pointer].padStart(
          digits - 5,
          romanCharOne[pointer]
        )}${result}`
        break
      case 9:
        result = `${romanCharOne[pointer]}${romanCharOne[pointer + 1]}${result}`
        break
    }
    // JS 中的 number 为 64 位浮点数，此处位运算用于取整
    // parseInt(3.14,10) 和 3.14 >> 0 返回值是一致的
    num = (num / 10) >> 0
    pointer++
  }
  return result
}
```

提交，AC，在 JavaScript 用户中，耗时 228ms 击败 81.82%，内存 40.5MB，击败 68.15%

## 移植到C

C 语言中基本类型不包含 string ，字符串实为一个 `\0` 结尾的 char 类型数组
所以前文中分析得出的字符串长度上限可以在这里很好地防止不必要的内存申请产生浪费
```C
char *intToRoman(int num)
{
  char *result = malloc(sizeof(char) * 16);
  result[15] = '\0';
  char romanCharFive[3] = {'V', 'L', 'D'};
  char romanCharOne[4] = {'I', 'X', 'C', 'M'};
  int digits;
  unsigned char numPointer = 0;
  char pointer = 14;
  while (num)
  {
    digits = num % 10;
    switch (digits)
    {
    case 3:
      result[pointer--] = romanCharOne[numPointer];
    case 2:
      result[pointer--] = romanCharOne[numPointer];
    case 1:
      result[pointer--] = romanCharOne[numPointer];
      break;
    case 4:
      result[pointer--] = romanCharFive[numPointer];
      result[pointer--] = romanCharOne[numPointer];
      break;
    case 8:
      result[pointer--] = romanCharOne[numPointer];
    case 7:
      result[pointer--] = romanCharOne[numPointer];
    case 6:
      result[pointer--] = romanCharOne[numPointer];
    case 5:
      result[pointer--] = romanCharFive[numPointer];
      break;
    case 9:
      result[pointer--] = romanCharOne[numPointer + 1];
      result[pointer--] = romanCharOne[numPointer];
      break;
    }
    num = num / 10;
    numPointer++;
  }
  return result + pointer + 1;
}
```

运行，AC，但发现执行用时 12ms ，金击败了 45.5% 的 C语言用户，怀疑是 switch 导致的性能问题，尝试修改。

## 优化

参考 *[整数转罗马数字（低位开始）——雨中音醉](https://leetcode-cn.com/problems/integer-to-roman/solution/zheng-shu-zhuan-luo-ma-shu-zi-di-wei-kai-shi-by-je/)* 的解题方案，并在其基础上减少循环次数，完成从 switch 到 if else 流程控制的结构修改。

```C
// Switch 使用 while(true) 重写
char *intToRoman(int num)
{
  // 前略
  char pointer = 14;
  while (num)
  {
    digits = num % 10;
    // 此处 while 并不用于循环，仅用于使用 break 进行流程控制
    while (true)
    {
      if (digits == 8)
      {
        result[pointer--] = romanCharOne[numPointer];
        digits--;
      }
      if (digits == 7)
      {
        result[pointer--] = romanCharOne[numPointer];
        digits--;
      }
      if (digits == 6)
      {
        result[pointer--] = romanCharOne[numPointer];
        digits--;
      }
      if (digits == 5)
      {
        result[pointer--] = romanCharFive[numPointer];
        break;
      }
      if (digits == 4)
      {
        result[pointer--] = romanCharFive[numPointer];
        digits = 1;
      }
      if (digits == 9)
      {
        result[pointer--] = romanCharOne[numPointer + 1];
        digits = 1;
      }
      if (digits == 3)
      {
        result[pointer--] = romanCharOne[numPointer];
        digits--;
      }
      if (digits == 2)
      {
        result[pointer--] = romanCharOne[numPointer];
        digits--;
      }
      if (digits == 1)
      {
        result[pointer--] = romanCharOne[numPointer];
        break;
      }
      break;
    }
    num = num / 10;
    // 后略
}
```

执行时间达到 8ms ，可推测 if 在这个案例中相较 switch 更快，但可以发现相较于 *[整数转罗马数字（低位开始）——雨中音醉](https://leetcode-cn.com/problems/integer-to-roman/solution/zheng-shu-zhuan-luo-ma-shu-zi-di-wei-kai-shi-by-je/)* 的解题方案，上文代码中虽然使用了 `while(1){}`，但未实际进行循环，故可以使用 `do{}while(1) ` 结构来减少一次判断，同理也可修改 `while(num){}` 为 `do{}while(num)`

参考雨中音醉的解法，再修改用于记录罗马数字的数组数量，由两个缩减为一个，减少一个数组的使用，进一步节约内存空间。

## 最终代码

如下：

```C
/**
 * 转换一个 1-3999 的 int 整数到罗马数字
 * 字符串由后向前计算
 * @author Handle 
 * @return 返回转换好的字符串
 */
char *intToRoman(int num)
{
  /**
   * 输出结果字符串
   * 3888 为最大长度 MMMDCCCLXXXVIII 共 15 位，故申请 16 位长度
   * 使用 static 数组在缺失 malloc 时使用
   */
  // char *result = malloc(sizeof(char) * 16);
  static char result[16];

  /**
   * 储存五和十
   * 使用一个而不是两个数组来节省内存
   */
  // char romanCharFive[3] = {'V', 'L', 'D'};
  // char romanCharOne[4] = {'I', 'X', 'C', 'M'};
  char romanChar[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

  /**
   * 用于记录单独一位数
   */
  int digits;

  /**
   * 用于记录当前是哪一位
   */
  char numPointer = 0;

  /**
   * 当前字符串位置
   */
  char pointer = 14;

  // 输入数一定大于 1，后置判断减少第一次判断
  do
  {
    // 通过 求余 得到单独一位的数值
    digits = num % 10;
    // 循环仅供使用 break，不进行任何判断
    do
    {
      // 8~5 区间
      if (digits == 8)
      {
        result[pointer--] = romanChar[numPointer];
        digits--;
      }
      if (digits == 7)
      {
        result[pointer--] = romanChar[numPointer];
        digits--;
      }
      if (digits == 6)
      {
        result[pointer--] = romanChar[numPointer];
        digits--;
      }
      if (digits == 5)
      {
        result[pointer--] = romanChar[numPointer + 1];
        break;
      }
      // 4~1 区间
      if (digits == 4)
      {
        result[pointer--] = romanChar[numPointer + 1];
        digits = 1;
      }
      if (digits == 3)
      {
        result[pointer--] = romanChar[numPointer];
        digits--;
      }
      if (digits == 2)
      {
        result[pointer--] = romanChar[numPointer];
        digits--;
      }
      if (digits == 1)
      {
        result[pointer--] = romanChar[numPointer];
        break;
      }
      // 9
      if (digits == 9)
      {
        result[pointer--] = romanChar[numPointer + 2];
        /**
         * 也可以将 digits == 1 段移到该段下方
         * 并将 digits 值设置为 1 来代替下行
         */
        result[pointer--] = romanChar[numPointer];
        break; // 本句多余
      }
      // 0
      break;
    } while (true); // 这个 while(true) 永远不会被判断

    // 去掉已经被处理完毕的末位
    num /= 10;

    // 改变位数标记
    numPointer += 2;

  } while (num); // 如果还有 任意位 尚未处理完毕，则继续循环
  /**
   * 因为 pointer 在每次使用后会自减到一个内容为空的下标
   * 所以最后输出结果需要 +1
   */
  return result + pointer + 1;
}
```

似乎是评测机随缘等问题，内存占用 6.8M ~ 7M 波动，时长则在 0ms~8ms 波动，总之……算是暂时想不到什么更好的优化方式了……还请正在阅读的您赐教啦！

## 碎碎念

说起来LeetCode题什么的……
完全是大学同学要手柄过来做的，
还专门说这道题看起来有意思但是做起来很无聊
然后手柄就真跑来了……
一开始明明只是心情很郁闷想要随便做几道题解闷
结果最后只在意排名了……
心态摆不正，只想着击败击败……
唔……AC不就行了么，笑
明明是手柄只是某屑专科学生……

刚才看到还有贪心算法……于是，手柄是不是要试一下呢？

总之，希望这篇题解能够帮到你！欢迎留言
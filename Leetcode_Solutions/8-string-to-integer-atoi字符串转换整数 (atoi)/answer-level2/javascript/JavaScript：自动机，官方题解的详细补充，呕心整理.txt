### 前言
关于这道题，之前利用了`parseInt()`这一API来巧妙解题，有兴趣的同学可以移步[这里](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/javascripttou-ji-qu-qiao-wu-xu-si-kao-yi-kan-jiu-h/)查看思路。

当作者阅读[官方题解](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/)时，发现了“自动机”这一解题思路，阅读后欣喜若狂，感觉打开了知识的大门。

激动之余，特地写下这篇题解，以便加深对“自动机”理念的理解，也供有兴趣的小伙伴一起学习。

为了防止日后遗忘，本篇题解会异常详尽，故篇幅可能有些冗长，不过如果你耐心阅读，相信一定会物有所值。

### 题意分析

无论你事先有没有阅读过官方题解，这里统一从头分析一遍。

何谓“自动机”？这里引用LeetCode官方的解释：

**我们的程序在每个时刻有一个状态`s`，每次从序列中输入一个字符`c`，并根据字符`c` 转移到下一个状态`s'`。这样，我们只需要建立一个覆盖所有情况的从`s`与`c`映射到`s'`的表格即可解决题目中的问题。**

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/
来源：力扣（LeetCode）

是不是觉得这句话有点拗口？没关系，我会用更加通俗易懂的语言来为你讲解一遍。

##### 状态分析
首先，从题意中，我们很轻易地可以知道，字符串`str`中的每个字符，都有可能是以下的四种类型中的一种：
- 空格字符`' '`（Space）
- 正负号`+`和`-`(Sign)
- 字符串型的数值（Number）
- 除以上三种情况外的任何情况（Other）

##### 阶段分析
如果想要将字符串转换为整数，那么必然会经历这四个**有序**的阶段：
1. 开始转换（start）
2. 判断正负（signed）
3. 生成数值（in_number）
4. 结束转换（end）

##### 生成自动机
这步是最为关键的一步，它将状态和阶段巧妙地结合了起来。

话不多说，让我们先来看一个表格：
![1585925170(1).png](https://pic.leetcode-cn.com/0ee783ff33682169033d26832e12619ef5186cff4ec46fa7449ab548b458fb56-1585925170\(1\).png)

现在来说明下这个表格的含义。

不同的**行**象征不同执行阶段：
- 第0行：开始转换阶段
- 第1行：判断正负阶段
- 第2行：生成数值阶段
- 第3行：结束转换阶段

不同的**列**象征不同的字符类型：
- 第0列：字符为空格
- 第1列：字符为正、负号
- 第2列：字符为字符型数值
- 第3列：字符为其他形式

由行、列确定的坐标，象征着**下一个**字符所处的执行阶段。

例如，官方的`str`例子：`"   -42"`,就会进行如下的**转换流程**（*请结合表格认真阅读，这对你理解“自动机”的概念很有帮助*）：

1. 一开始，必然是开始阶段，所以从第0行，即`[0, ?]`
2. 第一个字符是空格，找到空格所在的列，即`[?, 0]`
3. 结合行、列，即`[0, 0]`,发现将为下一个字符执行`state`阶段
4. 所以第二个字符还是从第0行开始，即`[0, ?]`
5. 第二个字符是空格，空格的列数是`[?, 0]`
6. 所以第三个字符的还是执行`state`阶段（`[0, 0]`）
7. ...（空格的分析不再赘述）
8. 发现字符是负号`-`,而此时是在第0行（之前空格的原因），所以坐标是`[0, 1]`，
9. 那么可以下一个字符的执行阶段是`signed`，即第1列（`[1, ?]`）
10. 接下来的字符是字符型的`4`，则列数是`[?, 2]`
11. 所以坐标确定为`[1, 2]`，则下一个字符的执行阶段是`in_number`,即`[2, ?]`
12. 这次的字符还是字符型（`2`），则依旧定位到`[?, 2]`，则下一个字符执行`in_number`阶段
13. 没有字符了，遍历结束
14. 依据负号和数值,得出转换结果为`-42`

现在你理解了如何由状态和阶段构建自动机了吧？

以上的这些步骤描述，其实就是LeetCode官方图例所表达的意思。
![8_fig1.png](https://pic.leetcode-cn.com/38f1d911b9187aad7c823607e7a8b69e886cd14d298d06fc437763661d91e5b2-8_fig1.png)
图片作者：LeetCode-Solution
图片链接：https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/
图片来源：力扣（LeetCode）

### 代码实现
以下是具体的代码实现，参考了LeetCode的官方示例C++代码。

由于作者是个JSer，所以采用JavaScript来进行实现。

代码中的各类关键点、易错点、优化点等等，都一一进行了详尽的备注说明。

如果你还有任何不理解或疑惑的地方，欢迎在评论区提出，作者有看到都会第一时间进行回复解答。

话不多说，看代码吧~
```
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
  class Automaton{
    constructor() {
      // 执行阶段，默认处于开始执行阶段
      this.state = 'start';
      // 正负符号，默认是正数
      this.sign = 1;
      // 数值，默认是0
      this.answer = 0;
      /*
      关键点：
      状态和执行阶段的对应表
      含义如下：
      [执行阶段, [空格, 正负, 数值, 其他]]
      */
      this.map = new Map([
        ['start', ['start', 'signed', 'in_number', 'end']],
        ['signed', ['end', 'end', 'in_number', 'end']],
        ['in_number', ['end', 'end', 'in_number', 'end']],
        ['end', ['end', 'end', 'end', 'end']]
      ])
    }

    // 获取状态的索引
    getIndex(char) {
      if (char === ' ') {
        // 空格判断
        return 0;
      } else if (char === '-' || char === '+') {
        // 正负判断
        return 1;
      } else if (typeof Number(char) === 'number' && !isNaN(char)) {
        // 数值判断
        return 2;
      } else {
        // 其他情况
        return 3;
      }
    }

    /*
    关键点：
    字符转换执行函数
    */
    get(char) {
      /*
      易错点：
      每次传入字符时，都要变更自动机的执行阶段
      */
      console.log(char);
      this.state = this.map.get(this.state)[this.getIndex(char)];

      if(this.state === 'in_number') {
        /*
        小技巧：
        在JS中，对字符串类型进行减法操作，可以将得到一个数值型（Number）的值

        易错点：
        本处需要利用括号来提高四则运算的优先级
        */
        this.answer = this.answer * 10 + (char - 0);
        /*
        易错点：
        在进行负数比较时，需要将INT_MIN变为正数
        */
        this.answer = this.sign === 1 ? Math.min(this.answer, Math.pow(2, 31) - 1) : Math.min(this.answer, -Math.pow(-2, 31));
      } else if (this.state === 'signed') {
        /*
        优化点：
        对于一个整数来说，非正即负，
        所以正负号的判断，只需要一次。
        故，可以降低其判断的优先级
        */
        this.sign = char === '+' ? 1 : -1;
      }
    }
  }

  // 生成自动机实例
  let automaton = new Automaton();

  // 遍历每个字符
  for(let char of str) {
    // 依次进行转换
    automaton.get(char);
  }

  // 返回值，整数 = 正负 * 数值
  return automaton.sign * automaton.answer;
};
```
都看到这里，如果觉得本题解对你有帮助或者说写得不错，烦请顺手点个赞~

码字不易，感谢阅读~




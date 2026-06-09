### 题意分析
首先，读题。

题目要求，**将整副牌分组，组内每张牌的数值相同，各组牌的张数相同**。

你品，你细品。

是不是很类似打牌时的“打对子”？只不过现在“对子”的张数不再是`2`，而是**大于等于`2`**。并且你手中的这副牌，全都是由该张数组成的“对子”。

所以这样一来，基础的代码逻辑就跃然纸上：
- 统计牌面数值的出现次数
- 分析合适的每组张数

### 逻辑梳理
##### 次数统计
次数统计非常简单，只需要遍历`deck`数组，依次统计出现的次数就行。

如果你事先看过官方题解的话，会发现这步是使用数组来统计，如下：
```
/* Java语言*/
int[] count = new int[10000];
for (int c: deck)
    count[c]++;

int g = -1;
for (int i = 0; i < 10000; ++i) {
    ...
}

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/solution/qia-pai-fen-zu-by-leetcode-solution/
来源：力扣（LeetCode）
```

个人觉得这种情况下使用**哈希表**会比较节省性能，毕竟遍历一个长度为`1000`的数组，还不一定每个位置都有值，性能上难免有点不划算。

详细代码如下：
```
// 相同牌出现次数Map
let timeMap = new Map();

// 遍历牌
deck.forEach(num => {
    // 统计每张牌出现的次数
    timeMap.set(num, timeMap.has(num) ? timeMap.get(num) + 1 : 1);
});

// Map.protype.values()返回的是一个新的Iterator对象，所以可以使用扩展运算符(...)来构造成数组
let timeAry = [...timeMap.values()];
```

##### 张数分析
如果有做过LeetCode第1071题[字符串的最大共因子](https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/)的话，很容易会想到，使用**辗转相除法**就可以解决张数的问题。

*小声提一句，第1071题我也写了题解，想要参考思路的同学可以点击[这里](https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/solution/javascript-zhan-zhuan-xiang-chu-fa-fu-xiang-jin-ji/)查看。*

当然没做过也没关系，本处会再从头分析一遍。

我们知道，每一组都有`X`张牌，那么`X`和卡牌总数`N`是什么关系？

从数学的角度上说，**`X`是`N`的约数**。

回顾下两个数学概念：

- **约数**。整数`a`除以整数`b(b≠0)`除得的商正好是整数而没有余数，那么整数`b`称为`a`的约数。即`4`的正约数有：`1`、`2`、`4`。代入到题目中，你现在有`2`个`2`，`4`个`4`，你就可以打出`[2, 2]`, `[4, 4]`, `[4, 4]`的打法。
- **最大公约数**。两个或多个整数共有约数中最大的一个被称为最大公约数。举例：求数值`3`和数值`9`的最大公约数。数值`3`的正约数有`1, 3`，数值`9`的正约数有`1, 3, 9`，数值`3`与数值`9`约数并集（既存在`3`的约数集中，又存在`9`的约数集中的数的集合）为`1、3`。则最大公约数为`3`。写作`gcd(3, 9) = 3`。附，`gcd`是英文`Greatest Common Divisor`（最大公约数）的缩写。代入到题目中，你现在有`2`个`2`，`4`个`4`，`6`个`6`，那么为了满足题意（张数大于等于`2`），所以是这么打：`[2, 2]`, `[4, 4]`, `[4, 4]`,`[6, 6]`, `[6, 6]`, `[6, 6]`。

那么问题的关键就可以，如何求得最大公约数？在数学中，可以利用辗转相除法来计算最大公约数。

辗转相除法是以除数和余数反复做除法运算，当余数为 0 时，取当前算式除数为最大公约数的计算公式。如下：
1997 / 615 = 3 (余 152)
615 / 152 = 4(余7)
152 / 7 = 21(余5)
7 / 5 = 1 (余2)
5 / 2 = 2 (余1)
2 / **1** = 2 (余0)
至此，最大公约数为1。

由此，可以写出gcd函数：
```
// 最大公约数计算公式
function gcd(num1, num2) {
    // 利用辗转相除法来计算最大公约数
    return num2 === 0 ? num1 : gcd(num2, num1 % num2); 
}
```
当然，本处只是求最大公约数，为了满足题意，最后还需要**判断该公约数是否大于等于2**。

### 代码实现
以下是具体的代码实现，结合注释食用更佳~
```
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
    // 最大公约数计算公式
    function gcd(num1, num2) {
        // 利用辗转相除法来计算最大公约数
        return num2 === 0 ? num1 : gcd(num2, num1 % num2); 
    }

    // 相同牌出现次数Map
    let timeMap = new Map();

    // 遍历牌
    deck.forEach(num => {
        // 统计每张牌出现的次数
        timeMap.set(num, timeMap.has(num) ? timeMap.get(num) + 1 : 1);
    });

    // Map.protype.values()返回的是一个新的Iterator对象，所以可以使用扩展运算符(...)来构造成数组
    let timeAry = [...timeMap.values()];

    /*
    最大公约数
    因为该数组是出现次数数组，最小值至少为1（至少出现1次），所以默认赋值为数组首位对公约数计算无干扰
    */
    let g = timeAry[0];

    // 遍历出现次数，计算最大公约数
    timeAry.forEach(time => {
        // 因为需要比较所有牌出现次数的最大公约数，故需要一个中间值
        g = gcd(g, time);
    });

    // 判断是否满足题意
    return g >= 2;
};
```



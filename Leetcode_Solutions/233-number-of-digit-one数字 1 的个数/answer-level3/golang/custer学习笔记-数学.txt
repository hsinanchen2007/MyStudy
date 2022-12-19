### 解题思路 - 暴力解法 超时
暴力解法从i遍历到n，然后去判断整数i,每个十进制位上是否为1，是的话计数器就+1。

判断整数i上有多少个数字1，只需要循坏两个操作即可。

	* 第一个是对10取模，看整数i个位上的数字是否等于1，是的话计数器就加1，
	* 第二个是把i除以10，来更新i，这样相当于把十位上的数字移动到了个位，

不断执行这两个操作，直到整数i变成了0。

暴力解法需要循环n次去计算每个整数上1出现的次数。

而对每个整数进行计算，需要的时间和它十进制表示的长度相关，数字n十进制表示的长度是logn，以10为底。

因此总的时间复杂度是O(nlogn),不需要额外的存储空间，因此空间复杂度是O(1)。

暴力解法的解题思路，是一个整数一个整数的去计算整数1出现的次数。

### 代码

```golang
// 暴力解法 Time: O(n*log10(n)), Space: O(1)
func countDigitOne(n int) int {
  // 边界情况
  if n < 1 {
    return 0
  }
  count := 0 // 初始化计数器为0
  for i := 1; i <= n; i++ { // 接着i从整数1遍历到整数n
    num := i       // 将整数i赋值为num
    for num != 0 { // 当num不等于0时不断执行以下操作
      if num%10 == 1 { // 先对10取模看个数上的数字是否等于1
        count++ // 如果是计数器+1
      }
      num = num / 10 // 然后除以10来更新num
    }
  }
  return count // 循环结束后返回count即可
}
```

### 解题思路 - 数学方法
换个思路来解决这个问题，不是从每个整数上来计算1出现的次数，

而是从个位，十位，百位，这些十进制位上切入，来计算1出现的次数。

比如n的十进制表示为abcde,

当前考察的十进制为是c，比c高的十进制位是high，比如这里ab就为high，

比c低的十进制位表示的数字为low，比如这里de就为low。

当前位数用factor表示，比如考察的是十位，factor则为10，考察百位则为100，

- 这样一来当c等于0时，1在当前位上出现的次数就等于high*factor,
- 当c等于1时，1在当前位上出现的次数就等于high*factor+low+1.
- 而对于其他情况，1在当前位上出现的次数就等于(high+1)*factor。

使用这种方法我们就只需要一个个处理整数n的十进制位就可以得到1出现的次数。

因此时间复杂度是O(logn),log 以10 位底，不需要使用额外的存储空间，因此空间复杂度是O(1)。

### 代码

```golang
// 使用数学方法 Time: O(log10(n)), Space: O(1)
func countDigitOne(n int) int {
  // 边界情况
  if n < 1 {
    return 0
  }
  count, factor := 0, 1 // 初始化计数器为0,和位数初始化为1
  for n/factor != 0 {   // 当整数n除以factor不等于0时
    // 不断执行之下操作
    // 先求出当前位上的数字digit
    digit := (n / factor) % 10 // n除以factor再对10取模
    // 然后计算更高位的数字high
    high := n/(10*factor) // n除以10倍的factor
    if digit == 0 {// 如果当前位数的数字等于0
      count+=high*factor // 计数器则加上high乘以factor
    } else if digit == 1 { // 如果当前位数字等于1
      count+=high*factor // 计数器不仅要加上igh乘以factor
      count+=(n%factor)+1 // 还要加上低位数字(n对factor取模即可求出)再加1
    } else { // 如果是其他情况
      count+=(high+1)*factor // 计数器则加上(high+1)乘以factor
    }
    // 计算完当前factor位上1出现的次数
    factor = factor*10 // factor乘以10进行更新,准备计算下一个十进制位
  }
  return count // 循环结束后返回count即可。
}

```
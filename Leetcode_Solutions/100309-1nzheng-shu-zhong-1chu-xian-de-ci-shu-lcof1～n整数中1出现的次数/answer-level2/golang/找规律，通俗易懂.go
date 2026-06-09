# 解题思路
- 这类题一定是有规律可循的，可以分别计算个位、十位、百位上的1,循环相加即可。
- 为了快速找到规律，我们可以直接分析**1~n的十位**上1的个数。
十位上的有1的数包括10,11,12...19,......,110,111...119,......,210,211...219......
不难看出，100以内有10个，200以内有20个...，当然，事情要比这稍微复杂一点，
- 如果n是**105**，那么1~109中符合条件的只有**10~19**，一共10个；
如果n是**115**，那么符合条件的有**10~19,110~115**，一共10+6=16个；
如果n是**125**，那么符合条件的有**10~19,110~119**，一共20个。

![1出现的次数.png](https://pic.leetcode-cn.com/bfc2802d72177f3dbe5e3bd44e8cae01e588a9213833ef0f1e7e46f16ea1c069-1%E5%87%BA%E7%8E%B0%E7%9A%84%E6%AC%A1%E6%95%B0.png)

- 接下来就简单了，可以将情况分为三种：
1. **n%100 < 10** => (n/100)*10
2. **10 <= n%100 < 20** => (n/100)*10 + n%100 - 10 + 1
3. **n%100 >= 20** => (n/100)*10 + 10
- 而每次统计是以10为倍数的，所以可以定义一个pow变量表示10的N次方，
考虑十位上的1时，pow=10，将公式转化为
1. n/(pow*10)*pow
2. n/(pow*10)*pow + n%(pow×10) - pow + 1
3. n/(pow*10)*pow + pow
- 上述公式对于个位也是适用的，可以分为n%10 < 1，n%10 >= 2，和n%10 = 1三种情况，后两种结果一样。
- 循环的结束条件取决于n最多有多少位，每次pow*10，n小于pow退出。
- 可以令增量incr = n%(pow*10) - pow + 1，小于0则取0，大于pow则取pow，代码会简短一些。
# 完整代码
```
func countDigitOne(n int) int {
    count, pow := 0, 1
    for n >= pow {
	count += n / (pow * 10) * pow
	if incr := n%(pow*10) - pow + 1; incr > pow {
	    count += pow
	} else if incr > 0 {
	    count += incr
	}
	pow *= 10
    }
    return count
}
```
**复杂度分析**
- 时间复杂度：O(logn)
- 空间复杂度：O(1)

**最后附上书中递归思路代码**
```
func countDigitOne(n int) int {
    strN := strconv.Itoa(n)
    return numberOf1(strN)
}

func numberOf1(strN string) int {
    if len(strN) == 0 {
	return 0
    }
    first := int(strN[0] - '0')
    if len(strN) == 1 && first == 0 {
	return 0
    }
    if len(strN) == 1 && first > 0 {
	return 1
    }
    var numFirstDigit int
    if first > 1 {
	numFirstDigit = int(math.Pow10(len(strN) - 1))
    } else if first == 1 {
	post, _ := strconv.Atoi(strN[1:])
	numFirstDigit = post + 1
    }
    numOtherDigits := first * (len(strN) - 1) * int(math.Pow10(len(strN)-2))
    numRecursive := numberOf1(strN[1:])
    return numFirstDigit + numOtherDigits + numRecursive
}
```
**两种方法Benchmark对比**
![两种方法benchmark对比.png](https://pic.leetcode-cn.com/b406b8bf7c8a41d56c030cbbf1abfafcd54f5d0e37269034680f35ad9429e25f-%E4%B8%A4%E7%A7%8D%E6%96%B9%E6%B3%95benchmark%E5%AF%B9%E6%AF%94.png)

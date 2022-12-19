前面两种解法不使用任何API， 最后使用go标准库函数实现正则匹配版本，供有需要的人参考。

```go
package lt8

import (
	"fmt"
	"log"
	"math"
	"regexp"
	"strconv"
	"strings"
	"unicode"
)

// 字符串转换整数
//请你来实现一个 atoi 函数，使其能将字符串转换成整数。
//
//首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
//
//当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
//
//该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
//
//注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
//
//在任何情况下，若函数不能进行有效的转换时，请返回 0。
//
//说明：
//
//假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。
//
//示例 1:
//
//输入: "42"
//输出: 42
//示例 2:
//
//输入: "   -42"
//输出: -42
//解释: 第一个非空白字符为 '-', 它是一个负号。
//     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
//示例 3:
//
//输入: "4193 with words"
//输出: 4193
//解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
//示例 4:
//
//输入: "words and 987"
//输出: 0
//解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
//     因此无法执行有效的转换。
//示例 5:
//
//输入: "-91283472332"
//输出: -2147483648
//解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
//     因此返回 INT_MIN (−231) 。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/string-to-integer-atoi
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// 1079/1079 cases passed (0 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 71.66 % of golang submissions (2.3 MB)
func myAtoi(str string) int {
	l := len(str)
	if l == 0 {return 0}

	sign := true	// sign为数字的符号，true表示正， false表负

	// 由于需要左起遍历找到数字开头，右起遍历找到数字结尾已确定数字的最高位是多少
	// 所以不可能一次遍历完成
	// 两种做法： 1. 用辅助数组把连续的整数段给保存起来，第二次遍历这个数组; 2. 记录开始和结束的位置，第二次遍历直接遍历字符串这个范围
	// 这里采取第二种做法

	// 找到 start
	start := -1
	for i:=0; i<l; i++ {
		start++		//从0开始
		if str[i] != 32 {	// ' ' 32		// start要跨越开头的数字0
			if str[i] > 48 && str[i] < 58 {break}	// 找到起始位置，注意这里不含0
			if str[i] == 48 {
				start = findStart(str, i+1, l-1)
				if start == -1 {		// 说明找到了有效的值
					return 0
				}
				break
			}
			if str[i] == 43 && i < l-1 && (str[i+1] > 47 && str[i+1] < 58) {	// '+' 43	// 谨防越界（i<l-1）
				start = findStart(str, i+1, l-1)
				if start == -1 {		// 说明找到了有效的值
					return 0
				}
				break
			}
			if str[i] == 45 && i < l-1 && (str[i+1] > 47 && str[i+1] < 58) {	// '-' 45
				start = findStart(str, i+1, l-1)
				if start == -1 {		// 说明找到了有效的值
					return 0
				}
				sign = false
				break
			}
			// 其余情况则应该退出
			return 0
		}
		// 注意这里有个问题，没有处理空格到字符末尾的情况，所以加上下面这个判断
		if str[i] == 32 && i == l-1 {	// str[i]==32不是必须，只是为了看起来清楚
			return 0
		}
	}

	// 找到 end
	end := start
	for i:=start+1; i<l; i++ {
		if str[i] < 48 || str[i] > 57 {	// 不是'0'~'9'
			break
		}
		// i 从start位置下一个开始， 如果当前不是数字，则将 end从start位置后移
		end++		//从start+1开始
	}

	// 得到有效数字下标范围 [start, end]
	nums := end - start + 1		// 数字的位数

	// 由于测例中会出现远大于int64的数字，以致于int64都会溢出
	// 所以先判断位数进行粗略的拦截大数。int32最大值是2147483647， 10位数，所以如果nums>10直接返回上/下限
	if nums > 10 {
		if sign {
			return math.MaxInt32
		} else {
			return math.MinInt32
		}
	}

	var integer int64		// 因为返回int32，为了处理溢出，使用int64
	var factor int64
	for i:=1; i<=nums; i++ {
		factor = 1
		for j:=2; j<=i; j++ {factor = factor*10}
		integer += int64(str[end+1-i]-48)*factor
	}

	// // 判断integer有没有越过int32的上下限 // -1 << 31  ~  1 << 31 -1
	if sign {
		if integer > math.MaxInt32 {return math.MaxInt32}
	} else {
		integer = -integer
		if integer < math.MinInt32 {return math.MinInt32}
	}

	return int(integer)
}

// 在索引范围中找到想要的start; 这个子函数不处理正负号的问题，符号由主函数处理
// 只负责从 '+' '-'之后开始搜寻 非0 start
func findStart(str string, l, r int) int {
	for i:=l; i<=r; i++ {
		switch str[i] {
		case '0':
			continue
		case '1', '2', '3', '4', '5', '6', '7', '8', '9':
			return i	// 找到start
		default:
			return -1	// start = -1 告诉主函数不用看了，直接最终返回0
		}
	}
	// for完了都没return说明遍历的全是0
	return -1
}


// 又一次把代码写得这么复杂...
// 虽然还有一些简化的思路，但不试了，直接看看题解区

// 首先看了shank3的解法，大致思路和我的一样，先找到开始位置，再找结束位置，然后处理得到的子串
// 关键点在子串的处理上，我是用了int64而且为了除去子串高位的0，在找start的代码段中加入了大量的条件语句
// 尽管最后通过了测试，但仍然是不符题意的解答。
// 这次吸收下shank3解答中关于子串解析数字的防溢出方法（它这么做不用额外处理前部的0）

// 1079/1079 cases passed (4 ms)
//Your runtime beats 59.07 % of golang submissions
//Your memory usage beats 71.66 % of golang submissions (2.3 MB)
func myAtoi2(str string) int {
	l := len(str)
	if l == 0 {return 0}

	sign := true	// sign为数字的符号，true表示正， false表负

	// 找到 start, 这里用 i 表示start
	var i int
	for i=0; i<l; i++ {		// 注意 i 在循环中发生改变
		if str[i] >= '0' && str[i] <= '9' {break}
		if str[i] == '+' || str[i] == '-' {
			sign = str[i] == '+'
			i++		// start移到符号位后一位
			break
		}
		// 其他非空格字符情况
		if str[i] != ' ' {return 0}
		// 空格则继续向右遍历
	}
	// 到这里 i (也就是start) 指向了 可能1.第一个数字位置； 可能2.符号位后一位； 可能3.字符串最末位后一位

	// 找到 end，这里用 j 表示
	var j int
	for j=i; j<l; j++ {
		if str[j] < '0' || str[j] > '9' {break}		// 不是'0'~'9'就退出循环
	}
	// 到这里 j 可能1.停在i(因为符号位下一个就不是数字)； 可能2.正常后移直至找到非数字位就停止，此时j指向了第一个出现的非数字的字符位置
	// i, j 所包围的部分前部全是'0'~'9'

	subStr := str[i:j]
	ret := 0
	for k:=0; k<len(subStr); k++ {	// 从高位向后遍历
		cur := subStr[k] - '0'		// 当前位数字
		if sign {	// 正
			if ret > math.MaxInt32 / 10 || (ret == math.MaxInt32 / 10 && cur > 7) {	// 1 << 31 -1 = 2147483647 (个位数7)
				return math.MaxInt32
			}
			ret = ret * 10 + int(cur)
		} else {	// 负
			if ret < math.MinInt32 / 10 || (ret == math.MinInt32 / 10 && cur > 8) {	// -1 << 31 = -2147483648 （个位数8）
				return math.MinInt32
			}
			ret = ret * 10 - int(cur)	// 注意这里第一次 ret = 0 * 10 - cur 就转为负数了
		}
	}

	return ret
}

// 这个解法效率不高，就是因为没有处理数值子串subStr中的前缀0.
// 很奇怪题解区看到有人用一模一样的思路和写法提交的go题解击败了100%.

// 第二次提交时优化了数字序列前缀0，达到了时间超越100%

func myAtoi21(str string) int {
	// 一般解法，先找整数序列起点，再找终点，最后再处理整数串转换

	maxInt32, minInt32 := 1<<31-1, -1<<31

	l := len(str)
	if l == 0 {return 0}

	sign := true    // 符号，true为正
	var i, j int    // 起始指针和终点指针

	// 找到起始点
	for i=0; i<l; i++ {
		if str[i] >= '0' && str[i] <= '9' {break}
		if str[i] == '+' {
			i++
			break
		}
		if str[i] == '-' {
			i++
			sign = false
			break
		}
		if str[i] != ' ' {return 0}
		// 剩余可能就是空格，空格就右移
	}

	// 找终止点
	for j = i; j<l; j++ {
		if str[j]<'0' || str[j]>'9' {break}
	}
	// j 指向了数字序列之后第一个不是数字的位置

	// 处理数字序列前面的0,找到去0头的起始点
	var k int
	for k=i; k<j; k++ {
		if str[k] != '0' {break}
	}

	subStr := str[k:j]  // 整数序列

	// 转换成数字
	var ret, cur int
	for k=0; k<len(subStr); k++ {
		cur = int(subStr[k] - '0')
		if sign {
			if ret > maxInt32/10 || (ret == maxInt32/10 && cur > 7) {return maxInt32}
			ret = ret*10 + cur
		} else {
			if ret < minInt32/10 || (ret == minInt32/10 && cur > 8) {return minInt32}
			ret = ret*10 - cur
		}
	}

	return ret
}

// -------------------------------------------------------------------------------

// 最后，再来试试正则表达式解法。参考题解区Knife
// 这里就不纠结溢出啊之类的问题，使用go的标准库来做，熟练熟练
// 1079/1079 cases passed (4 ms)
//Your runtime beats 59.07 % of golang submissions
//Your memory usage beats 5.35 % of golang submissions (4.7 MB)
func myAtoi3(str string) int {

	// 首先去除字符串开头的所有空格，下面虽然功能不太一样，但都能达到本题剔除前面空格的要求
	// str = strings.TrimSpace(str)							// 前后都剔除空白字符
	// str = strings.TrimLeftFunc(str, unicode.IsSpace)		// 这里的空格指的是空格、制表符、换行符等等所有unicode中规定的空白字符
	// str = strings.TrimLeft(str, " ")						// 只剔除左边的所有空格

	// fmt.Println(str)

	// 制定正则表达式
	exp := `^[\+\-]?\d+`	// ^表示要匹配前缀， \+\-是+-的转义，[\+\-]表示这个位置的这个字符可以是+或-， ？表示前一个字符可有可无
							// \d 匹配0~9任意的一个数字， 后面跟 + 表示前一个字符起码出现一次。相当于 \d\d\d... 的意思，可以表示 任意长的数字序列（长度起码为1）
							// 总体，这句exp模式串就是在目标串匹配前缀是不是+/-/其他，紧跟着的是不是一串数字序列



	// 匹配出子串
	re := regexp.MustCompile(exp)
	subStr := re.Find([]byte(strings.TrimLeftFunc(str, unicode.IsSpace)))

	fmt.Println(string(subStr))

	if subStr == nil {		// 说明没匹配到
		return 0
	}

	// 调用strconv， 由于strconv.ParseInt最多也就是64位，而64位在测例下仍然可能溢出，这会使得strconv出错，因此当出错时，就知道是越界了
	ret, err := strconv.ParseInt(string(subStr), 10, 32)
	// strconv.ParseInt(string(subStr), 10, 0) 等价于strconv.Atoi()； bitSIze设为0是默认调用IntSize,而IntSize取决于操作系统32还是64
	if err != nil {
		if err.(*strconv.NumError).Err == strconv.ErrRange {	// 判断是越界，但是我们得自己判断是正还是负
			if subStr[0] == '-' {return math.MinInt32}
			return math.MaxInt32
		}
		log.Fatalln(err)
	}

	return int(ret)
}


```
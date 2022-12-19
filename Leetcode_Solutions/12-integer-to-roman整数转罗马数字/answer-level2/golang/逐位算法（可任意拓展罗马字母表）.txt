## 读题

我们仔细看一下罗马数字的翻译规则，有一个点很重要，那就是罗马数字依然是**10进制**的，即：

 - 10以内的数字可以完全表达
 - 个位、十位、百位……之间互不干涉

那要初步实现就非常容易了，我们**逐位翻译**即可。

## 初步实现

定义一个**罗马数字字母表**，先简单起见，用`[]string`：

```go
var RomanTable = [7]string{"I", "V", "X", "L", "C", "D", "M"}
```

然后从个位开始，逐个取出数字：

```go
func intToRoman(num int) string {
    for i := 0; i < 4; i++ {
        romanTable = RomanTable[i*2:]
        switch num % 10 {
        }
        num /= 10
    }
}
```

注意，这里定义了一个**对应于当前数位**的罗马字母子集`romanTable = RomanTable[i*2:]`。

然后填入每一位的翻译规则：

```go
switch num % 10 {
case 1:
    result[3-i] = fmt.Sprint(romanTable[0])
case 2:
    result[3-i] = fmt.Sprint(romanTable[0], romanTable[0])
case 3:
    // ...
}
```

最后输出结果：

```go
return strings.Join(result, "")
```

完整代码如下：

```go
var RomanTable = [7]string{"I", "V", "X", "L", "C", "D", "M"}

func intToRoman(num int) string {
	// 题目规定 1<= num <=3999
	var romanTable []string
	var result = make([]string, 4)
	for i := 0; i < 4; i++ {
		romanTable = RomanTable[i*2:]
		switch num % 10 {
		case 1:
			result[3-i] = fmt.Sprint(romanTable[0])
		case 2:
			result[3-i] = fmt.Sprint(romanTable[0], romanTable[0])
		case 3:
			result[3-i] = fmt.Sprint(romanTable[0], romanTable[0], romanTable[0])
		case 4:
			result[3-i] = fmt.Sprint(romanTable[0], romanTable[1])
		case 5:
			result[3-i] = fmt.Sprint(romanTable[1])
		case 6:
			result[3-i] = fmt.Sprint(romanTable[1], romanTable[0])
		case 7:
			result[3-i] = fmt.Sprint(romanTable[1], romanTable[0], romanTable[0])
		case 8:
			result[3-i] = fmt.Sprint(romanTable[1], romanTable[0], romanTable[0], romanTable[0])
		case 9:
			result[3-i] = fmt.Sprint(romanTable[0], romanTable[2])
		}
		num /= 10
	}
	return strings.Join(result, "")
}
```

看起来挺丑的，不过有个最大的优点是，可以任意拓展罗马字母表的长度，比如增加`Q W E R T Y ...`增加多少位都没有关系，不需要像其他答案中那样列举所有的字母组合。

## 性能分析与改进

本题算法复杂度已经是`O(1)`了，几乎没有优化的空间。

但是要关注的一个重点是，大量的字符串拼接操作，需要伴随着大量的内存申请，这是非常慢的。

所以我们使用`[]byte`来代替`string`。主要是用到`unsafe`包。

关键代码：

```go
var RomanTable = [7]byte{'I', 'V', 'X', 'L', 'C', 'D', 'M'}
func xxx(){
    // ...
    return (*(*string)(unsafe.Pointer(&(result))))
}
```

经过本地性能测试，`[]byte`改良后的版本，性能提升了10倍。

详情可访问我的个人网站。
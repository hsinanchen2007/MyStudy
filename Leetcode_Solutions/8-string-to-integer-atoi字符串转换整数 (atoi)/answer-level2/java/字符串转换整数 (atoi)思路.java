1.去除空格，str = str.trim()
2.第一个字符为正负号时，通过sign = 1|-1 记录符号，并且通过flag=true标记不再需要正负号
3.第一个字符为数字时，通过flag=true标记不再需要正负号，并将数字加到累计值中 result = result * 10 + (c - '0'),此处要注意char跟数字类型的加运算，累加之后要结合sign于 Integer.MAX_VALUE以及Integer.MIN_VALUE进行比较，超出范围则直接返回，此处rsult定义为long类型，避免超出int范围
4.flag=true之后任何非数字的字符都会导致转换结束
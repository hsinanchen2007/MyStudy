直接粘代码吧，这个不太难理解：

暴力算法
```golang []
func intToRoman(num int) string {
	var roman string

	if num<1 && num>3999{
		return "exit -1"
	}
	roman1 := []string{"","I","II","III","IV","V","VI","VII","VIII","IX"}
	roman2 := []string{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"}
	roman3 := []string{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"}
	roman4 := []string{"","M","MM","MMM"}
	roman = roman4[num/1000]+roman3[num%1000/100]+roman2[num%100/10]+roman1[num%10]

	return roman
}
```

贪心算法
```golang []
func intToRoman(num int) (roman string) {
	romanNum := []int{1000,900,500,400,100,90,50,40,10,9,5,4,1}
	romanStr := []string{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"}
	for i:=0;i<len(romanNum);i++ {
		for num>=romanNum[i]{
			roman += romanStr[i]
			num -= romanNum[i]
		}
	}

	return
}
```

有问题，欢迎讨论。
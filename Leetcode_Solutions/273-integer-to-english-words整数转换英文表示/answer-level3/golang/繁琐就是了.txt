```
import "strings"

var digitMap = map[int]string{
	1: "Thousand",
	2: "Million",
	3: "Billion",
}

var digitStr = map[int]string{
	0: "Zero",
	1: "One",
	2: "Two",
	3: "Three",
	4: "Four",
	5: "Five",
	6: "Six",
	7: "Seven",
	8: "Eight",
	9: "Nine",
}

var twentyStr = map[int]string{
	10: "Ten",
	11: "Eleven",
	12: "Twelve",
	13: "Thirteen",
	14: "Fourteen",
	15: "Fifteen",
	16: "Sixteen",
	17: "Seventeen",
	18: "Eighteen",
	19: "Nineteen",
}

var teenStr = map[int]string{
	2: "Twenty",
	3: "Thirty",
	4: "Forty",
	5: "Fifty",
	6: "Sixty",
	7: "Seventy",
	8: "Eighty",
	9: "Ninety",
}

func numberToWords(num int) (rtn string) {
	var (
		digit = 0
	)
	for num > 0 {
		if num%1000 != 0 {
			rtn = numberToWords3WithDigit(num%1000, digit) + " " + rtn
		}
		num /= 1000
		digit++
	}
	if rtn == "" {
		return digitStr[0]
	}
	return strings.TrimSpace(rtn)
}

func numberToWords3WithDigit(num int, digit int) string {
	if digit > 0 {
		return numberToWords3(num) + " " + digitMap[digit]
	} else {
		return numberToWords3(num)
	}
}

func numberToWords3(num int) string {
	if num < 10 {
		return digitStr[num]
	} else if num < 20 {
		return twentyStr[num]
	} else if num < 100 {
		if num%10 == 0 {
			return teenStr[num/10]
		} else {
			return teenStr[num/10] + " " + digitStr[num%10]
		}
	} else {
		if num%100 == 0 {
			return digitStr[num/100] + " " + "Hundred"
		} else {
			return digitStr[num/100] + " " + "Hundred " + numberToWords3(num%100)
		}
	}
}
```

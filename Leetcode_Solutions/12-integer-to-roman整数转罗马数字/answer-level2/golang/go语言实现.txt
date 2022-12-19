```
func intToRoman(num int) string {
	roman := ""
	if num/1000 != 0 {
		for i := 0; i < num/1000; i++ {
			roman += "M"
		}
		num = num % 1000
	}
	if num/500 != 0 {
		if num >= 900 {
			roman += "CM"
			num = num - 900
		} else {
			for i := 0; i < num/500; i++ {
				roman += "D"
			}
			num = num % 500
		}
	}
	if num/100 != 0 {
		if num >= 400 {
			roman += "CD"
			num = num - 400
		} else {
			for i := 0; i < num/100; i++ {
				roman += "C"
			}
			num = num % 100
		}
	}
	if num/50 != 0 {
		if num >= 90 {
			roman += "XC"
			num = num - 90
		} else {
			for i := 0; i < num/50; i++ {
				roman += "L"
			}
			num = num % 50
		}
	}
	if num/10 != 0 {
		if num >= 40 {
			roman += "XL"
			num = num - 40
		} else {
			for i := 0; i < num/10; i++ {
				roman += "X"
			}
			num = num % 10
		}
	}
	if num/5 != 0 {
		if num == 9 {
			roman += "IX"
			num = num - 9
		} else {
			for i := 0; i < num/5; i++ {
				roman += "V"
			}
			num = num % 5
		}
	}
	if num == 4 {
		roman += "IV"
		num = num - 4
	} else {
		for i := 0; i < num; i++ {
			roman += "I"
		}
	}
	return roman
}
```
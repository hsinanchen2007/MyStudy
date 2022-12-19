```go []
func romanToInt(s string) int {
     var lastS byte
	 var  res  int
     for i:=0;i<len(s);i++ {
		 switch s[i] {
		 case 'M':
		 	res += 1000
			 if lastS=='C'{
				 res -= 200
			 }
		 case 'D':
		 	res += 500
			 if lastS=='C'{
				 res -= 200
			 }
		 case 'C':
			 res += 100
			 if lastS=='X'{
				 res -= 20
			 }
		 case 'L':
			 res += 50
			 if lastS=='X'{
				 res -= 20
			 }
		 case 'X':
			 res += 10
			 if lastS=='I'{
				 res -= 2
			 }
		 case 'V':
			 res += 5
			 if lastS=='I'{
				 res -= 2
			 }
		 case 'I':
		 	 res += 1
		 default:
			 return 0
		 }
		 lastS = s[i]
	 }
     return res
}
```


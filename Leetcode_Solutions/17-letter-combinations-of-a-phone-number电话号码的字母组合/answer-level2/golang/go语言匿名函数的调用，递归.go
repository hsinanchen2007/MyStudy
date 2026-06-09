func letterCombinations(digits string) []string {
	 m1 :=map[string]string{"2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"}
	 var ret []string
	 if len(digits)==0{
	 	ret=nil
	 }else {
		 ret = make([]string, 1)
		 for i := 0; i < len(digits); i++ {
			 tmp := make([]string, 0)
			 func(s string) {
				 for i := 0; i < len(m1[s]); i++ {
					 for v, k := range ret {
						 fmt.Println(v, k, "v,k")
						 sprintf := fmt.Sprintf("%s%s", k, string(m1[s][i]))
						 tmp = append(tmp, sprintf)
					 }
				 }
			 }(string(digits[i]))
			 ret = tmp
		 }
	 }
	 return ret
}
Go的发布我看着比较少，加一个
func addBinary(a string, b string) string {
	indexa :=len(a)-1
	indexb :=len(b)-1
	result := ""
	carry :=0

	for indexa>=0 || indexb >= 0 {
			var Inta ,Intb int
				if indexa <0{
					Inta = 0
				}else{
					Inta ,_ =strconv.Atoi(string(a[indexa]))			
				}
			if indexb <0{
				Intb = 0
		
			}else{
				Intb ,_ =strconv.Atoi(string(b[indexb]))
			}
			sum :=Inta + Intb + carry
			carry = sum / 2
			result = strconv.Itoa(sum % 2)+result
			indexa --
			indexb --
		}
	if carry == 1 {
		result = "1"+result
	}
	return result
}
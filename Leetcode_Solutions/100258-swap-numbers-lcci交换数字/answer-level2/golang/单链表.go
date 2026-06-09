# 单链表

}```
func swapNumbers(numbers []int) []int {

	 for i:=0;i<32;i++{
	 	if numbers[0]&1 !=0{
	 		numbers[0] >>=1

            if numbers[1] &1 !=0{
            	numbers[1]>>=1
                 numbers[1] |= 1<<31
                 numbers[0] |= 1<<31
			}else{
				numbers[1]>>=1
				numbers[1] |= 1<<31
			}

		} else{
			numbers[0] >>=1
			if numbers[1] &1 !=0{
				numbers[1]>>=1
				numbers[0] |= 1<<31
			}else{
				numbers[1]>>=1

			}

		}
	 }
return numbers
}
```

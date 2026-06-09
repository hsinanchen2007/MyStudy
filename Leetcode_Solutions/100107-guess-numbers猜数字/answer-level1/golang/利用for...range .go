func game(guess []int, answer []int) int {
        count:=0
    	for i, v := range guess {
		if v == answer[i] {
			count = count + 1
		}
	}
    return count
}
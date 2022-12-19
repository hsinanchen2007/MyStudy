func game(guess []int, answer []int) int {
    count := 0
    for index,_ := range guess {
        if guess[index] == answer[index]{
            count += 1
        } 
    }
    return count
}
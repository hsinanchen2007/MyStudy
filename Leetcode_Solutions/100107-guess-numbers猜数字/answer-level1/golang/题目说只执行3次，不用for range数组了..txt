func game(guess []int, answer []int) int {
    var count, i = 3, 0

    for i < 3 {
        if guess[i] != answer[i] {
            count--
        }
        i++
    }

    return count
}
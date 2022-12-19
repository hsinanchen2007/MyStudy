func numJewelsInStones(_ J: String, _ S: String) -> Int {
    var num = 0
    for stone in S {
        if J.contains(stone) {
            num += 1
        }
    }
    return num
}
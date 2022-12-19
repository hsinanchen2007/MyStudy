   ```
    func repeatedNTimes(_ A: [Int]) -> Int {
    var set = Set<Int>()
    for num in A.enumerated() {
        if set.contains(num.element) {
            return num.element
        }
        set.insert(num.element)
    }
    return 0
}
    ```
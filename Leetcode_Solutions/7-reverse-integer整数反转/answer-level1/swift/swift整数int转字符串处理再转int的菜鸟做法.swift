```
func reverse(_ x: Int) -> Int {
    let string = "\(x)"
    var array = Array<String>()
    var minus = false
    for value in string {
        if value == "-" {
            minus = true
            continue
        }
        array.append(String(value))
    }
    var temp = minus ? "-" : ""
    for value in array.enumerated().reversed() {
        temp.append(value.element)
    }
    return Int(Int32(temp) ?? 0)
}
```
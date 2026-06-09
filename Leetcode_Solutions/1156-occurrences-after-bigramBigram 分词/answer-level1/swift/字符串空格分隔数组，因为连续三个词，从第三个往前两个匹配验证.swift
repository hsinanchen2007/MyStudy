之前想法不对，导致错误好几次，后来想想，既然是连续的三个词，那直接从第三个开始验证，验证前两个是否匹配，匹配第三个就满足了。
```
func findOcurrences(_ text: String, _ first: String, _ second: String) -> [String] {
    let texts = text.components(separatedBy: " ")
    var result = Array<String>()
    for (index, one) in texts.enumerated() {
        if index < 2 {
            continue
        }
        if texts[index - 2] == first && texts[index - 1] == second {
            result.append(one)
        }
    }
    return result
}
```
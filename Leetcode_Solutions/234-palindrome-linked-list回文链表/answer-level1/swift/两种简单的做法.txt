```转换为字符串 []
func isPalindrome(_ head: ListNode?) -> Bool {
        var head_ = head
        var ltr: String?, rtl: String?
        while head_ != nil {
            if ltr == nil {
                ltr = ""
                rtl = ""
            }
            let str = String(head_!.val)
            ltr?.append(str)
            rtl!.insert(contentsOf: str, at: rtl!.startIndex)
            head_ = head_?.next
        }
        return ltr == rtl

}
```
```转换为数组 []
func isPalindrome(_ head: ListNode?) -> Bool {
        var head_ = head
        var numbers = [Int]()
        while head_ != nil {
            numbers.append(head_!.val)        //can't assgin an option type to a element type
            head_ = head_?.next
        }

        var left = 0
        var right = numbers.count - 1
        while left < right {
            if numbers[left] != numbers[right] {
                return false
            }
            left += 1
            right -= 1
        }
        return true
}
```
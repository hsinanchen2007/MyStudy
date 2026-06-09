### 解题思路

很容易想到暴力乘积来取最后k 项乘积的问题
但是有个问题就是，查询次数要是特别多的话，会造成超时
缓存之前的乘积结果会是一个不错的方法

当然，还有更好的实现，然而我不会，o(╥﹏╥)o

### 代码

```swift
class ProductOfNumbers: NSObject {
    var values = [1]
    override init() {
    }
    
    func add(_ num: Int) {
        if num == 0 {
            values = [1]
        } else {
            values.append(num * values.last!)
        }
    }
    
    func getProduct(_ k: Int) -> Int {
        if values.count <= k {
            return 0
        }
        return values.last! / values[values.count - k - 1]
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * let obj = ProductOfNumbers()
 * obj.add(num)
 * let ret_2: Int = obj.getProduct(k)
 */
```
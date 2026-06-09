虽然不让用bigInt类型，但是真心想说，Scala设计的真优雅，一行代码。
```
def multiply(num1: String, num2: String): String = {
        (BigInt(num1) * BigInt(num2)).toString()
}
```

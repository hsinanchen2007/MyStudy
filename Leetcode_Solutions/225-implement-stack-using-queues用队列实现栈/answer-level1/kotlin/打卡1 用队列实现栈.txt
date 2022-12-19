```
class MyStack() {

    private var a = mutableListOf<Int>()
    private var b = mutableListOf<Int>()

    //a操作完始终为空，数据以倒序的形式存放到b中
    fun push(x: Int) {
        a.add(x)
        while(!b.isEmpty()) {
            a.add(b.removeAt(0))
        }
        (a to b).run { a = second; b = first }
    }

    fun pop(): Int = b.removeAt(0)

    fun top(): Int = b[0]

    fun empty(): Boolean = b.isEmpty()

}
```

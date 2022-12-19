List模拟没啥可说的
```
 class MyStack() {
    var lst : List[Int] = Nil

    def push(x: Int) {
      lst = x +: lst
    }
    def pop(): Int = {
      val ret = lst.head
      lst = lst.drop(1)
      ret
    }
    
    def top(): Int = {
      lst.head
    }
    def empty(): Boolean = {
      lst == Nil
    }
  }
```

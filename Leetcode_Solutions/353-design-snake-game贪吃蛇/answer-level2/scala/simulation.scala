```scala []
class SnakeGame(_width: Int, _height: Int, _food: Array[Array[Int]]) {
    case class Pos(x:Int, y:Int){
        def +(that:Pos):Pos = Pos(x+that.x, y + that.y)
    }
    def inBound(p:Pos):Boolean = p.x >= 0 && p.y >= 0 && p.y < _width && p.x < _height
    var snake = List(Pos(0,0))
    var food = _food.toList.map{case Array(x,y) => Pos(x,y)}
    val dir = List('U', 'L', 'R', 'D')
    val delta = List(Pos(-1, 0), Pos(0, -1), Pos(0, 1), Pos(1, 0))    
    def valid(snake:List[Pos]):Boolean = snake.distinct.length == snake.length
    def move(d: String): Int = {
        val shift = delta(dir.indexOf(d.head))
        if(food.nonEmpty && food.head == snake.head + shift){
            snake ::= food.head 
            food = food.tail
            if(valid(snake)) snake.length -1 else -1
        }
        else if(!inBound(snake.head + shift)) -1 
        else {
            snake =(snake.head+shift)::(snake.dropRight(1)) //map {x => x + shift}
            if(valid(snake)) snake.length -1 else -1
        }
    }

}
```
```

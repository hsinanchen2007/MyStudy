```ruby
object Solution {
    case class State(path:List[Int])
    def leadsToDestination(n: Int, edges: Array[Array[Int]], source: Int, destination: Int): Boolean = {
        val table = scala.collection.mutable.HashMap[Int, List[Int]]()
        edges foreach {case Array(start, end) => 
            table.put(start, end::table.getOrElse(start, Nil))}
        def f(state:State):List[State] = {
            table
            .getOrElse(state.path.head, Nil)
            .map(next => State(next::state.path))
        }
        def isCycle(state:State):Boolean = {
            state.path.distinct.length != state.path.length
        }
        def reached(state:State):Boolean = state.path.head == destination
        def solve(l:List[State]):Boolean = l match {
            case Nil => true
            case _ => 
            val ll = l map f
            if(ll exists (_==Nil)) false
            else if(ll exists (x => x exists isCycle)) false
            else solve(ll.flatten.filterNot(x => reached(x)))
        }
        if(source == destination) table.getOrElse(source, Nil).isEmpty else
        table.getOrElse(destination, Nil).isEmpty &&solve(List(State(source::Nil)))
    }
}
```

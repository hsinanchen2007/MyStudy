1. 用并查集将值为1的合到一起
2. 对每个1的集合做对齐,排序减掉第一个元素,因为只考虑平移
3. 判断最后有几个不同的元素就可以了
```ruby
object Solution {
    class DSU(N:Int){
        val parent = (0 until N).toArray
        def find(x:Int):Int = if(x != parent(x)) find(parent(x)) else x
        def union(x:Int, y:Int):Unit = {parent(find(x)) = parent(find(y))}
    }
    def numDistinctIslands(grid: Array[Array[Int]]): Int = {
        if(grid.length == 0 || grid(0).length == 0) return 0
        val dsu = new DSU(grid.length * grid(0).length)
        val seq = (
            for{
                i <- grid.indices
                j <- grid(i).indices
                if grid(i)(j) == 1
            } yield (i,j)
        )
        def nei(i:Int, j:Int):List[(Int,Int)] = List((i+1,j),(i-1,j),(i,j+1), (i,j-1))
        def inBound(p:(Int,Int)):Boolean = p match {
            case (x,y) => x >= 0 && y >= 0 && x < grid.length && y < grid(0).length
        }
        def idx(i:Int, j:Int):Int = i * grid(0).length + j
        seq foreach { 
            case (i,j) => nei(i,j).filter{x => inBound (x)} foreach { 
                case (x,y) => if(grid(x)(y) == 1) dsu.union(idx(i,j), idx(x,y))
                }
            }
        seq
        .filter {case(i,j) => grid(i)(j) == 1} 
        .groupBy { case (i,j) => dsu.find(idx(i,j))}
        .values.toList
        .map{
            l => 
            val sl = l.sorted; 
            sl map {
                case (i,j) => (i-sl.head._1, j - sl.head._2)
            } 
        }.distinct.length
        
    }
    // 1 1 0 1 1
    // 1 0 0 0 0
    // 0 0 0 0 1
    // 1 1 0 1 1
    
    
}
```

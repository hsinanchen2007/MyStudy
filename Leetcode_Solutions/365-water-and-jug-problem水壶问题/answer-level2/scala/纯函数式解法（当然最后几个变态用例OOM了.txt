
### 解法

通过惰性计算进行DFS，祖师爷给的代码改改还是能用的。目前`Stream`已经不再推荐使用，可以使用`LazyList`代替。

### 代码

```scala
object Solution {
  def canMeasureWater(x: Int, y: Int, z: Int): Boolean = {
    val game = new Pouring(Vector(x, y)) // x和y分别代表给定的两个容器的大小
    game.solutions(z).take(1).nonEmpty // solution中包含了可能的解，由于题目只要求输出能否达到这个状态，因此只需要取一个解就可以
  }

  class Pouring(capacity: Vector[Int]) {
    // States
    type State = Vector[Int]
    val initialState: Vector[Int] = capacity map (x => 0) // 初始化状态，每个水桶的水含量为0

    // Moves
    // 这几个类定义了可能的操作
    trait Move {
      def change(state: State): State
    }
    
    // 将某个容器的水清空，glass就是我们想要清空容器的编号
    case class Empty(glass: Int) extends Move {
      def change(state: State): State = state updated(glass, 0)
    }

    // 同理，填满整个容器
    case class Fill(glass: Int) extends Move {
      def change(state: State): State = state updated(glass, capacity(glass))
    }
    
    // 将一个容器的水倾倒至另外一个容器中
    case class Pour(from: Int, to: Int) extends Move {
      def change(state: State): State = {
        // 这里计算可以倾倒的水的数量，`倾`容器剩余的水量和`倒`容器可以容纳水量的最小值
        val amount = state(from) min (capacity(to) - state(to))
        // 进行倾倒
        state updated(from, state(from) - amount) updated(to, state(to) + amount)
      }
    }

    // 获取每个水桶的编号，用以对每个水桶产生相应的状态
    val glasses: Range = capacity.indices

    // 这里产生下一步的状态，对每个水桶，我们都可以填满、倒掉或是倾倒至另外一个水桶
    val moves: Seq[Move] =
      (for (g <- glasses) yield Empty(g)) ++
        (for (g <- glasses) yield Fill(g)) ++
        // 这个地方要排除from = to 的情况，自己给自己倒只会陷入死循环
        (for (from <- glasses; to <- glasses if from != to) yield Pour(from, to))

    class Path(history: List[Move], val endState: State) {
      // Path记录了操作步骤和最终状态 
      def extend(move: Move): Path = new Path(move :: history, move change endState)

      override def toString: String = (history.reverse mkString " ") + "-->" + endState
    }

    // 最开始的时候，我们没有进行任何操作，初始状态都是 initialState
    val initialPath = new Path(Nil, initialState) 

    // 最核心的函数，用以产生惰性的计算流。explored表示的是曾经有过的状态。如果该解法中，这个状态曾经出现过，那么再次出现就是没必要的。
    def from(paths: Set[Path], explored: Set[State]): Stream[Set[Path]] =
      if (paths.isEmpty) Stream.empty
      else {
        val more = for {
          path <- paths
          // 将可能的操作添加到整个path中  
          next <- moves map path.extend
          if !(explored contains next.endState)
        } yield next
        paths #:: from(more, explored ++ (more map (_.endState))) // 根据当前状态产生下一个状态，这个函数是无限递归的，但由于返回的类型是Stream，所以会按需计算
      }

    val pathSets = from(Set(initialPath), Set(initialState)) // 利用from函数构建的无限流

    def solutions(target: Int): Stream[Path] =
      for {
        pathSet <- pathSets
        path <- pathSet
        if ((path.endState contains target) || path.endState.sum == target) // 注意这个条件，如果最终状态包含target，或者最终的两个罐子的水加起来等于target，我们就结束整个计算流
      } yield path
  }
}

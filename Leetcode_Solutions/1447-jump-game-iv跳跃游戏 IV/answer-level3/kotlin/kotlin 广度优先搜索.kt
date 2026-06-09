### 解题思路
Queue:   广度优先搜索 使用Queue队列进行遍历
HashMap: 在准备阶段遍历数组，将同值元素储存到HashMap中,方便跳跃时寻址
memo:    记录最小步数

### 代码

```kotlin
import java.util.concurrent.LinkedBlockingQueue
class Solution {
    fun minJumps(arr: IntArray): Int {
        //优化数组，去除相邻同值元素 
        //7,7,7,7,7,7,12 类似数组 优化为 7,7,12
        val arr = arr.filterIndexed { index, num ->
            !(index != 0 && index != arr.lastIndex && num == arr[index - 1] && num == arr[index + 1])
        }
        val memo = IntArray(arr.size){-1}
        val queue = LinkedBlockingQueue<Frog>()
        val map = HashMap<Int,MutableList<Int>>()
        for(i in arr.indices){
            if(map.containsKey(arr[i])) map[arr[i]]!!.add(i)
            else map[arr[i]] = mutableListOf(i)
        }

        queue.put(Frog(0,0))
        while(queue.isNotEmpty()){
            val frog = queue.poll()
            val node = frog.index
            if(memo[node] != -1 && frog.time >= memo[node]){
                continue
            }
            memo[node] = frog.time
            for(num in map[arr[node]]!!){
                if(num != node){
                    queue.put(Frog(num,frog.time+1))
                }
            }
            if(node + 1 < arr.size){
                queue.put(Frog(node +1,frog.time+1))
            }
            if(node - 1 >= 0 ){
                queue.put(Frog(node -1,frog.time+1))
            }
        }
        return memo[arr.lastIndex]
    }

    class Frog(val index:Int,val time:Int)
}
```
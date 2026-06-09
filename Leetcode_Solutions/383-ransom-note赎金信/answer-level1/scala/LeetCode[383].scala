```
object Solution {
    def canConstruct(ransomNote: String, magazine: String): Boolean = {
      val mymap= scala.collection.mutable.Map[Char,Int]()
      for (item <- ransomNote) {
        if(mymap.contains(item)){
          mymap(item) += 1
        }else{
          mymap(item) = 1
        }
      }

      for (item <- magazine) {
        if(mymap.contains(item)){
          mymap(item) -= 1
        }
      }

      mymap.forall( x => x._2 <= 0 )
    }
}

```

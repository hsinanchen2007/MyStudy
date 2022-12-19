```scala []
import scala.collection.mutable

object Solution {
  def distributeCandies(candies: Array[Int]): Int = {
    val s = new mutable.HashSet[Int]()
    candies.foreach(i => s.add(i))
    s.size.min(candies.length / 2)
  }
}
```
```cpp []
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        return min(unordered_set<int>(candies.begin(), candies.end()).size(), candies.size() / 2);
    }
};
```


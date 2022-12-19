```
object Solution {
  def findRelativeRanks(nums: Array[Int]): Array[String] = {
    val sortNums = nums.sorted.reverse
    nums.map(x => {
      sortNums.indexOf(x) + 1 match {
        case 1 => "Gold Medal"
        case 2 => "Silver Medal"
        case 3 => "Bronze Medal"
        case x => x.toString
      }
    })
  }
}

```

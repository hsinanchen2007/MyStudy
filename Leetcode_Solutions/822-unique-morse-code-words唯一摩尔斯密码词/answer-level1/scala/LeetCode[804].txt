```
object Solution {
  val mymap = Map[Char, String](
    97.toChar -> ".-"
    , 98.toChar -> "-..."
    , 99.toChar -> "-.-."
    , 100.toChar -> "-.."
    , 101.toChar -> "."
    , 102.toChar -> "..-."
    , 103.toChar -> "--."
    , 104.toChar -> "...."
    , 105.toChar -> ".."
    , 106.toChar -> ".---"
    , 107.toChar -> "-.-"
    , 108.toChar -> ".-.."
    , 109.toChar -> "--"
    , 110.toChar -> "-."
    , 111.toChar -> "---"
    , 112.toChar -> ".--."
    , 113.toChar -> "--.-"
    , 114.toChar -> ".-."
    , 115.toChar -> "..."
    , 116.toChar -> "-"
    , 117.toChar -> "..-"
    , 118.toChar -> "...-"
    , 119.toChar -> ".--"
    , 120.toChar -> "-..-"
    , 121.toChar -> "-.--"
    , 122.toChar -> "--.."
  )
  def uniqueMorseRepresentations(words: Array[String]): Int = {
    words.map(word => {
      word.map(char => mymap.get(char).get).mkString
    }).distinct.length
  }
}
```

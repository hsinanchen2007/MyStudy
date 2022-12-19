```
func flipAndInvertImage(_ A: [[Int]]) -> [[Int]] {
        return A.map{$0.reversed().map{ return $0^1 }}
    }
```
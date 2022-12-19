[MS SQL SERVER]

个人理解：如果该题的出题环境是 `MS SQL SERVER` ，那么可能是在考察对 `ROW_NUMBER` 的运用，毕竟难度为中等。

解题思路：1. 对数据通过 `Score` 进行分组，并给分组后的每一行通过 `ROW_NUMBER` 赋予行号。2. 再将分组数据和原表进行内联查询。

其它疑问：在有一定数据量的情况下或者出题考察的目的是其它，这样解决是一种错误方案（个人觉得刷题不是为了解决问题而解决问题，而要去揣测出题者的考点）

```
SELECT S.Score,T.Rank FROM Scores S
INNER JOIN (SELECT Score,ROW_NUMBER() OVER(ORDER BY Score DESC) Rank FROM Scores GROUP BY Score) T 
ON S.Score = T.Score ORDER BY S.Score DESC
```



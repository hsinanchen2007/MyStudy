### 解题思路
以"上边缘"与"左边缘"为起点,依次斜向下比较,看看是否存在不同的数字

### 代码

```csharp []
public class Solution {
        public bool IsToeplitzMatrix(int[][] matrix)
        {
            for (var c = 0; c < matrix[0].Length; c++)
                if (!IsSame(matrix, 0, c))
                    return false;

            for (var r = 0; r < matrix.Length; r++)
                if (!IsSame(matrix, r, 0))
                    return false;

            return true;
        }

        private bool IsSame(int[][] matrix, int r, int c)
        {
            var rows = matrix.Length;
            var cols = matrix[0].Length;

            var curValue = matrix[r][c];
            while (r < rows && c < cols)
                if (matrix[r++][c++] != curValue)
                    return false;

            return true;
        }
}
```

### 解题思路
使用链表,每次比较前,删除最右数字,比较后,在开头增加新的数字

### 代码

```csharp []
public class Solution {
        public bool IsToeplitzMatrix(int[][] matrix)
        {
            var link = new LinkedList<int>();
            for (var c = 0; c < matrix[0].Length; c++)
                link.AddLast(matrix[0][c]);

            for (var r = 1; r < matrix.Length; r++)
            {
                link.RemoveLast();

                var f = link.First;
                for (var c = 1; c < matrix[r].Length; c++)
                {
                    if (f.Value != matrix[r][c])
                        return false;

                    f = f.Next;
                }

                link.AddFirst(matrix[r][0]);
            }

            return true;
        }
}
```

### 解题思路
斜向看,行和列都是加 1 的,因此它俩的差值永远是固定的,以此为依据建立字典

### 代码

```csharp []
public class Solution {
        public bool IsToeplitzMatrix(int[][] matrix)
        {
            var dic = new Dictionary<int, int>();
            for (var r = 0; r < matrix.Length; r++)
            {
                for (var c = 0; c < matrix[r].Length; c++)
                {
                    if (!dic.ContainsKey(r - c))
                        dic[r - c] = matrix[r][c];
                    else if (dic[r - c] != matrix[r][c])
                        return false;
                }
            }

            return true;
        }
}
```

### 解题思路
每个元素都与左上角的数字比较

### 代码

```csharp []
public class Solution {
        public bool IsToeplitzMatrix(int[][] matrix)
        {
            for (var r = 0; r < matrix.Length; r++)
                for (var c = 0; c < matrix[r].Length; c++)
                    if (r != 0 && c != 0 && matrix[r][c] != matrix[r - 1][c - 1])
                        return false;

            return true;
        }
}
```
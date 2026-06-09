#### 方法一：贪心

**分析**

我们随便选其中的一个多米诺骨牌，它的标号为 `i`，上半部分的数字为 `A[i]`，下半部分的数字为 `B[i]`。

![bla](https://pic.leetcode-cn.com/Figures/1007/config.png){:width=500}
{:align=center}    

此时可能会有三种情况：

1. 以数字 `A[i]` 作为基准，将 `A` 或 `B` 中的所有值都变为 `A[i]`。例如，下图中，我们选择了第 $0$ 个多米诺骨牌，这样可以将 `A` 中的所有值都变为 $2$。

![bla](https://pic.leetcode-cn.com/Figures/1007/s1.png){:width=500}
{:align=center}    

2. 以数字 `B[i]` 作为基准，将 `A` 或 `B` 中的所有值都变为 `B[i]`。例如，下图中，我们选择了第 $1$ 个多米诺骨牌，这样可以将 `B` 中的所有值都变为 $2$。

![bla](https://pic.leetcode-cn.com/Figures/1007/s2.png){:width=500}
{:align=center}    

3. 无论选择 `A[i]` 还是 `B[i]` 都没有办法将 `A` 或 `B` 中的所有值变为都相同。例如，下图中，我们选择了最后一个多米诺骨牌，无论是它的上半部分 $5$ 还是下半部分 $4$，都无法满足条件。

![bla](https://pic.leetcode-cn.com/Figures/1007/s3.png){:width=500}
{:align=center}    

如果要满足第 $1$ 种或是第 $2$ 种情况，就必须存在一块多米诺骨牌，它的上半部分或者下半部分的数字 `x` 在所有其它的多米诺骨牌中都出现过。若该条件满足，则说明所有多米诺骨牌中都出现了数字 `x`。因此，我们只要选择任意一块多米诺骨牌，判断它的上半部分或下半部分的数字是否可以作为 `x` 即可。

**算法**

- 选择第一块多米诺骨牌，它包含两个数字 `A[0]` 和 `B[0]`；
- 检查其余的多米诺骨牌中是否出现过 `A[0]`。如果都出现过，则求出最少的翻转次数，其为将 `A[0]` 全部翻到 `A` 和全部翻到 `B` 中的较少的次数。
- 检查其余的多米诺骨牌中是否出现过 `B[0]`。如果都出现过，则求出最少的翻转次数，其为将 `B[0]` 全部翻到 `A` 和全部翻到 `B` 中的较少的次数。

- 如果上述两次检查都失败，则返回 `-1`。

```Python [sol1]
class Solution:        
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        def check(x):
            """
            Return min number of swaps 
            if one could make all elements in A or B equal to x.
            Else return -1.
            """
            # how many rotations should be done
            # to have all elements in A equal to x
            # and to have all elements in B equal to x
            rotations_a = rotations_b = 0
            for i in range(n):
                # rotations coudn't be done
                if A[i] != x and B[i] != x:
                    return -1
                # A[i] != x and B[i] == x
                elif A[i] != x:
                    rotations_a += 1
                # A[i] == x and B[i] != x    
                elif B[i] != x:
                    rotations_b += 1
            # min number of rotations to have all
            # elements equal to x in A or B
            return min(rotations_a, rotations_b)
    
        n = len(A)
        rotations = check(A[0]) 
        # If one could make all elements in A or B equal to A[0]
        if rotations != -1 or A[0] == B[0]:
            return rotations 
        # If one could make all elements in A or B equal to B[0]
        else:
            return check(B[0])
```

```Java [sol1]
class Solution {
    /*
    Return min number of rotations 
    if one could make all elements in A or B equal to x.
    Else return -1.
    */
    public int check(int x, int[] A, int[] B, int n) {
        // how many rotations should be done
        // to have all elements in A equal to x
        // and to have all elements in B equal to x
        int rotations_a = 0, rotations_b = 0;
        for (int i = 0; i < n; i++) {
            // rotations coudn't be done
            if (A[i] != x && B[i] != x) return -1;
            // A[i] != x and B[i] == x
            else if (A[i] != x) rotations_a++;
            // A[i] == x and B[i] != x    
            else if (B[i] != x) rotations_b++;
        }
        // min number of rotations to have all
        // elements equal to x in A or B
        return Math.min(rotations_a, rotations_b);
    }

    public int minDominoRotations(int[] A, int[] B) {
        int n = A.length;
        int rotations = check(A[0], B, A, n);
        // If one could make all elements in A or B equal to A[0]
        if (rotations != -1 || A[0] == B[0]) return rotations;
        // If one could make all elements in A or B equal to B[0]
        else return check(B[0], B, A, n);
    }
}
```

```C++ [sol1]
class Solution {
    public:
    /*
    Return min number of rotations 
    if one could make all elements in A or B equal to x.
    Else return -1.
    */
    int check(int x, vector<int>& A, vector<int>& B, int n) {
        // how many rotations should be done
        // to have all elements in A equal to x
        // and to have all elements in B equal to x
        int rotations_a = 0, rotations_b = 0;
        for (int i = 0; i < n; i++) {
            // rotations coudn't be done
            if (A[i] != x && B[i] != x) return -1;
            // A[i] != x and B[i] == x
            else if (A[i] != x) rotations_a++;
            // A[i] == x and B[i] != x    
            else if (B[i] != x) rotations_b++;
        }
        // min number of rotations to have all
        // elements equal to x in A or B
        return min(rotations_a, rotations_b);
    }

    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int rotations = check(A[0], B, A, n);
        // If one could make all elements in A or B equal to A[0]
        if (rotations != -1 || A[0] == B[0]) return rotations;
        // If one could make all elements in A or B equal to B[0]
        else return check(B[0], B, A, n);
    }
};
```

**复杂度分析**

* 时间复杂度：$O(N)$。我们只会遍历所有的数组最多两次。

* 空间复杂度：$O(1)$。
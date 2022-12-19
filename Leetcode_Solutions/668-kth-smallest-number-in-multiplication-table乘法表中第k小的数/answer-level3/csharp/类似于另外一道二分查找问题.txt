### 解题思路
最大数和最小数，平均数
遍历M N 中较小者 构成的单调数列，寻找小于 Mid的数字数量
调整 Start End 的值


### 代码

```csharp
class FindKInMul {
    private int FindSmallNum (int iRow, int midV, int nCol) {
        //1*i 2*i 3*i ... n*i
        var start = 1;
        var end = nCol;
        while (start <= end) {
            var mid = (start + end) / 2;
            var val = mid * iRow;
            if (val < midV) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        //3->?
        //1 2 2 2 3
        //相等的数量 1 S > midV
        // 0E 1E 1SE 2SE
        //start > MidV
        //end <= MidV
        //S >= MidV 第一个MidV元素
        //end < MidV 最后一个小于 end=0
        return end;
    }
    private int FindIncludeMeNum (int iRow, int midV, int nCol) {
        var start = 1;
        var end = nCol;
        while (start <= end) {
            var mid = (start + end) / 2;
            var val = mid * iRow;
            if (val <= midV) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        //S> E <=
        //1 1 2 2 2E 3S 3
        return end;
    }
    public int FindKthNumber (int m, int n, int k) {
        // 2 3 6
        //1 2 3
        //2 4 6
        var totalNum = m * n;

        var first = 1;
        var last = m * n;
        FindMidV:
            var midV = (first + last) / 2;
        //单调增1*i 2*i ... n*i
        var smallNum = 0;
        var includeMe = 0;
        for (var i = 1; i <= m; i++) {
            smallNum += FindSmallNum (i, midV, n);
            includeMe += FindIncludeMeNum (i, midV, n);
        }
        // Console.WriteLine ("midV:" + midV + ":" + smallNum+":"+includeMe);
        // if (smallNum == (k - 1)) {
        //     return midV;
        // }
        if (smallNum < k && includeMe >= k) return midV;
        //K= 4? 1
        //0 0 1 1 1 2 2 2
        //小于<midV 值的数字数量 
        if (includeMe < k) {
            first = midV + 1;
        } else {
            last = midV - 1;
        }
        // Console.WriteLine ("first:" + first + ":" + last);
        if (first == last) return first;
        if (first < last) {
            goto FindMidV;
        }
        return 0;
    }
    // static void Main (string[] arg) {
    //     var fk = new FindKInMul ();
    //     var r = fk.FindKthNumber (2, 3, 6);
    //     Console.WriteLine (r);
    // }
}
public class Solution {
    public int FindKthNumber(int m, int n, int k) {
        var fk = new FindKInMul ();
        return fk.FindKthNumber(m, n, k);
    }
}
```
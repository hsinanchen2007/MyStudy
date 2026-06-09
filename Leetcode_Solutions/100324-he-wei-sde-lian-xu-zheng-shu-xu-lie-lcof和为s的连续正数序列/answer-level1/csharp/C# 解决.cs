### 解题思路
    解题思路：用到了高中知识。
    连续的【正整数】，为等差数列，假设首项为a，需要项数为b，那么最后一项为a+b-1，根据等差数列之和的公式
    N = (a + a+b-1)*b / 2;
    2N = (2a+b-1)*b;由于2a+b-1 > b,所以项数b一定小于√2N,那么b可以从1开始，遍历到√2N;
    要满足条件，需要满足 2N % b == 0,这样 2a+b-1才有解，并且要使a有解，得((2N/b)-b+1) %2 ==0，a才有整数解

### 代码

```csharp
public class Solution {
    public int[][] FindContinuousSequence(int target) {
        List<List<int>> result = new List<List<int>>();
        int nums = 0;
        int DoubleN = 2 * target;
        for(int i=(int)Math.Sqrt(DoubleN);i>=2 ;i--) {
            if(DoubleN%i==0 && (DoubleN/i+1-i)%2 ==0){
                List<int> temp = new List<int>();
                int a = (DoubleN/i+1-i)/2;
                for(int j=a;j<=a+i-1;j++)
                    temp.Add(j);
                result.Add(temp);
            }
        }
        int [][] r = new int[result.Count][];
        for(int i=0;i<result.Count;i++) {
            r[i] = new int[result[i].Count];
            for(int j=0;j<result[i].Count;j++) {
                r[i][j] = result[i][j];
            }
        }

        return r; 
    }
}
```
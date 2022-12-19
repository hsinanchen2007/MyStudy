### 解题思路
用left和right分别表示当前序列的最小值和最大值。如果从left到right的序列的和大于n的话，我们向右移动left，相当于从序列中去掉较小的数字。如果从left到right的序列的和小于n的话，我们向右移动right，相当于向序列中添加right的下一个数字。
期间要相应地对sum进行增减。
### 代码

```csharp
public class Solution {
    public int[][] FindContinuousSequence(int target) {
        List<int[]> res = new List<int[]>();
        int left=1, right=2;
        int half = target/2;
        int sum = (left+right)*(right-left+1)/2;
        while(left<=half){
            if(sum==target){
                res.Add(GetArr(left, right));
            }

            while(sum > target && left <= half){
                sum -= left;
                left++;
                if(sum==target){
                    res.Add(GetArr(left, right));
                }
            }

            right++;
            sum+=right;
        }
        return res.ToArray();
    }

    private int[] GetArr(int left, int right){
        int[] arr = new int[right-left+1];
        for(int i=0; i<arr.Length; i++){
            arr[i]=left+i;
        }
        return arr;
    }
}
```
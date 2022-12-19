### 解题思路
双指针，从头尾向中间靠拢比较，因为是非降序排列，所以最大的平方数必在两端
ps:新人，谢谢大家多提意见
### 代码

```csharp
public class Solution {
    public int[] SortedSquares(int[] A) {
        if(A.Length==0) return null;//如果数组为空返回null
        int length = A.Length;
        int[] B = new int[length];//用于返回的数组，与A等长
        int i=0;//头指针
        int j=length-1;//尾指针
        int index = j;//B数组的索引
        int pl=A[i]*A[i];//左边数的平方
        int pr=A[j]*A[j];//右边数的平方
        while(i<=j)
        {
            if(pl>pr)//左边平方大于右边平方，不用A[i]*A[i]和A[j]*A[j]比较，减少n次计算
            {
                B[index--]=pl;//往B数组尾巴填入左边（较大）数
                i++;//头指针后移
                pl=A[i]*A[i];
            }else//左边平方不大于右边平方（数组只有一个数或者互为相反数）
            {
                B[index--]=pr;//往B数组尾巴填入右边（较大）数
                j--;//尾指针前移
                if(j>=0) pr=A[j]*A[j];
            }
        }
        return B;
    }
}
```
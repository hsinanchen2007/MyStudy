# 思路
思路很简单，额外申请一个与`A`等长数组`temp`，在`A`数组上进行双指针操作。在`temp`上从后往前操作，保证数组是递增的。每次比较`A[i]`和`A[j]`的平方，取最大放进`temp`里。
# 代码
```
public class Solution {
    public int[] SortedSquares(int[] A) {
        if(A.Length==0)return null;
        int[] temp=new int[A.Length];
        int i=0;
        int j=A.Length-1;
        int x=temp.Length-1;

        while(i<=j){
            if(A[j]*A[j]>=A[i]*A[i]){
                temp[x]=A[j]*A[j];
                j--;
            }
            else{
                temp[x]=A[i]*A[i];
                i++;
            }
            x--;
        }
        return temp;
    }
}
```

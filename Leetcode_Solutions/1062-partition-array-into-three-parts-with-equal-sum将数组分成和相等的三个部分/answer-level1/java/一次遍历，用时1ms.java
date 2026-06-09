### 解题思路
利用一个规律，当一个数组能被划分为元素和相等的三个子数组时，**这三个子数组的元素之和均为原来的1/3**；
int i=0;int j=n-1;
因此只需要计算，若前i个元素的和不等于sum/3，则i++；若后j个元素的和不等于sum/3，则j--；
当前i个和后j个都等于sum/3，判断中间那一段是否为sum/3即可。

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum=0;
        for(int i=0;i<A.length;i++)
        sum+=A[i];
        sum/=3;
        int i=0;
        int n=A.length;
        int j=n-1;
        int sum_1=A[i];
        int sum_2=0;
        int sum_3=A[n-1];
        for(int k=i+1;k<j;k++)
        sum_2+=A[k];
        while(i<j-1)
        {
            if(sum_1==sum&&sum_2==sum&&sum_3==sum)
            return true;
            if(sum_1!=sum)
            {
                i++;
                sum_1+=A[i];
                sum_2-=A[i];
            }
            if(sum_3!=sum)
            {
                j--;
                sum_3+=A[j];
                sum_2-=A[j];
            }
        }
        return false;
    }
}
```
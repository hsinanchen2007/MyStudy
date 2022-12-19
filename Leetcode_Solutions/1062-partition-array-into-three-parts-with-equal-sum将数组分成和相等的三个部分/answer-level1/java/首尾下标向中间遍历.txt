### 解题思路
![1.png](https://pic.leetcode-cn.com/feab3dc801509f16fd2f80a2d4aa318f2a795019c6b18d8140828fe2f3bdb52f-1.png)
因为至少要有3个非空数组，所以可以先排除数组长度小于3的。
然后3个子非空数组要相等，所以计算数组总和是否能被3整除。如果不能则不存在3个子非空数组相等。
如果能整除则3个子非空数组的值就是数组总和除以3的值。
然后只要计算2个子非空数组的值是否等于数组总和除以3的值就可以了


### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {

        if(A.length<3)
            return false;

        int sum=0,i=0,j=A.length-1;
        for(int a:A)
            sum+=a;
        if(sum%3!=0)
            return false;
        sum/=3;
        while(i+1<j){
            if(A[i]==A[j]&&A[i]==sum)
                return true;
            if(A[i]!=sum){
                i++;
                A[i]=A[i]+A[i-1];
            }
            if(A[j]!=sum){
                j--;
                A[j]=A[j]+A[j+1];
            }

        }
        
        return false;
    }
}
```
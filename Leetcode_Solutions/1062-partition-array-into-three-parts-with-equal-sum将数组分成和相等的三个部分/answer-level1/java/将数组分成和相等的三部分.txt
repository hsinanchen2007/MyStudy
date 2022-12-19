### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum=0;
        for(int i:A)
            sum+=i;
        if(sum%3!=0)
            return false;
        sum/=3;
        int curSum=0,cnt=0;
        for(int i=0;i<A.length;i++)
        {
            curSum+=A[i];
            if(curSum==sum)
            {
                cnt++;
                curSum=0;
            }
        }
        return  cnt==3||(cnt>3&&sum==0);  //如果目标值是0可以大于三
    }
}
```
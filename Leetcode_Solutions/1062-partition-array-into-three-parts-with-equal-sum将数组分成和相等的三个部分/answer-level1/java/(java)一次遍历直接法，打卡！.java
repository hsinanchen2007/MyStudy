### 解题思路
直接遍历数组，动态存储数组和，若当前的值的和等于sum/3，则找到了一组，继续遍历，看能否找到>=3组。
这里还有>3，是因为可能有和为0的情况，比如[1,-1,1,-1,1,-1,1,-1]

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        if(A==null || A.length==0)
        return false;
        int sum=0;
        for(int num:A)
        {
            sum+=num;
        }
        if(sum%3!=0)
        return false;
        int s=0;
        int count=0;
        for(int num:A)
        {
            s+=num;
            if(s==sum/3)
            {
                count++;//找到一组
                s=0;
            }
        }
        return count>=3;
    }
}
```
### 复杂度
- 时间复杂度：O(N)
- 空间复杂度：O(1)
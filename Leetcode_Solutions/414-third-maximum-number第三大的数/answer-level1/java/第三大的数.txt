### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int thirdMax(int[] nums) {
        int max1=Integer.MIN_VALUE;
        int max2=Integer.MIN_VALUE;
        int max3=Integer.MIN_VALUE;
        //记录数据中是否含有这个值
        boolean hasMinInteger=false;
        for(int n:nums)
        {
            if(!hasMinInteger&&n==Integer.MIN_VALUE)
                hasMinInteger=true;
            if(n>max1)
            {
                max3=max2;
                max2=max1;
                max1=n;
            }
            else if(n>max2&&n!=max1)
            {
                max3=max2;
                max2=n;
            }
            else if(n>max3&&n!=max2&&n!=max1)
                max3=n;
        }
        if(max3==Integer.MIN_VALUE)
        {
            if(max2==Integer.MIN_VALUE)
                return max1;
            if(hasMinInteger)
                return max3;
            else
                return max1;
        }
        return max3;
    }
}
```
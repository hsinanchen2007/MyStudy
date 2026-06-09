### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
        int count=0;
        for(int i=0;i<nums.length;i++)
        {
            if(IsEvenDigit(nums[i]))
                count++;
        }
        return count;
    }

    public boolean IsEvenDigit(int n)
    {
        int digit=0;  //统计它的位数
        while(n!=0)
        {
            digit++;
            n=n/10;
        }
        if(digit%2==0)
            return true;
        else
            return false;
    }
}
```
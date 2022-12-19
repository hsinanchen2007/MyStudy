### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int len=nums.length;  //数组的长度
        if(len==0)
            return new int[0];
        //定义一个结果数组
        int [] res=new int [len-k+1];
        //maxlnd记录每次最大值的下标，max记录最大值
        int maxlnd=-1,max=Integer.MIN_VALUE;
        for(int i=0;i<len-k+1;i++)
        {
            //如果标号在滑动窗口中，就比较后面的值是否大于上一个滑动窗口的最大值
            if(maxlnd>=i&&maxlnd<i+k)
            {
                if(nums[i+k-1]>max)
                {
                    max=nums[i+k-1];
                    maxlnd=i+k-1;
                }
            }
            else
            {
                max=nums[i];
                for(int j=i;j<i+k;j++)
                {
                    if(max<nums[j])
                    {
                        max=nums[j];
                        maxlnd=j;
                    }
                }
            }
            res[i]=max;
        }
        return res;
    }
}
```
这道题坑很多！正解用的是成段的直接位移，先将多次重复位移复位成一次位移；再将末尾待移到头部的元素存储。然后倒序将头部后移，最后将临时存储的部分写入头部。
代码如下：
```
class Solution {
    public void rotate(int[] nums, int k) {
        int length = nums.length;
        
        while(k >= length)
        {
            k -= length;
        }
        
        int []temp = new int[k];
        for(int i = k-1; i>=0; i--)
        {
            temp[i] = nums[length-1];
            length--;
        }
        
        int j = nums.length;
        
        for(int i = length-1; i>=0; i--)
        {
            nums[j-1] = nums[i];
            j--;
        }
        for(int i = temp.length-1; i>=0; i--)
        {
            nums[i] = temp[i];
        }
        
    }
}
```
常见错解一：
k次大循环！老老实实位移，这样会被最后一个变态测试例卡住！
代码如下：
```
class Solution {
    public void rotate(int[] nums, int k) {
        int length = nums.length;
        int temp = 0;
        for(int i=0; i<k; i++)
        {
            for(int j = length-1; j>=0; j--)
            {
                if(j == length-1)
                {
                    temp = nums[length-1];
                }
                
                if(j != 0)
                {
                    nums[j] = nums[j-1];
                }
                else
                {
                    nums[0] = temp;
                    
                }
            }
        }   
    }
}
```
错解二：
计算每个数应移到何处，移动后再将该位上的元素进行位移。但是！当nums.length 为 k的整数倍时，倍数位上的元素被重复移动！
代码如下：
```
class Solution {
    public void rotate(int[] nums, int k) {
        int length = nums.length;
        int temp1  = nums[0];
        int count = 0;
        int i     = 0;
        int temp2 = 0;
        
       while(count<length)
       {
           if(i+k < length)
           {
               //temp1 = nums[i]
               temp2 = nums[i+k];
               nums[i+k] = temp1;
               temp1 = temp2;
               i = i+k;
           }
           else
           {
               int j = i+k;
               
               while(j >= length)
               {
                   j -= length;
               }
                   
               temp2 = nums[j];
               nums[j] = temp1;
               temp1 = temp2;
               i = j;
           }
           count++;
       }
        
    }
}
```


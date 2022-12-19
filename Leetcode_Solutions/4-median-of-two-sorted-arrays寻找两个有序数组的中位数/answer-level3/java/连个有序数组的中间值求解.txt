### 解题思路
首先数组A和数组B，规定A的长度m小于B的长度n;k=(m+n+1)/2；
其中如果m+n是偶数，那么中间值是第k个值和K+1个值的平均数；
如果m+n是奇数，那么中间值是第k个值；
设i取值[0，m],j=(m+n+1)/2-i-1;
i初始值取m/2;
通过i来确定j，通过处理A数组来解决B的数据；

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;

        int[] left = nums1;
        int[] right = nums2;
        if(m>n)
        {
            int tmp = m;
            m = n;
            n = tmp;

            left = nums2;
            right = nums1;
        }
        

        int min = 0;
        int max = m;
        int halfLen = (m+n+1)/2;
        int i = (max-min)/2;

        int maxleft =0 ;
        int minright = 0;

        if(m==0)
        {
            if(n%2==1)
            {
                if(n==1)
                {
                    return right[0];
                }
                else
                {
                    return (right[halfLen-1]);
                }
                
            }
            else
            {
                if(n==0)
                {
                    return 0;
                }
                else
                {
                    return (right[halfLen-1]+right[halfLen])/2.0;
                }
            }
        }

        while(min <= i && i<max)
        {
            
            int j = halfLen-i-1;
            

            if(i>min&&left[i-1]>right[j])
            {
                i = i - 1;
            }
            else if(i<=max-2 && j>0&&right[j-1]>left[i])
            {
                i = i + 1;
            }
            else
            {
                if(i==0)
                {
                    if(j==0)
                    {
                        maxleft = Math.max(left[0],right[0]);
                        minright = Math.min(left[0],right[0]);
                    }
                    else
                    {
                        if(right[j]<left[i])
                        {
                            maxleft = right[j];
                            if(max>1)
                            {
                                if(j<n-1&&left[i]>right[j+1])
                                {
                                    minright = right[j+1];
                                }
                                else
                                {
                                     minright = left[i];
                                }
                               
                            }
                            else
                            {
                                if(j+1<n)
                                {
                                    minright = Math.min(left[i],right[j+1]);
                                }
                                else
                                {
                                    minright = right[j];
                                }

                            }
                        }
                        else
                        {
                            maxleft = Math.max(left[i],right[j-1]);
                            if(max>1)
                            {
                                minright = Math.min(left[i+1],right[j]);
                            }
                            else{
                                if(left[i]<right[j-1])
                                {
                                    minright = right[j];
                                }
                                else
                                {
                                     minright = Math.max(left[i],right[j]);
                                }
                               
                            }
                            
                        }
                        
                    }
                    
                    
                }
                else if(i==max-1)
                {
                    if(j==0)
                    {
                        if(max==1)
                        {
                            maxleft = Math.min(left[i],right[0]);
                            minright =  Math.max(left[i],right[0]);
                        }
                        else
                        {
                            maxleft = Math.max(left[i-1],right[0]);
                            minright =  Math.min(left[i],right[1]);
                        }
                    }
                    else
                    {
                         if(max==1)
                        {
                             maxleft = Math.min(left[i],right[j-1]);
                             minright =  Math.max(left[i],right[j]);
                        }
                        else
                        {
                            
                            if(left[i]<right[j]&&left[i]<right[j-1])
                            {
                                maxleft = right[j-1];
                                minright = right[j];
                            }
                            else if(left[i]>right[j])
                            {
                                if(j+1<n&&left[i]>right[j+1])
                                {
                                    maxleft = right[j];
                                    minright = right[j+1];
                                }
                                else
                                {
                                    maxleft = right[j];
                                    minright = left[i];
                                }
                                
                            }
                            else
                            {
                                if(i+1<max&&left[i+1]<right[j])
                                {
                                    minright = left[i+1];
                                }
                                else
                                {
                                    minright = right[j];
                                }
                                maxleft = left[i];
                            }
                            
                        }
                    }
                    
                }
                else
                {
                    if(j==0)
                    {
                        maxleft = Math.max(left[i-1],right[j]);
                        if(left[i]>right[j])
                        {
                            maxleft = right[j];
                            minright = left[i];
                        }
                        else
                        {
                            maxleft = left[i];
                            minright = right[j];
                        }
                    }
                    else
                    {
                        if(left[i]>right[j-1]&&left[i]<=right[j])
                        {
                            maxleft = left[i];
                            if(i+1<max&&left[i+1]<=right[j])
                            {
                                minright = left[i+1];
                            }
                            else
                            {
                                minright = right[j];
                            }
                            
                        }
                        else if(left[i]>right[j])
                        {
                            maxleft = right[j];
                            if(j+1<n&&left[i]>right[j+1])
                            {
                                minright = right[j+1];
                            }
                            else if(j+1<n&&left[i]<right[j+1])
                            {
                                minright = left[i];
                            }
                            else
                            {
                                minright = left[i];
                            }
                        }
                        else
                        {
                            maxleft = right[j-1];
                            minright = right[j];
                        }
                    }
                    
                }
                if((m+n)%2==1)
                {
                    return maxleft;
                }
                else
                {
                    return (maxleft+minright)/2.0;
                }


            }
        }
        return 0;
    }
}
```
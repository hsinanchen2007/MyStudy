### 解题思路
很简单 新建一个数组依次存储两个数组中较小的那个数。然后通过下标是奇数还是偶数进行计算中位数。

### 代码

```c

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int total[100000];
    int t=0,i=0,j=0;
    double re;
    if(nums1Size==0){//异常情况处理
        if(nums2Size%2!=0)
            return nums2[(nums2Size)/2];
        else{
            re=nums2[(nums2Size)/2-1]+nums2[(nums2Size)/2];
            return re*1.00/2;
        } 
    }
    else if(nums2Size==0){//异常情况处理
        if(nums1Size%2!=0)
            return nums1[(nums1Size)/2];
        else{
            re=nums1[(nums1Size)/2-1]+nums1[(nums1Size)/2];
            return re*1.00/2;
        } 
    }
    while(t<nums1Size+nums2Size){
        if(nums1[i]<=nums2[j]){//如果nums1[i]中的数较小，total赋值为该数 并且i++,再将nums1[i+1]与nums2[j]相比
            
            total[t]=nums1[i];
            i++;
        }    
        else if(nums2[j]<=nums1[i]){
            
            total[t]=nums2[j];
            j++;
        } 
        t++;
        if(j==nums2Size){//如果nums2中的数赋值完成 则将nums1剩下的数直接赋给total
        	while(i!=nums1Size){
        		total[t]=nums1[i];
        		t++;i++;
			}
            	
        }
        else if(i==nums1Size){
        	while(j!=nums2Size){
        		total[t]=nums2[j];
        		t++;j++;
			}
            	
        }
    }
    if((nums1Size+nums2Size)%2==0){//中位数判断 如果是偶数 则中间两个值相加除2
         re=total[(nums1Size+nums2Size)/2-1]+total[(nums1Size+nums2Size)/2];
        return re*1.00/2;
    }
    else{
         re=total[(nums1Size+nums2Size)/2];
        return re;
    }
         
}
```
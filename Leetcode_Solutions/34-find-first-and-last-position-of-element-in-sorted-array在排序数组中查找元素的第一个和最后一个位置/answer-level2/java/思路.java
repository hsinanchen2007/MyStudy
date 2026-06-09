### 解题思路
此处撰写解题思路
我的思路:
    首先遍历数组，判断数组中元素是否等于target，如果相等的话，就创建一个新的数组来存放，这个下标，并且记录
下真，循环结束后判断是否为真，如果为false的时候再创建一个新的数组分别给0，1赋值为-1，因为没有找到所以提前结束
如果为真，那么就遍历找到的下标的那个数组，找最大值和最小值，最后再创建一个新的数组，将最大值和最小值分别赋值给新的数组的0，1位置

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int arr[]=new int[nums.length];
        int j=0;
        boolean flag=false;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==target){
                arr[j]=i;
                j++;
                flag=true;
            }
        }
        int c[]=new int[2];
        if(!flag){
            c[0]=-1;
            c[1]=-1;
            return c;
        }
        int b[]=new int[2];
        int min=10000000,max=-10000000;
        for(int i=0;i<j;i++){
            if(arr[i]<min){
                min=arr[i];
            }
            if(arr[i]>max){
                max=arr[i];
            }
        }
        b[0]=min;
        b[1]=max;
        return b;
        
    }
}
```
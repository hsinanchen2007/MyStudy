### 解题思路
此处撰写解题思路
我的思路:
    用二分查找法，首先判断是否找到了，如果找了这个数就记录下来，
一个循环完之后找到了就直接返回。
    如果没有找到这个数，那么就用一个新的数组，新数组的长度是原来数组长度多1个，然后将原始的
数组的值全部赋值给新数组，然后数组的最后一个添加上要查找的这个数，再通过比较排序算法来将新数组
的顺序从小到大排序，最后找用一个循环遍历出来要查找的那个值的下标，记录下来，最后返回这个记录下来的,ok'
### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int left=0;
        int right=nums.length-1;
        int mid=0;
        int index=0;
        boolean flag=false;
        while(left < right){
            mid=(left+right)/2;
            if(nums[mid]<target){
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid-1;
            }else if(nums[mid]==target){
                index=mid;
                flag=true;
                break;
            }
        }
        if(flag)
        return index;
        else{
            int arr[]=new int[nums.length+1];
              arr[arr.length-1]=target;
            for(int i=0;i<nums.length;i++){
                arr[i]=nums[i];  
            }
    
            for(int i=0;i<arr.length-1;i++){
                for(int j=i+1;j<arr.length;j++){
                    if(arr[i]>arr[j]){
                        int t=arr[i];
                        arr[i]=arr[j];
                        arr[j]=t;
                    }
                }
            }
            for(int i=0;i<arr.length;i++){
                if(arr[i]==target){
                    index=i;
                    break;
                }
            }
            return index;
        }
    }
}
```
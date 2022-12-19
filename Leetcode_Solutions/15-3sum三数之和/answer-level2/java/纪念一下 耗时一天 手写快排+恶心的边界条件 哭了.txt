### 解题思路
此处撰写解题思路

### 代码

```java
//22:43
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        
       List<List<Integer>> arrs=new ArrayList<List<Integer>>();
        if(nums.length<3) return arrs;
        quickSort(nums,0,nums.length-1);
        for(int k=0;k<nums.length;k++){
          System.out.print(nums[k]);
          System.out.print(" ");
        }

         int left=0; int right=nums.length-1;
        for(int i=0;i<nums.length-2;i++){
            if(nums[i]>0) return arrs;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
           left=i+1;right=nums.length-1;
           while(left<right){
             if(nums[i]+nums[right]+nums[left]>0){
               right--;
              }else if(nums[i]+nums[right]+nums[left]<0){
                left++;
              }else {
                  List<Integer> arr=new ArrayList();
                    arr.add(nums[i]);
                    arr.add(nums[left]);
                    arr.add(nums[right]);
                    arrs.add(arr);
                  while(left+1<nums.length&&nums[left]==nums[left+1]&&left<right){
                      left++;
                    }
                  while(right>0&&nums[right]==nums[right-1]&&left<right){
                      right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return arrs;
    }
    public static void quickSort(int[] nums,int left,int right){
        if(nums.length==1) return;
        int item=partSort(nums,left,right);
        if(item==-1) return;
        quickSort(nums,left,item-1);
        quickSort(nums,item+1,right);
    }
    public static int partSort(int[] nums,int left,int right){
        if(left>right) return -1;
        int i=left;
        int j=right;
        int target=nums[left];
        int curr=target;
        while(i!=j){
          while(nums[j]>=target&&i<j){
            j--;
           }
            while(nums[i]<=target&&i<j){
            i++;
              }
            if(i<j){
            curr=nums[i];
            nums[i]=nums[j];
            nums[j]=curr;
            }
        }
        nums[left]=nums[i];
        nums[i]=target;
        return i;
    }
}
```
### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public String minNumber(int[] nums) {
        quickSort(nums,0,nums.length-1);
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i< nums.length ; i++){
            stringBuilder.append(nums[i]);
        }
        return stringBuilder.toString();
    }
    private boolean adbx(int a,int b){
        String sab = String.valueOf(a)+String.valueOf(b);
        String sba = String.valueOf(b)+String.valueOf(a);
       if ((Double.parseDouble(sab) >= Double.parseDouble(sba)))
            return true;
        else return false;
    }
    private void quickSort(int[] nums,int left,int right){
        if (left > right)
            return;
        int l = left,r = right;
        int tmp = nums[left];
        while ( l < r ){
            while (l<r && adbx(nums[r],tmp)) { r--;}
            while (l<r && adbx( tmp,nums[l] )){ l++;}
            if (l < r){
                int t = nums[l];
                nums[l] = nums[r];
                nums[r] = t;
            }
        }
        nums[left] = nums[l];
        nums[l] = tmp;
        quickSort(nums,left,l-1);
        quickSort(nums,l+1,right);
    }
}
```
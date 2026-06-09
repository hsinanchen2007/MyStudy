```
class Solution {
    public int[] sortArray(int[] nums) {
        if(nums.length<2) return nums;
        quick3Sort(nums,0,nums.length-1);
        return nums;
        
    }
    public void quick3Sort(int[] a,int l, int r){
        if(l>=r) return;
        int left=l,i=l+1,right=r;
        int temp = a[l];
        while(i<=right){
            if(a[i]<temp){
                exchange(a,i,left);
                left++;
                i++;
            }
            else if(a[i]>temp){
                exchange(a,i,right);
                right--;
            }
            else{
                i++;
            }
        }
        quick3Sort(a,l,left-1);
        quick3Sort(a,right+1,r);
    }
    public void exchange(int[] a,int i, int j){

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

    }

}
```

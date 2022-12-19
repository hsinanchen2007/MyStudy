```
class Solution {
    public void duplicateZeros(int[] arr) {
        //快慢指针，寻找原数组中应该出现在结果数组最后一个位置的元素index
        int i=0,j=0;
        for (;i<arr.length;i++,j++) {
            if(arr[i]==0) j+=1;
            if (j>=arr.length-1) break;
        }

        //判断快指针是否溢出，溢出说明结果数组最后一个元素是0，且倒数第二个元素不是0
        int k=arr.length-1;
        if (j==arr.length) {
            arr[k--]=0;
            i--;
        }

        //倒序遍历赋值，遇0赋值两次
        for (;k>=0;k--,i--) {
            if (arr[i]==0) {
                arr[k--]=0;
                arr[k]=0;
            } else {
                arr[k]=arr[i];
            }
        }
    }
}
```

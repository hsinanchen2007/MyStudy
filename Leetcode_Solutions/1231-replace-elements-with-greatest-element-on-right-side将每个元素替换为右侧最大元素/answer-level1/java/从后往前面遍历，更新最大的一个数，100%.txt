```
class Solution {
    public int[] replaceElements(int[] arr) {
         if(arr.length==1)return new int[]{-1};
        int rightMax = arr[arr.length-1];
        arr[arr.length-1]=-1;
        for(int i=arr.length-2;i>=0;i--){
            int temp = arr[i];
            arr[i] = rightMax;
            rightMax = temp>rightMax?temp:rightMax;
        }
        return arr;
    }
}
```
从前往后面扫一遍，用rightMax记住最大的一个数，然后更新数组。

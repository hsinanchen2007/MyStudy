一开始想着只用一个数组，然后从尾部循环逐个替换，结果搞了快两小时都没成功，干脆用最直接的办法实现一个
```
class Solution {
    public void duplicateZeros(int[] arr) {
        int[] arr2 = Arrays.copyOf(arr,arr.length);
        if(arr.length==1)return;
        for(int i=0,move=0;i<arr.length;i++,move++){
            arr[i]=arr2[move];
            if(arr[i]==0&&i<arr.length-1){
                arr[i+1]=0;
                i++;
            }
        }
    }
}
```
for循环加数组
```
class Solution {
    public int tribonacci(int n) {
        int[] array = new int[38];
        for(int i=0;i<=n;i++){
            if(i<2){
                array[i] = i;
            }else if(i==2){
                array[i] = 1;
            }else{
                array[i] = array[i-3]+array[i-2]+array[i-1];
            }
        }
        return array[n];
    }
}
```

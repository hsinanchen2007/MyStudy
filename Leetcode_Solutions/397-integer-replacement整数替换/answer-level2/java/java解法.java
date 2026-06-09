执行用时 : 6 ms, 击败了53.56% 的用户。
内存消耗 : 32.8 MB, 击败了79.09% 的用户。
```
class Solution {
    public int integerReplacement(int n) {
        int[] min = new int[]{Integer.MAX_VALUE};
        getCount(min,n,0);
        return min[0];
    }
    
    private void getCount(int[] min, int n, int count){
        if(n==1){
            if(count < min[0]){
                min[0] = count;
            }
            return;
        }
        count++;
        if(n%2==0){
            getCount(min, n / 2, count);
        }else{
            getCount(min, n / 2, count + 1);//相当于（n-1）/2
            getCount(min, n / 2 + 1, count + 1);//相当于（n+1）/2
        }
    }
}
```
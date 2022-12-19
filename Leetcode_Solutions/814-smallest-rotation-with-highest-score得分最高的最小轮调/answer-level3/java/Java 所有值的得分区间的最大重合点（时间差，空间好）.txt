![Screen Shot 2019-12-02 at 11.56.59 PM.png](https://pic.leetcode-cn.com/6ababf3513d756e83fc609c51d0da27b86b18ec50a5650f4f5876b807aada8e3-Screen%20Shot%202019-12-02%20at%2011.56.59%20PM.png)
```
class Solution {
    public int bestRotation(int[] A) {
        int ans=0;
        int n=A.length;
        int[] tmp=new int[n];
        for(int i=0; i<n; i++) tmp[i]=0;

        for(int i=0; i<n; i++){
            int a=A[i];
            if(a > i){
                for(int j=i+1; j<i+n-a+1; j++) tmp[j]++;
            }
            else{
                for(int j=0; j<i-a+1; j++) tmp[j]++;
                for(int j=i+1; j<n; j++) tmp[j]++;
            }
        }

        int t = tmp[0];
        for(int i=0; i<n; i++){
            if(tmp[i] > t){
                t = tmp[i];
                ans = i;
            }
        }
        return ans;
    }
}
```

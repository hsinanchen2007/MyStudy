可以从后往前遍历，设置双指针，i代表当前温度，j从i+1位置开始往后遍历（小于数组范围），
如果T[i] < T[j] 存储当前i为j-i。如果不会升温，设零，开始下一个位置。
```
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] r = new int[T.length]; 
        r[T.length-1] = 0;
        for(int i = T.length-2; i >= 0; i--) {
            int j = i+1;
            while(true) {
                if(T[i] < T[j]) {
                    r[i] = j-i;
                    break;
                } else if(j < T.length-1){
                    j++;
                } else {
                    r[i] = 0;
                    break;
                }
            } 
        }
        return r;
    }
}
```

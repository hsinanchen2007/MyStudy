### 解题思路
思路：比如1,2,1,2,7，输出的结果是重复的数字（1+2）与重复的数字需要变成的数字之差（3,4），那就是7-3=4，
      那目的就是寻找到重复的数字，然后找到他们能够变成的数字，

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if(A.length == 0) return 0;
        Arrays.sort(A);
        int min = 0,max = 0,p  = 0;
        for(int i = 0;i<A.length-1;i++){
            if(A[i] == A[i+1]){
                min = min + A[i];//重复的数字之和
                p++;//重复的次数
            }
            int j = 0;
            int temp = A[i+1]-A[i]-1;//两个数字之间有多少位置，比如3和5之间有一个位置4
            while(p > 0 && 0 < temp){
                j++;
                max = max + A[i]+j;
                p--;
                temp--;
            }
        }
        while(p>0){      
            max = max + A[A.length-1] + p;
            p--;
            }
        return max - min;
   }
}
```
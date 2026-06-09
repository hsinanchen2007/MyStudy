### 解题思路
一开始暴力求解超时

后来先取每个time对60的模，然后计算有多少对time的模相加为60的。

### 代码

```java
class Solution {
    public int numPairsDivisibleBy60(int[] time){
        int[] record = new int[60];
        int ans = 0;

        for(int t : time){
            t %= 60;
            if(t != 0){
                ans += record[60 - t];
            }
            else ans += record[t];
            record[t]++; 
        }
        return ans;
    }
}

// class Solution {
//     public int numPairsDivisibleBy60(int[] time) {

//         if(time.length == 1) return 0;

//         int ans = 0;

//         for(int i = 0; i < time.length - 1; i++){
//             for(int j = i + 1; j < time.length; j++){
//                 if((time[i] + time[j]) % 60 == 0){
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// }
```
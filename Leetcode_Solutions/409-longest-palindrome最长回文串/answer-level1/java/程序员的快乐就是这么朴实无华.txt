### 解题思路
1. 偶数必然可以分配在轴两端，所以直接加；
2. 奇数向下取第一个小于它的偶数；
3. 只能以一个奇数为轴；

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] times = new int[80];
        for(char c : s.toCharArray()){
            times[c-'A']++;
        }
        int res = 0;
        int flagOdd = 0;
        for(int i : times){
            if(i!=0){
                if(i % 2 == 0){
                    res += i;
                }else{
                    flagOdd = 1;
                    res += i/2*2;
                }
            }
        }
        return res + flagOdd;
    }
}
```
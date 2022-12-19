### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {//求每个数的出现次数，再求最大公约数
        int gcdnum = 0;
        int[] nums = new int[10000];
        for(int i = 0; i < deck.length; i++) nums[deck[i]]++;
        for(int i : nums)
            if(i > 0){
               gcdnum = gcd(gcdnum, i);
               if(gcdnum == 1) return false;
            }
       return gcdnum >= 2;
    }
    public int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
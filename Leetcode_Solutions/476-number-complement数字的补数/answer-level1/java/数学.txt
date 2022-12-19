### 解题思路
除留余数法求解二进制数，然后按位取反就是题解了。

### 代码

```java
class Solution {
    public int findComplement(int num) {
        if(num == 0)
            return 1;

        List<Integer> reverse = new ArrayList<>();
        int ans = 0;

        while(num != 0){
            // 在while循环中，直接把num变成反码
            if(num % 2 == 0){
                reverse.add(0);
            }else{
                reverse.add(1);
            }
            num = num / 2;
        }
        for(int i = 0; i < reverse.size(); i++){
            if(reverse.get(i) == 0){
                ans = ans + (int)Math.pow(2, i);
            }
        }
        return ans;
    }
}
```
### 解题思路
1. 每次在上一个数字的情况下，像做移动一位（*2），然后加上当下的数字a。
2. 考虑到溢出的情况，如果一直累加的话，数组长的时候会发生溢出
3. 能否被5整除，在%5后，再保存回sum中
4. 最后判断是否等于0

### 代码

```java
class Solution {
    
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean> ans = new ArrayList<>();
        int sum = 0;
        for(int a : A){
            sum = ((sum << 1) + a) % 5;
            ans.add(sum == 0);
        }
        return ans;
    }
}
```
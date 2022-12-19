### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(z > x + y) return false;
        long[] nums = new long[x + y + 1];
        LinkedList<Integer> stk = new LinkedList<>();
        stk.push(Math.abs(x - y));
        while(!stk.isEmpty()){
            int tmp = stk.pop();
            if(nums[tmp] == 0){
                nums[tmp]++;
                if(tmp + x <= x + y)
                    nums[tmp + x] ++;
                if(tmp + y <= x + y)
                    nums[tmp + y] ++;
                stk.push(Math.abs(x - tmp));
                stk.push(Math.abs(y - tmp));
            }
        }
        
        if(nums[z] != 0) return true;
        return false;
    }
}
```
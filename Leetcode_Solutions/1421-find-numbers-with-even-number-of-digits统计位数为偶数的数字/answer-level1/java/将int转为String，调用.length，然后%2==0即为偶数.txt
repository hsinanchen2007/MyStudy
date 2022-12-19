### 解题思路
将int转为String，调用.length，然后%2==0即为偶数

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
        int res=0;
        for(int i:nums){
            if(String.valueOf(i).length()%2==0){
                res++;
            }
        }

        return res;
    }
}
```
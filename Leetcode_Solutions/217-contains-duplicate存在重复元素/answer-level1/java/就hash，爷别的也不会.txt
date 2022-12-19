### 解题思路
![QQ截图20200307210913.png](https://pic.leetcode-cn.com/d0d283a38cec5dd661a5890a3a5a7464189e9d8e0615e50c5809a36100416220-QQ%E6%88%AA%E5%9B%BE20200307210913.png)

### 代码

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        if(nums.length<=1){
            return false;
        }
        Map<Integer, Integer> h = new HashMap();
        for(int n : nums){
            if(h.containsKey(n)){
                return true;
            }else{
                h.put(n,1);
            }

        }
        return false;

    }
}
```
### 解题思路
关键是格雷码规则：
![image.png](https://pic.leetcode-cn.com/d3d144f1f072d67815a488486a4aedcec0a07e1875f156bcb41256d2ffb41f84-image.png)

### 代码

```java
class Solution {
    /**
     * 0位的格雷码，为0
     * 1位的格雷码，为0、1 
     * n位的格雷码，前一半为n-1位的格雷码，顺序书写，增加前缀0，十进制值不变
     * n位的格雷码，后一半为n-1位的格雷码，倒序书写，增加前缀1，等于加上十进制2^(n-1)
     */
    public List<Integer> grayCode(int n) {
        List<Integer> result = new ArrayList<>();
    
        //初始化0位的格雷码
        result.add(0);

        //动态规划，借助grayCode(n-1)求得grayCode(n)
        for(int i = 1; i <= n; i++){
            int add = 1 << i-1;
            //前面一半为old result，然后old result倒序，增加2^(n-1)
            for(int j = result.size() - 1; j >= 0; j--){
                result.add(result.get(j) + add);
            }
        }

        return result;
    }
}
```
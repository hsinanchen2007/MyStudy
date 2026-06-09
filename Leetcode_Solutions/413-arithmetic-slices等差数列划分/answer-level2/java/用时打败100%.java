### 解题思路
![WeChatWorkScreenshot_f3e43233-98c6-44db-b66d-ce318f427b72.png](https://pic.leetcode-cn.com/91ca9cee0474859c3fe2690b9eddcc7c3cff29cebd140b333236576aeb7c2c0d-WeChatWorkScreenshot_f3e43233-98c6-44db-b66d-ce318f427b72.png)

此处撰写解题思路
从index=2开始遍历，直到不满足等差条件，然后看是否有合法的等差数列，有则更新总数量，然后更新外层起点，否则外层起点i++
### 代码

```java
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int total = 0;
        int i = 0;
        while(i < A.length - 2){
            int start = i;
            int len = 2;
            while(start < A.length - 2 && A[start + 2] - A[start + 1] == A[start + 1] - A[start]){
                len++;
                start++;
            }
            if(len >= 3){
                total += (len - 3 + 1) * (len - 3 + 2) / 2;
                i = start + 1;
            } else {
                i++;
            }
        }
        return total;
    }
}
```


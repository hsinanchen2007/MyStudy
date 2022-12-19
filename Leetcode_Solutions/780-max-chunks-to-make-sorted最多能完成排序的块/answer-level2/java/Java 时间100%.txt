### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/8f7f417f0ccecb661600c6608bbabb782522afeb1b1c0e011923a384388bb52f-image.png)
每块在正确的位置时块内下标和与块内元素和相等
### 代码

```java
class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        if(n < 2) return n;
        int res = 0;
        int t = -arr[0];
        for(int i = 1; i < n; i++){
            if(t == 0){
                res++;
                t = i - arr[i];
            }else{
                t += i - arr[i];
            }
        }
        return res + 1;
    }
}
```
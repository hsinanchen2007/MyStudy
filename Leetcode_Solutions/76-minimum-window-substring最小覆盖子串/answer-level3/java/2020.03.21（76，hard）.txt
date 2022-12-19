### 解题思路
本题难度为`hard`，思路参考`438`题，基本一致

- 这道题和`438`题的区别在于要不断移动找出**最小的子串**，所以判断有些复杂

- 代码注释很好的解释了做题思路，最好在纸上画出一串字符一步一步的观察变化，最后就会迎刃而解了。

### 代码

```java []
class Solution {
    public String minWindow(String s, String t) {
        char[] arrS = s.toCharArray();
        char[] arrT = t.toCharArray();
        
        // 定义两个数组存放 arrT 中有的和窗口遍历到的
        int[] needs = new int[128];
        int[] window = new int[128];
        
        // 遍历 arrT 数组,将每个元素出现的个数存到 needs 数组中
        for (int i = 0; i < arrT.length; i++) {
            needs[arrT[i]] += 1;
        }
        
        int left = 0;
        int right = 0;
        // 记录满足要求的字符数
        int count = 0;
        // 接收结果
        String ans = "";
        // 定义最小值
        int min = arrS.length + 1;
        
        while (right < arrS.length) {
            int curR = arrS[right];
            window[curR] += 1;
            // 当 window 数组存放个数不超过 needs 数组时计数 + 1
            if (needs[curR] > 0 && needs[curR] >= window[curR]) {
                count++;
            }
            // 当计数的个数和 arrT 数组长度相等时
            while (count == arrT.length) {
                int curL = arrS[left];
                
                // 当左窗口所指元素个数不满足 needs 所存个数，计数 - 1
                if (needs[curL] > 0 && needs[curL] >= window[curL]) {
                    count--;
                }
                // 更新最小子串
                if ( (right - left) + 1 < min) {
                    min = (right - left) + 1;
                    ans = s.substring(left, right + 1);
                }  
                window[curL] = window[curL] - 1;
                left++;
            }
            right++;
        }
        return ans;
    }
}
```
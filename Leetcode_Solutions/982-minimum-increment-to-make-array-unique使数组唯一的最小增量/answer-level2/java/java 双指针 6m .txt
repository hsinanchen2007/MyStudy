![image.png](https://pic.leetcode-cn.com/5e58784350f6bde811504bb4612f51a75d85403c679c91365426720db736679a-image.png)

### 关键数据结构：
table 存储每个A数组元素的出现次数，
i 变量递增遍历 table的每一个 key
j 变量指向table中第一个 value为0的key，也就是没有在A中出现的数

### 主要过程：
遍历每个i有以下两种情况
1：当table[i]小于等于1，i++
2：当table[i]大于1时，将i处的一个元素放到j处，table[i]--，并将j移动到下一个table[j] = 0处。重复2直到table[i]递减到1。
注意在遍历i的过程中，要保证j一定位于i的右侧。

### 细节问题：
i的上边界：A中的最大值
j的上边界：table数组的大小

关于table数组的大小，我们考虑极端情况，A中所有数都是 39999，那么table数组开 80000足够大，可以装下所有数。（空间还可以根据A中最小值进一步优化）

```
class Solution {
    int MAX = 40010;
    int[] table = new int[MAX * 2];
    int iStart = 0;
    int j = 0;
    int cnt = 0;
    int maxv = 0;
    public int minIncrementForUnique(int[] A) {
        for(int t : A){
            table[t] ++;
            if(t > maxv) maxv = t;
        }

        // 确定i的初始位置
        for(int k = 0; k < MAX; k++){
            if(table[k] > 1){
                iStart = k;
                break;
            }
        }
        
        // 确定j的初始位置
        for(int k = iStart; k < MAX; k++){
            if(table[k] == 0){
                j = k;
                break;
            }
        }

        for(int i = iStart; i < maxv + 1; i++){
            int remain = table[i];

            // 确保j位于i的右侧
            if(j < i) {
                j = i;
                while(j < 2 * MAX && table[j] > 0) j++;
            }

            // 递减remain直到为1
            while(remain > 1){
                remain --;
                table[j] = 1;
                cnt += (j - i);
                while(j < 2 * MAX && table[j] > 0) j++;
            }
        }
        return cnt;
    }
}
```
![image.png](https://pic.leetcode-cn.com/fe87e8ca1521401bdeaac8ee52452c5c5174945689306ce5e444a8c71f1dfce9-image.png)

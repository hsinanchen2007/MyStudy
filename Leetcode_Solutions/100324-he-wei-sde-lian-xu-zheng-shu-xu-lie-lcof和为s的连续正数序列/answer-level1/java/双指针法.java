### 解题思路
设置i、j(j > i),在起始阶段设置i = 1、j = 2,包含i、j两数及两数范围之内的数构成一个连续的正整数序列(如i = 2、j = 5,就会构成序列[2, 3, 4, 5])。紧接着,我们开始讨论这个序列的总和与target值的大小比较。如果序列和等于target值，说明我们找到了一个有效的序列;如果序列和小于target值，说明我们还要在序列中添加数(j++);如果序列和大于target值，说明我们需要减少序列中的数(i++)。循环往复, 直到i == j跳出循环。

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        ArrayList<int[]> list = new ArrayList<>();
        int i = 1, j = 2, cur = i + j;
        int[][] ans;
        while(i < j){
            if(cur  > target){
                cur -= i;
                i++;
            }else if(cur < target){
                j++;
                cur += j;
            }else{
                int[] temp = new int[j - i + 1];
                for (int k = 0; k <= j - i; k++) {
                    temp[k] = k + i;
                }
                list.add(temp);
                cur -= i;
                i++;
            }
        }
        ans = new int[list.size()][];
        i = 0;
        while(list.size() != 0){
            ans[i] = list.remove(0);
            i++;
        }
        return ans;
    }
}
```
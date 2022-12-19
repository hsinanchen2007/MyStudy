### 解题思路
题目意思找到一组可行解即可，因为p[0]=start，已经固定，
所以从下标为2^n-1开始，往前填，只要保证当前数与左边的数（即i与i+1不同）二进位1位不同，
所以可以依次枚举当前数与左边数的每个二进位不同的情况。
然后递归，回溯，即可。
### 代码

```java
class Solution {
    List<Integer> res = new ArrayList<Integer>();
    int[] flag; //保存那个数用没用过，1表示用过，0表示没用过
    public List<Integer> circularPermutation(int n, int start) {
        flag = new int[1 << n];
        flag[start] = 1;
        res.add(start); //固定第0位
        dfs(start, n, (1 << n) - 1);    //从后往前枚举
        return res;
    }
    //left表示当前index的左边是什么数，index要填的数只要二进位与该数1位不同即可
    //n表示每个数的最多二进制位数，所以每个index下可填的数最多n种可能
    //当前枚举到那个数
    boolean dfs(int left, int n, int index){
        if(index == 0) return true; //枚举到0表示成功找到合法解
        for(int i = 0; i < n; i++){ //枚举n种情况
            int num = left ^ (1 << i);  //num为与left只有一位不同的数
            if(flag[num] == 0){ //该数没有被用过
                res.add(num);
                flag[num] = 1;
                if(dfs(num, n, index - 1))  
                    return true;
                flag[num] = 0;  //恢复现场
            }
        }
        return false;
    }
}
```
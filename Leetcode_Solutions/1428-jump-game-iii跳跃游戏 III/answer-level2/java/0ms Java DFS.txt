### 解题思路
执行用时 :0 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :47.7 MB, 在所有 java 提交中击败了100.00%的用户

今天第一次参加竞赛，以前都是报名不敢参加。。。

这一题当时卡住了，不知道怎么退出深搜，感谢题解区的大佬“一个位置搜索一次就好了”。所以我这边递归结束的条件中有一个，只要判断该位置搜索过就立即false。（当时傻乎乎的每次遍历状态数组，如果全部为true，也就是都遍历一遍了，才返回false，后来debug,发现有的位置反复搜索出不来导致栈溢出，可惜水平不够还剩两分钟了，没解决，哈哈。。）


### 代码

```java
class Solution {

    // state数组，用于标识是否被搜索过
    boolean[] st;

    public boolean canReach(int[] arr, int start) {
        st = new boolean[arr.length];
        return dfs(arr,start);
    }

    private boolean dfs(int[] arr,int index){     
        if (index < 0 || index >= arr.length) return false;       // 索引越界则false
        if (st[index] == true) return false;                      // 该位置被搜索过
        
        int value = arr[index];                                   // 当前搜索位置的值
        if (value == 0) return true;                              // 如果搜索到值为0，则返回true

        st[index] = true;                                         // 如果搜索到的值不是0，则标识当前搜索位置已经被搜索过了。

        return dfs(arr,index + value) || dfs(arr,index - value);  // 按照题目要求，继续搜索。

    }
}
```

以后会多多参赛的，感觉挺好玩的哈哈，尤其是看到排名，大佬的速度真的是可怕，加油加油~~
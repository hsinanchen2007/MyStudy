大家看看就好，每种题解都给了链接地址
```
//递归
//题解：https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/chuan-shuo-zhong-de-yue-se-fu-huan-wen-ti-by-pendy/
// class Solution {
//     public int lastRemaining(int n, int m) {
//         if (n == 1) {
//             return 0;
//         }

//         return (lastRemaining(n - 1, m) + m) % n;
//     }
// }

//迭代
//题解：https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/c-dao-tui-fa-mian-shi-ti-62-yuan-quan-zhong-zui-ho/
//我个人是通过递归的方法写出迭代的，大家看看怎么理解更容易
class Solution {
    public int lastRemaining(int n, int m) {
        //index是最后剩下的元素的索引（只剩它自己了，它的索引肯定是0）
        int index = 0;

        for (int i = 2; i <= n; i++) {
            index = (index + m) % i;
        }

        return index;
    }
}

//dp
//题解在右边链接的评论区一个叫Shanks的网友：https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/c-dao-tui-fa-mian-shi-ti-62-yuan-quan-zhong-zui-ho/
/*
    状态：还剩i个人的时候，安全人所在的位置编号 reuslt
    初始状态：只剩一个人的时候，他的位置肯定是 result = 0
    状态方程： i -> i + 1 result = （m + result） % i
*/
// class Solution {
//     public int lastRemaining(int n, int m) {
        
//         //dp[i]表示有i个数时，删除第m个数，剩下的最后的数的索引（用n+1是为了看起来更直观，dp[0]无意义）
//         int[] dp = new int[n + 1];
        
//         dp[1] = 0;

//         for (int i = 2; i <= n; i++) {
//             dp[i] = (dp[i - 1] + m) % i;
//         }

//         return dp[n];
//     }
// }

//ArrayList（或LinkedList）模拟删除的过程，剩下的最后一个数就是答案
//由于list每次删除的时间复杂度是O(n)，所以这种解法比较耗时
// class Solution {
//     public int lastRemaining(int n, int m) {
//         ArrayList<Integer> arrayList = new ArrayList<>();
//         for (int i = 0; i < n; i++) {
//             arrayList.add(i);
//         }

//         int index = 0; //index是要删除的数的位置
//         while (n > 1) {
//             index = (index + m - 1) % n;
//             arrayList.remove(index);
//             n--;
//         }

//         return arrayList.get(0);
//     }
// }
```

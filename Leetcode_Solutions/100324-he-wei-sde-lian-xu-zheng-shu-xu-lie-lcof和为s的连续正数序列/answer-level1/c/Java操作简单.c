### 解题思路
此处撰写解题思路
package LeetCodeDay;
/*
* 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]

* */


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class _57mstSumequals {
    public static void main(String[] args) {
        System.out.println(Arrays.deepToString(findContinuousSequence(9)));
    }

    public static int[][] findContinuousSequence(int target) {
        //利用滑动窗口法
        int i = 1;//左边
        int j = 1;//右边
        int sum = 0;//总数
        //list存放数组
        List<int[]> list = new ArrayList<>();
        //遍历 10不可能会出现5+6  所以取一半
        while (i <= target / 2) {
            //如果sum小于target 说明窗口总数太小了 j像右移动一位
            if (sum < target) {
                sum += j;
                j++;
            }
            //如果sum大于target 说明窗口太大了 i向右移动一位 并减去原本的i
            else if (sum > target) {
                sum -= i;
                i++;
            } else {
                //如果相等 存数据 大小是窗口的大小j-i
                int[] res = new int[j - i];
                //从i开始 j结束
                for (int k = i; k < j; k++) {
                    res[k - i] = k;
                }
                list.add(res);
                //左边向右移动
                sum -= i;
                i++;
            }
        }
        return list.toArray(new int[list.size()][]);

    }
}



### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
    int i = 1; // 滑动窗口的左边界
    int j = 1; // 滑动窗口的右边界
    int sum = 0; // 滑动窗口中数字的和
    List<int[]> res = new ArrayList<>();

    while (i <= target / 2) {
        if (sum < target) {
            // 右边界向右移动
            sum += j;
            j++;
        } else if (sum > target) {
            // 左边界向右移动
            sum -= i;
            i++;
        } else {
            // 记录结果
            int[] arr = new int[j-i];
            for (int k = i; k < j; k++) {
                arr[k-i] = k;
            }
            res.add(arr);
            // 左边界向右移动
            sum -= i;
            i++;
        }
    }

    return res.toArray(new int[res.size()][]);
}

}
```
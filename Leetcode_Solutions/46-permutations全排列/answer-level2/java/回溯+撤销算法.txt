### 解题思路
参考labuladong大神的框架-思路的代码
回溯算法
1，每次做选择，排除已经选择过的(全排列没有重复的)
2，每次做完选择，撤销回到上一步，重新做选择
3，当选择到最后一步时，也就是填充列表长度和数组长度一致时，选择完成，返回

相关待研究问题
N皇后
组合
子集

全排列优化算法
选择交换 - 待研究

### 代码

```java
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        if (nums.length < 1) {
            return list;
        }
        //全排列 回溯算法 回溯一步 撤销一步
        helper(nums, list, new ArrayList<Integer>());
        return list;
    }

    //helper 回溯算法
    public void helper(int[] nums, List<List<Integer>> list , List<Integer> listItem) {
        //listItem已经存满值了
        if (listItem.size() == nums.length) {
            list.add(new ArrayList<Integer>(listItem));
            return;
        }
        
        //依次循环回溯
        for (int i = 0; i < nums.length; i++) {
            if (listItem.contains(nums[i])) {//已经作出选择了 退出此次循环
                continue;
            } 
            listItem.add(nums[i]);//做选择
            //递归做下一选择
            helper(nums, list, listItem);
            //撤销刚才的选择 做下一选择
            listItem.remove(listItem.size() - 1);
        }

    }

}
```
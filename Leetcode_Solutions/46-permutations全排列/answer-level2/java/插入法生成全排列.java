插入法生成全排列。  
![](https://pic.leetcode-cn.com/854191e1b21014289221c10c9cce3c916fc5bffd7ed0edfa65e0ebbcea7c9435-file_1581750536129)  
图片来自[组合数学第五版](https://book.douban.com/subject/10606626/)


**代码如下**，回溯：
```
public class Solution {
    public static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> lists = new ArrayList<>();
        generatePermute(lists, new ArrayList<>(), nums);
        return lists;
    }

    /**
     * permuteLists 存储全排列
     * list 存储其中一个排列
     */
    private static void generatePermute(
            List<List<Integer>> permuteLists, List<Integer> list, int[] nums) {
        if (list.size() == nums.length) {
            // 必须要 new 一个 list 再 add，因为 list 是引用传递
            // 在退出递归时 list.remove 会把 list 清空，permuteLists 也会变空
            permuteLists.add(new ArrayList<>(list));
            return;
        }
        // 对于每一个长度为 n 的排列来说，有 n + 1 个插入位置
        for (int i = 0; i <= list.size(); i++) {
            list.add(i, nums[list.size()]);
            generatePermute(permuteLists, list, nums);
            list.remove(i);
        }
    }
}
```
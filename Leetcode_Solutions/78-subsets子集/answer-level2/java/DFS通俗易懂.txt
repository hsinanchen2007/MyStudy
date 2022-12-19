解题思路：
对于每一个数，都有选择或者不选择的抉择，然后就会衍生出一颗满二叉树，只要进行一次二叉树的前序遍历即可
看了几个大家的写法，感觉理解起来有点不是很容易，所以自己写了一个
 
![1.png](https://pic.leetcode-cn.com/cd6cd9916941404dddfe82f17ff549a39f9c56ed1547129aadc97ba83a3763a6-1.png)


1：先排序好数组
2：开始DFS

```
class Solution {
        List<List<Integer>> result = new ArrayList<>();

        public List<List<Integer>> subsets(int[] nums) {
            if (nums.length == 0) {
                return result;
            }
            Arrays.sort(nums);
            sub(nums, new ArrayList<>(), 0);
            return result;
        }

        public void sub(int[] nums, List<Integer> sub, Integer level) {
            //terminal
            if (level >= nums.length) {
                result.add(new ArrayList<>(sub));
                return;
            }

            //drill down
            sub(nums, sub, level + 1);
            sub.add(nums[level]);
            sub(nums, sub, level + 1);

            //clean data
            sub.remove(sub.size() - 1);
        }
    }
```
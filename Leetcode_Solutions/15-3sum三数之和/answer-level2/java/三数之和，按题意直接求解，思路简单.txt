### 解题思路
![image.png](https://pic.leetcode-cn.com/5ab58fe6d21e350e29a5e381dc6bb77d88bdf68aabd898b68954b6b93d38e914-image.png)
按题意直接求解，思路简单。首先排序；
i指向当前值，st从i的下一个位置开始，ed从数组最后一个开始。遍历时去重。

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int st = 0;
        int ed = nums.length - 1;
        List<List<Integer>> ls = new ArrayList<>();
        for (int i = 0; i < nums.length - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {// 如果当前值与前一个相同，则跳过，保证不重复，从第二个数开始判断
                continue;
            }
            st = i + 1;
            ed = nums.length - 1;
            //System.out.println("for: " + st + " " + ed);
            while (st < ed) {
                if (st > i + 1 && nums[st] == nums[st - 1]) {// 如果当前值与前一个相同，则跳过，保证不重复。
                                        // st > i + 1保证st位置的数和i位置的数不是一个
                    st++;
                    continue;
                }
                //System.out.print("while: " + nums[i] + nums[st] + nums[ed] + " ");
                if (nums[i] + nums[st] + nums[ed] < 0) {//和小于0，移动st
                    st++;
                } else if (nums[i] + nums[st] + nums[ed] > 0) {//和大于0，移动ed
                    ed--;
                } else if (nums[i] + nums[st] + nums[ed] == 0) {//和等于0，记录结果，修改st、ed
                    List<Integer> tmp = new ArrayList<>();
                    tmp.add(nums[i]);
                    tmp.add(nums[st]);
                    tmp.add(nums[ed]);
                    ls.add(tmp);
                    st++;
                    ed--;
                    //System.out.print(" tmp" + tmp);
                }
            }
        }
        //System.out.println(ls);

        return ls;
    }
}
```
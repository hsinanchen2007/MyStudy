### 解题思路
一开始想要用回溯，感觉不太方便，后来采用了朴素的思想，先考虑1个数的排列，两个数的排列，三个数的排列，找规律，其实就是list的插入，可以自己拿个纸笔画一画，很容易找出来。
有了规律就需要循环了。
本来以为三重循环效率很低，可能是用例比较少的原因？居然超过99.84的用户，尴尬。
![截图.PNG](https://pic.leetcode-cn.com/0cda9108fdd8ff863853289d4698b3e646031e4112d6154cae0c7459eb79fbf9-%E6%88%AA%E5%9B%BE.PNG)


### 代码

```java
class Solution {
   List<List<Integer>> results = new ArrayList<>();

    public List<List<Integer>> permute(int[] nums) {
        if (nums.length == 0) {
            return results;
        }
        List<Integer> list = new ArrayList<>();
        list.add(nums[0]);
        results.add(list);
         for (int i = 1; i < nums.length; i++) {
            int toAdd = nums[i];
            List<List<Integer>> tmp = new ArrayList<>(results);
            results.clear();
            for (int j = 0; j < tmp.size(); j++) {
                List<Integer> toAddList = tmp.get(j);
                int size = toAddList.size();
                for (int k = 0; k <= size; k++) {
                    List<Integer> tmpList = new ArrayList<>(toAddList);
                    tmpList.add(k, toAdd);
                    results.add(new ArrayList<>(tmpList));
                }
            }
        }
        return results;
    }
}
```
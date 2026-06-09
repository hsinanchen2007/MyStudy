### 解题思路
1、入参校验很重要。要判null、输入数据个数、数据的范围

2、逻辑：
1）先排序，再用三个标识k、i、j来标识三个数字
2）依次扫描k, 对i,j, 判断3个数之和，根据和的大小，分别左移j、右移i.
直到i=j停止，再进行下一个k的扫描.

3、可优化的点：
1）当num[k]>0时，此时和一定大于0，结束遍历
2）当k>0时，跳过计算过的数字。对连续的相同数字，可直接跳过
3) 对i,j的扫描也是一样，跳过计算过的数字。（注：这里应该先移动，再跳过重复数据）

4、关于去重
1）可用set去重
Set finalResult = new LinkedHashSet();
        finalResult.addAll(list);
        list.clear();
        list.addAll(finalResult);
2）如果考虑到了3中的所有情况，就不会有重复的结果，不用特意写set去重。

5、其他
1)int[]转list<Integer>
Arrays.asList(nums[k], nums[i], nums[j])
2)排序
数组的排序：Array.sort(arrayName)
List的排序：Collections.sort(tempList);

### 代码

```java
class Solution {
     public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(nums);
        for (int k = 0; k < nums.length - 2; k++) {
            if (nums[k] > 0) {
                break;
            }
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            int i = k + 1;
            int j = nums.length - 1;
            while (i < j) {
                int s = nums[k] + nums[i] + nums[j];
                if (s > 0) {
                    j--;
                    while (i < j && nums[j] == nums[j + 1]) {
                        j--;
                    }
                } else if (s < 0) {
                    i++;
                    while (i < j && nums[i] == nums[i - 1]) {
                        i++;
                    }
                } else {
                    list.add(Arrays.asList(nums[k], nums[i], nums[j]));
                    i++;
                    j--;
                    while (i < j && nums[i] == nums[i - 1]) {
                        i++;
                    }
                    while (i < j && nums[j] == nums[j + 1]) {
                        j--;
                    }
                }
            }
        }
        return list;
    }

}
```
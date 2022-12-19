### 解题思路
执行用时 :18 ms, 在所有 Java 提交中击败了21.88%的用户
内存消耗 :41.6 MB, 在所有 Java 提交中击败了6.79%的用户
虽然用的时间和内存多了，但是更好理解了

当存在重复元素时，元素只能用一次，且结果集还不能有重复
元素只能用一次：给所有元素排序，只能用当前元素往后的元素，前边遍历过的就不再使用了即可
结果集不重复：使用给map生成key值的方式，如果已经有该结果了，就不再加入到结果集

### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> list = new ArrayList<>();
        if (candidates == null || candidates.length == 0)
        {
            return list;
        }
        Arrays.sort(candidates);
        LinkedList<Integer> path = new LinkedList<>();
        Map<String, Integer> map = new HashMap<>();
        getComb(candidates, target, list, path, 0, 0, map);
        return list;
    }

    private void getComb(int[] cand, int target, List list, LinkedList path, int idx, int sum, Map map)
    {
        // System.out.println("idx:"+idx+" val:"+cand[idx]+" sum:"+sum);
        if (sum == target)
        {
            String pathStr = getPathStr(path);
            if (map.get(pathStr) == null)
            {
                list.add(new ArrayList<>(path));
                map.put(pathStr, 1);
            }
            
        }
        
        if  (idx == cand.length)
        {
            return;
        }
        for (int i = idx; i < cand.length; i ++)
        {
            // 为了少进方法 在方法外判断
            if (sum + cand[i] > target)
            {
                // 到当前值就大于目标值了 就不需要再执行当前循环了
                break;
            }
            path.add(cand[i]);
            getComb(cand, target, list, path, i+1, sum+cand[i], map);
            path.removeLast();
        }
    }

    private String getPathStr(List<Integer> path)
    {
        String str = "";
        for (int i : path)
        {
            str += i+"";
        }
        // System.out.println("str:"+str);
        return str;
    }
}
```
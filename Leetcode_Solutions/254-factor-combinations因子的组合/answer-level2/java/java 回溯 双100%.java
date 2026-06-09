![image.png](https://pic.leetcode-cn.com/d830ea7f8991f3475360a244fb7c899bccc713cc1dbbd1c7223f3d74c0439274-image.png)

```java
class Solution {
    private List<List<Integer>> ansList;

    // 求一个数的所有小于sqrt(num)的因子
    private List<Integer> getSmallFactors(int num) {
        List<Integer> list = new ArrayList<>();
        int end = (int) Math.sqrt(num);
        for (int i = 2; i <= end; i++) {
            if (num % i == 0) {
                list.add(i);
            }
        }
        return list;
    }

    private void backTrack(int num, List<Integer> tmpList) {
        tmpList.add(num);
        ansList.add(new ArrayList<>(tmpList));
        tmpList.remove(tmpList.size() - 1);
        List<Integer> factors = getSmallFactors(num);
        int size = tmpList.size();
        for (Integer factor: factors) {
            if (size >= 1 && factor < tmpList.get(size - 1)) { // 保证因子列表是非递减的
                continue;
            }

            tmpList.add(factor);
            backTrack(num / factor, tmpList);
            tmpList.remove(tmpList.size() - 1);
        }

    }

    public List<List<Integer>> getFactors(int n) {
        ansList = new ArrayList<>();
        backTrack(n, new ArrayList<>());
        ansList.remove(0);
        return ansList;
    }
}
```

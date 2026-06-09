【总体思路】先找出数组中只出现1次的元素，然后取其中的最大值。
```
import java.util.*;

class Solution {
    public int largestUniqueNumber(int[] A) {
        Map<Integer, Integer> map = new HashMap<>();
        List<Integer> list = new ArrayList<>();
        // 遍历数组，将数组中的元素和元素的出现次数放入一个map
        for (int i = 0; i < A.length; i++) {
            map.put(A[i], map.getOrDefault(A[i], 0) + 1);
        }
        // map生成后，遍历map的keyset，如果其value等于1，放入list
        for (int number : map.keySet()) {
            if (map.get(number) == 1) {
                list.add(number);
            }
        }
        // 如果list为空，返回-1
        if (list.size() == 0) {
            return -1;
        } else { // 如果list不为空，返回list的最大值。
            return Collections.max(list);
        }
    }
}
```

附测试用例：
```
import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {
    @Test
    public void test01(){
        Solution solution = new Solution();
        int[] a = {5,7,3,9,4,9,8,3,1};
        Assert.assertEquals(solution.largestUniqueNumber(a),8);
    }

    @Test
    public void test02(){
        Solution solution = new Solution();
        int[] a = {9,9,8,8};
        Assert.assertEquals(solution.largestUniqueNumber(a),-1);
    }
}
```



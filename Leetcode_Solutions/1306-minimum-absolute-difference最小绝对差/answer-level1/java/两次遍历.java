![微信图片_20191015153536.png](https://pic.leetcode-cn.com/7be67de63f33b74c744130ee845e7ac418dc9dac299e16095d590e87e2d2bcab-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191015153536.png)
```
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(arr);//升序排列
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i + 1] - arr[i] < min) {
                min = arr[i + 1] - arr[i];
            }
        }
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i + 1] - arr[i] == min) {
                List<Integer> list1 = new ArrayList<>();
                list1.add(arr[i]);
                list1.add(arr[i + 1]);
                list.add(list1);
            }
        }

        return list;
    }
}
```

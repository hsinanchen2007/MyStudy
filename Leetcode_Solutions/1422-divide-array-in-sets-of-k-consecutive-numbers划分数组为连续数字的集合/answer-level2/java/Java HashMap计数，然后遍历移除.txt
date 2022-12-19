![TIM截图20191222142714.png](https://pic.leetcode-cn.com/ebfeffdc24b2887de0d60ad5cb9a97915beb537adcf92288ae5824d09e17c076-TIM%E6%88%AA%E5%9B%BE20191222142714.png)

 基础思路
1. 利用hashmap统计数组中每个数字出现的次数
2. 将结果装到一个二维数组mark[][]中,mark[i][0]表示出现的数字，mark[i][1]是其对应出现的次数
3. 用lambda表达式将mark按第一列升序排序
4. 变量j遍历数组，每次从mark数组中拿出k个字符
5. 首先判断拿出来的k个字符是否连续，不连续则false
6. 将每个字符出现的个数减去mark[j][1],即减去拿出来的字符串的第一个字符出现的次数，也就是从数组中移除了以mark[j][0]开头的、长度为k的所有连续字串
7. 判断数组中是否全部数字被移除，是则true，否则false
```
class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        //处理极端情况
        if (k == 1)
            return true;
        //用hashmap统计出现的数字和其次数
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }
        //将统计的结果存到二维数组中
        int[][] mark = new int[map.size()][2];
        int q = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            mark[q][0] = entry.getKey();
            mark[q][1] = entry.getValue();
            q++;
        }
        //把数组按第一列也就是出现的数字从小到大排序    
        Arrays.sort(mark, (a,b) -> (a[0] - b[0]));
        //从mark第一列中每次取出k个元素，首先判断它们是否连续，不连续则返回false
        //连续的话则对应的mark第二列减去mark[j][1],即移除以mark[j][0]开头的所有长度为k的连续字串
        int len = mark.length;
        for (int j = 0; j <= len - k; j++) {
            if (mark[j][1] == 0)
                continue;
            for (int p = j; p <= j + k - 2; p++) {
                if (mark[p][0] != mark[p + 1][0] - 1)
                    return false;
            }
            for (int p = j + 1; p <= j + k - 1; p++) {
                mark[p][1] -= mark[j][1];
                if (mark[p][1] < 0)
                    return false;
            }
            mark[j][1] = 0;
        }
        //判断数组中是否所有元素都已经被移除
        for (int j = 0; j < len; j++) {
            if (mark[j][1] != 0)
                return false;
        }
        return true;
    }
}
```

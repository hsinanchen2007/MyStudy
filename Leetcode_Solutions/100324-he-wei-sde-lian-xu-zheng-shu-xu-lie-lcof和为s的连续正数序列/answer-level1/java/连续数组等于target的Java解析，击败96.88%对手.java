### 解题思路
个人感觉这个算法不好，但是看到击败96.88%，内存消耗击败100%就写个笔记，后续补上别人优秀代码！！！
1. 根据`upper * (upper + 1)/2 = target`求出上限，即`1 + 2 + ... + upper = target`；
2. 因为至少需要两个元素相加等于target，因而起始begin = 2，并记录begin是偶数还是奇数，即isOdd进行判断；
3. 计算`middle = target/begin`，当begin是偶数，即`isOdd = false`时，若满足题目要求，则有middle + middle + 1 = target，middle - 1 + (middle + 2) = target, ..., middle - begin + 1 + (middle + begin) = target，即`(middle *2 + 1) * begin/2 == target`,则将对应的值添加到数组中；
4. 若begin是奇数，即`isOdd = true`时，此时middle必定是最中间的数，即`middle * begin = target`，并添加到数组中。
即可完成。

其实个人感觉如何通**过List转换为二维数组才是重点**，因为第一次碰到二维数组中的元素个数不一样的情况，不知道如何处理，因而该部分照抄别人答案！！！


### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        if(target < 3) {
            int[][] array = {};
            return array;
        }
        int upper = (int)(-0.5 + Math.sqrt(0.25 + 2.0 * target));
        List<int[]> result = new ArrayList<>();
        int begin = 2;
        boolean isOdd = true;
        int middle = 0;
        while(begin <= upper){
            isOdd = !isOdd;
            middle = target/begin;
            if(!isOdd && (middle * 2 + 1) * begin/2 == target){
                result.add(getEverryResult(middle - begin/2 + 1, middle + begin/2));
            }else if(isOdd && middle * begin == target){
                result.add(getEverryResult(middle - begin/2, middle + begin/2));
            }
            begin ++;
        }
        List<int[]> resultReverse = new ArrayList<>();
        for(int i = result.size() - 1; i >= 0; i --) resultReverse.add(result.get(i));
        return resultReverse.toArray(new int[0][]);
    }

    public int[] getEverryResult(int begin, int upper){
        int[] result = new int[upper - begin + 1];
        int i = 0;
        while(begin + i <= upper){
            result[i] = begin + i ++;
        }
        return result;
    }
}
```
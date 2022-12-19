参考大佬的C++解法，C++中用vector实现，只消耗了6m内存。
java的list做不到那么优秀了，但是一维数据结构解决这个问题的思想非常值得借鉴。
原解法：https://leetcode-cn.com/problems/pascals-triangle-ii/solution/c-8xing-dai-ma-jian-ji-yi-dong-by-heroma-2/


```
class Solution {
    public List<Integer> getRow(int rowIndex){
        List<Integer> result = new ArrayList<>();
        for(int i = 0 ; i <= rowIndex; ++i) {
            result.add(1);
            for(int j = i-1 ; j>0 ; --j ){
                result.set(j,result.get(j)+result.get(j-1));
            }
        }
        return result;
    }
}
```

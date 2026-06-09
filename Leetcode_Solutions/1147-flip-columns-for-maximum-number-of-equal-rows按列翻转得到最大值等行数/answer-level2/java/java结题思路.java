### 解题思路
1、得到当前二维数组的相等行和不等行，如果相等行大于等于不等行，那就直接返回相等行
2、如果不等行大于相等行，统计每行最小翻转位置，如果0和1的翻转次数一样，这行就有2个最小翻转位置
3、统计不等行中最小翻转位置最多的行数，如果比相等行大，则最大等行数为它，否则还是相等行的数量

### 代码

```java
class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int sameNum = 0;
        int unSameNum = 0;
        Map<Integer, String> unSameRows = new HashMap<>();
        for (int i = 0; i < matrix.length; i++) {
            List<String> zeroNum = new ArrayList<>();
            List<String> oneNum = new ArrayList<>();
            for (int j = 0; j < matrix[i].length; j++) {
                if (0 == matrix[i][j]) {
                    zeroNum.add(String.valueOf(j));
                    continue;
                }
                oneNum.add(String.valueOf(j));
            }
            if (0 == zeroNum.size() || 0 == oneNum.size()) {
                sameNum++;
                continue;
            }
            unSameNum++;
            if (oneNum.size() == zeroNum.size()) {
                unSameRows.put(i, String.join("|", zeroNum));
                unSameRows.put(matrix.length + i, String.join("|", oneNum));
                continue;
            }
            unSameRows.put(i, oneNum.size() > zeroNum.size() ? String.join("|", zeroNum) : String.join("|", oneNum));
        }

        if (sameNum >= unSameNum) {
            return sameNum;
        }

        Map<String, Integer> result = new HashMap<>();
        for (String unSameStr : unSameRows.values()) {
            if (result.containsKey(unSameStr)) {
                result.put(unSameStr, result.get(unSameStr) + 1);
                continue;
            }
            result.put(unSameStr, 1);
        }
        
        int maxUnsameNum = 0;
        for (Integer count : result.values()) {
            if (maxUnsameNum < count.intValue()) {
                maxUnsameNum = count.intValue();
            } 
        }

        return maxUnsameNum > sameNum ? maxUnsameNum : sameNum;
    }
}
```
```
public int[] getModifiedArray(int length, int[][] updates) {
        int[] result = new int[length];
        for (int[] tempArray : updates) {
            int start = tempArray[0];
            int end = tempArray[1];
            int updateNum = tempArray[2];
            for (int j = start; j <= end; j++) {
                result[j] = result[j] + updateNum;
            }
        }
        return result;
    }
```

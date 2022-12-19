### 解题思路
用数组来标记出现的次数，内存用的少，但是耗时长了些

### 代码

```java
class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        List<String> result = new LinkedList<>();
        int[] aCount = new int[26];
        int[] bCount = new int[26];
        int[] bMaxCount = new int[26];
        for (String strb : B) {
           Arrays.fill(bCount,0);
           getCharCount(strb, bCount);
           for (int i = 0; i < 26; ++i){
               if (bCount[i] > bMaxCount[i]){
                   bMaxCount[i] = bCount[i];
               }
           }
        }
        for (String strA : A) {
            Arrays.fill(aCount, 0);
            getCharCount(strA, aCount);
            boolean isChildren = isChildren(aCount, bMaxCount);
            if (isChildren == true){
                result.add(strA);
            }
        }
        return result;
    }
    private void getCharCount(String str, int[] count) {
        for (int i = 0; i < str.length(); ++i) {
            int tmp = str.charAt(i) - 'a';
            count[tmp]++;
        }
    }
    private boolean isChildren(int[] fahter, int[] children) {
        boolean result = true;
        for(int i = 0; i < 26; ++i) {
            if (fahter[i] < children[i]){
                result = false;
                break;
            }
        }
        return result;
    }
}
```
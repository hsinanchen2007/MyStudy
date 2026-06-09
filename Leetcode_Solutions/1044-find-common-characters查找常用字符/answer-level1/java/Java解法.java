### 执行结果
执行用时 :
2 ms, 在所有 Java 提交中击败了98.78%的用户
内存消耗 :
36.8 MB, 在所有 Java 提交中击败了96.08%的用户


### 代码

```java
class Solution {
    public List<String> commonChars(String[] A) {
        List<String> lst = new ArrayList<>();
        int[] freqMin = new int[26];
        for (int i = 0; i < 26; i++) {
            freqMin[i] = Integer.MAX_VALUE;
        }
        for (int i = 0; i < A.length ; i++) {
            int[] freqI = freqCount(A[i]);
            for (int j = 0; j < freqI.length ; j++) {
                if(freqI[j] < freqMin[j]){
                    freqMin[j] = freqI[j];
                }
            }
        }

        for (int i = 0; i < freqMin.length; i++) {
            if(freqMin[i] > 0 ){
                inset2List(lst,String.valueOf((char)(i+'a')),freqMin[i]);
            }
        }

        return lst;
    }

    public void inset2List(List<String> lst, String s, int times){
        for (int i = 0; i < times ; i++) {
            lst.add(s);
        }
    }

    public int[] freqCount(String chars){
        int[] freqs = new int[26];
        for(char chr:chars.toCharArray()){
            freqs[chr-'a']++;
        }

        return freqs;
    }
}
```
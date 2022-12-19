
java 很无奈的解法, 能看懂我代码思路的也是没谁了。。
```
class Solution {
    public List<String> commonChars(String[] A) {
        List<String> list = new ArrayList<>();
        for (int i=0; i<A[0].length(); i++) {
            for (int j=1; j<A.length; j++) {
                if (!A[j].contains(String.valueOf(A[0].charAt(i)))) {
                    break;
                } else {
                    A[j] = A[j].replaceFirst(String.valueOf(A[0].charAt(i)), "");
                }

                if (j==A.length-1) {
                    list.add(String.valueOf(A[0].charAt(i)));
                    break;
                }

            }

        }
        return list;
    }
}
```
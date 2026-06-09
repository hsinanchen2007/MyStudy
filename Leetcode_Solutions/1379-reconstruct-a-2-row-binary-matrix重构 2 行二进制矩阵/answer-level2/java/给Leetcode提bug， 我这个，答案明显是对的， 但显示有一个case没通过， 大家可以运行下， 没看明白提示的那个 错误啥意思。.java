```java
class Solution {
    public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
        List<List<Integer>> res = new ArrayList<>();
        if (colsum.length <= 0) {
            return res;
        }
        int minUpper = 0;
        int minLower = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        for (int item : colsum) {
            if (item == 2) {
                a++;
            }
            if (item == 1) {
                b++;
            }
            if (item == 0) {
                c++;
            }
        }
        if (a > upper || a > lower) {
            return res;
        }
        upper-=a;
        lower-=a;
        if (b != upper + lower) {
            return res;
        }
        List<Integer> upRow = new ArrayList<>();
        List<Integer> bottomRow = new ArrayList<>();
        for (int item : colsum) {
           if (item == 2) {
                upRow.add(1);
                bottomRow.add(1);
            }
            if (item == 1) {
                if (--upper != 0) {
                    upRow.add(1);
                    bottomRow.add(0);
                } else {
                    upRow.add(0);
                    bottomRow.add(1);
                }
            }
            if (item == 0) {
                upRow.add(0);
                bottomRow.add(0);
            } 
        }
        res.add(upRow);
        res.add(bottomRow);
        return res;
    }
}
```
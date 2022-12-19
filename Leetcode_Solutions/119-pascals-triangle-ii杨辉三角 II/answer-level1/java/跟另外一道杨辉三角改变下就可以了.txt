### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {

     List<Integer> result = new ArrayList<>();


        if (rowIndex < 2) {
            for (int j = 0; j < rowIndex+1; j++) {
                result.add(1);
            }
        } else {
            for (int j = 0; j < 2; j++) {
                result.add(1);
                // row2
            }
            for (int i = 3; i <= rowIndex+1; i++) {
                int a = 0;
                List<Integer> tmp = new ArrayList<>();
                tmp.add(1);
                while (a < (i-2)) {
                    tmp.add(result.get(a) + result.get(a + 1));
                    a++;
                }
                tmp.add(1);
                result = tmp;
            }
        }
        return result;
    }
}
```
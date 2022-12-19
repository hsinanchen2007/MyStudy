### 解题思路
把 特殊条件分隔开，，分开进行

### 代码

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {

        List<List<Integer>> result = new ArrayList<>();
        List<Integer> tmp = null;
       if (numRows == 0){
            return result;
        }
        if (numRows <= 2 && numRows> 0){
            for (int i = 0 ;i < numRows; i++){
                tmp = new ArrayList<>();
                for (int j = 0; j< i+1; j++){
                    tmp.add(1);
                }
                result.add(tmp);
            }
        }else {
            for (int i = 0 ;i < 2; i++){
                tmp = new ArrayList<>();
                for (int j = 0; j< i+1; j++){
                    tmp.add(1);
                }
                result.add(tmp);
            }
            for (int i = 3 ; i <= numRows  ; i++){
                int j = 0;
               List<Integer> rowtmp = new ArrayList<>();
               rowtmp.add(1);
               while (j < (i-2)){
                   rowtmp.add(tmp.get(j) + tmp.get(j+1));
                   j ++;
               }
               rowtmp.add(1);
               result.add(rowtmp);
               tmp = rowtmp;
            }
        }
        return result;
    }
}
```
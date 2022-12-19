![image.png](https://pic.leetcode-cn.com/e305e1fc764b1fe0d6b27a534cefe3be48788481f4e3a0b5101961f4a187c3ae-image.png)

```
class Solution {
    public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
        List<List<Integer>> answer;
        List<Integer> up, low;
        int i, n;

        n = colsum.length;
        answer = new ArrayList<>(2);
        up = new ArrayList<>(n);
        low = new ArrayList<>(n);
        for(i = 0; i < n; i++){
            if(colsum[i] == 2){
                upper--;
                lower--;
            }
        }
        if(upper < 0 || lower < 0)
            return answer;
        for(i = 0; i < n; i++){
            if(colsum[i] == 2){
                up.add(1);
                low.add(1);
            }else if(colsum[i] == 0){
                up.add(0);
                low.add(0);
            }else{
                if(upper > 0){
                    up.add(1);
                    low.add(0);
                    upper--;
                }else if(lower > 0){
                    up.add(0);
                    low.add(1);
                    lower--;
                }else{
                    return answer;
                }
            }
        }
        if(upper > 0 || lower > 0)
            return answer;
        answer.add(up);
        answer.add(low);
        return answer;
    }
}
```

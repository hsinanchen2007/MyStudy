```
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result=new ArrayList<>();
        if(matrix.length==0)
            return result;
        //最小/最大列数
        int minL=0;
        int maxL=matrix[0].length-1;
        //最小/最大行数
        int minH=0;
        int maxH=matrix.length-1;

        while (result.size()<(matrix.length*matrix[0].length)){
            for(int i=0;i<matrix.length;i++) {
                int[] ints = matrix[i];
                if (i == minH) {
                    //第1行
                    for (int j = 0; j < ints.length; j++) {
                        if(!result.contains(ints[j]))
                            result.add(ints[j]);
                    }
                } else if(minH < i && i < maxH){
                    //中间行
                    for (int j = ints.length - 1; j >= 0; j--) {
                        if (j == maxL) {
                            //最后1列上至下
                            result.add(ints[j]);
                            break;
                        }
                    }
                } else if (i == maxH) {
                    //最后1行
                    for (int j = ints.length - 1; j >= 0; j--) {
                        if(!result.contains(ints[j]))
                            result.add(ints[j]);
                    }
                    //中间行：第1列下至上
                    for (int k = matrix.length - 1;  k >= 0; k--) {
                        int[] ints2 = matrix[k];
                        if(k>minH&&k<maxH){
                            for (int j = ints2.length - 1; j >= 0; j--) {
                                //第1列下至上
                                if(!result.contains(ints2[minL]))
                                    result.add(ints2[minL]);
                                break;
                            }
                        }
                    }
                    maxH--;
                    minH++;
                    maxL--;
                    minL++;
                }
            }
        }

        return result;
    }
}
```

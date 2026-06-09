解题思路：
将每一行的士兵数量x1000+索引存到一个新的列表里，然后对这个列表进行排序，取前面的k位对1000取余即是需要的索引值。
```
 class Solution {
        public int[] kWeakestRows(int[][] mat, int k) {
            int[] list = new int[mat.length];
            int[] result = new int[k];
            for(int i=0;i<mat.length;i++){
                list[i] = count(mat[i])*100+i;
            }
            Arrays.sort(list);
            for(int i=0;i<k;i++){
                result[i] = list[i]%100;
            }
            return result;
        }

        public int count(int[] nums){
            int sum=0;
            for(int n:nums){
                if(n!=1){
                    break;
                }
                sum+=n;
            }
            return sum;
        }
    }
```

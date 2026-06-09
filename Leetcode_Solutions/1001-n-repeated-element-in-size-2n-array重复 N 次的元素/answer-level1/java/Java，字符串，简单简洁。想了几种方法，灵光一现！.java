// 执行用时 :1 ms, 在所有 Java 提交中击败了99.53%的用户
// 内存消耗 :38.2 MB, 在所有 Java 提交中击败了95.78%的用户
// ```
class Solution {
    public int repeatedNTimes(int[] A) {
        String str = "";
        for (int i = 0; i < A.length; i++){
            if (str.contains(A[i]+"")){
                return A[i];
            }else{
                str += A[i];
            }
        }
        return 0;
    }
}
// ```

// 当然还有别的思路，先排序，然后判断。但是因为用了排序所以这个比较慢:
// ```
class Solution {
    public int repeatedNTimes(int[] A) {
         Arrays.sort(A);
        if (A[A.length/2 - 2] == A[A.length/2 -1]){
            return A[A.length/2 - 1];
        }else{
            return A[A.length/2];
        }
        

    }
}
// ```

// 所以改进了排序，用计数排序能快点，50%:
// ```
class Solution {
    public int repeatedNTimes(int[] A) {
 		int max = A[0];
 		for (int i = 0; i < A.length/2+1; i++) {
 			if(max < A[i]) {
 				max = A[i];
 			}
			
 		}
 		int [] ANew = new int[max + 1];
 		for (int i = 0; i < A.length/2+1; i++) {
 			ANew[A[i]]++;
 		}
         for (int i = 0; i < ANew.length; i++){
         if (ANew[i] > 1){
             return i;
         }
     }
         return A[A.length/2 + 1];
    }
}
// ```



// 当然也可以不用排序，用hash表,但是也不怎么快:
// ```
class Solution {
    public int repeatedNTimes(int[] A) {
       
         Set<Integer> set = new HashSet<Integer>();
         for (int i = 0; i < A.length/2 + 2; i++){
             set.add(A[i]);
         }
         for (int i = 0; i < A.length/2 + 2; i++){
             if (set.contains(A[i])){
                 set.remove(A[i]);
             }else{
                 return A[i];
             }
         }
         return 0;
    }
}
// ```

// 提交之后看了一下最快的那个，他的思路是相邻两个查，相邻三个查，相邻四个查，查到为止，因为分的最散的时候也就是每隔一个出现一个，不然必定连续出现两个或者两个以上。
// 还发现直接两层for暴力破解反而比其他的更快？不理解，是我们想太多了吗？
// 还有用随机的函数的，因为目标数出现的盖了比较大，任意取两个数，相同的概率是1/2，而且每次只比较一次，确实是很好的思路。我也想过用随机，但想的是用抓取一大把的想法，而没有想到这么完美的抓取两个个就行。惊讶随机还能这么用，厉害了👍

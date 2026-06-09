```java
class Solution {
    public int[][] findContinuousSequence(int target) {
//         List<int[]> L = new ArrayList<>();
//         for(int i=1;i<=target/2;i++){  //开头的数字
//             List<Integer> l = new ArrayList<>();
//             int sum = 0, n = i;
//             while(sum<target){
//                 l.add(n);
//                 sum += n++;
//             }
//             if(sum==target){
//                 L.add(l.stream().mapToInt(Integer::valueOf).toArray());
//             }
//         }
//         return L.toArray(new int[L.size()][]);
//     }
// }

        List<int[]> result = new ArrayList<>();
        int i=1, j=2, sum=1;
        while(i<=target/2){
            if(sum<target){
                sum += j++;
            }else if(sum>target){
                sum -= i++;
            }else{
                int[] arr = new int[j-i];
                for(int k=0;k<j-i;k++) arr[k] = k+i;
                result.add(arr);
                sum -= i++;
            }
        }
        return result.toArray(new int[result.size()][]);
    }
}
```
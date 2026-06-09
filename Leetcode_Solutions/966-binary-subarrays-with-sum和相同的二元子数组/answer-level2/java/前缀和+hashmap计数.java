```
class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
        int[] P = new int[A.length+1];
        for(int i= 0;i<A.length;i++){
            P[i+1] = P[i] + A[i];
        }
        Map<Integer,Integer> map = new HashMap<>();
        int count = 0;
        for(int a : P){
            count += map.getOrDefault(a,0);
            map.put(a+S,map.getOrDefault(a+S,0)+1);
        }
        return count;
    }
}
```
设P[i] = A[0]+……+A[i-1];
那么P[j+1]-P[i] = A[i]+……+A[j];就代表着i到j的所有和，也就是一个子数组的和
只要判断上式=S的个数就可以了
那么我们可以遍历P数组，并找到每个满足P[j] = P[i] + S;并且i<j的i个数
所以采用map，将每个P[j]+S存入到map中，key-P[j]+S，value-个数,这就代表着，每个p[j]+S也就是上式的P[j]的i<j的个数，然后我们在遍历的同时，把所有P[j]的value值取出来加和，就得到了最终结果

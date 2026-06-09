```
class Solution {
    public int game(int[] a, int[] b) {
        Map<Integer,Integer> map = new HashMap<>();
        int count=0;
        for(int i=0; i<a.length; i++){
           map.put(i,a[i]);
        }
        for(int i=0; i<b.length; i++){
            if(b[i] == map.get(i)) count++;
        }
        return count;
    }
}


```





```
class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean> res = new ArrayList<>(A.length);
        int val=0;
        for (int a:A) {
            val=((val<<1)+a)%5;
            res.add(val==0);
        }
        return res;
    }
}
```

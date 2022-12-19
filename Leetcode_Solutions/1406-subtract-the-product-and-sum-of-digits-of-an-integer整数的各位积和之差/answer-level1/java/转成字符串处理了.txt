```
class Solution {

    public int subtractProductAndSum(int n) {
        int ji = 1;
        int he = 0;
        for (char c : String.valueOf(n).toCharArray()) {
            int temp = c - '0';
            ji *= temp;
            he += temp;
        }
        return ji - he;
    }
}
```

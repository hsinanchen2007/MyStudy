```
class Solution {

    private int[] weight;
    private int sum;
    private Random random = new Random();
    
    public Solution(int[] w) {
        this.weight = w;
        int len = w.length;
        
        for(int i = 1; i < len; i++) {
            weight[i] += weight[i-1];
        }
        
        sum = weight[len - 1];
    }
    
    public int pickIndex() {
        int s = random.nextInt(sum);
        int index = Arrays.binarySearch(weight, s + 1);
        if (index < 0) {
            return -index - 1;
        } 
        return index;
    }
}
```

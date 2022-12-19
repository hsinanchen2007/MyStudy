### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {

    private int[] abs = null;
    public Solution(int[] w) {
        abs = new int[w.length];
        for(int i=0; i<w.length; i++){
            if(i==0)
                abs[i] = w[i];
            else
                abs[i] = abs[i-1] + w[i];
        }
    }

    public int pickIndex() {
        double temp = Math.random() * abs[abs.length-1];
        for(int i=0; i<abs.length; i++){
            if(temp < abs[i])
                return i;
        }
        return 0;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
```
```java
class Solution {
    public int[] constructRectangle(int area) {
        int q = (int) Math.sqrt(area);
        while (area % q != 0) q--;
        return new int[]{area / q, q};
    }
}
```
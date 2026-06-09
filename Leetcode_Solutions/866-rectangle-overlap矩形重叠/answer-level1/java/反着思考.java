```
    boolean isRectOut(int[] rec1, int[] rec2) {
        return rec2[1] >= rec1[3] 
            || rec2[3] <= rec1[1] 
            || rec2[2] <= rec1[0] 
            || rec2[0] >= rec1[2];
    }
    
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return !isRectOut(rec1, rec2);
    }
```

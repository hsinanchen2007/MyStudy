```
class Solution {
    public int search(ArrayReader reader, int target) {
        int maxIndex = searchMaxIndex(reader);
        int s = 0, e = maxIndex;
        while(s <= e){
            int m = s + ((e - s) >> 1);
            int val = reader.get(m);
            if(val < target){
                s = m + 1;
            } else if(val > target){
                e = m - 1;
            } else {
                return m;
            }
        }
        return -1;
    }

    private int searchMaxIndex(ArrayReader reader){
        int s = 0, e = 10000;
        while(s <= e){
            int m = s + ((e - s) >> 1);
            if(reader.get(m) == 2147483647){
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return e;
    }
}
```
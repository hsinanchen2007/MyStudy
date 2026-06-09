```
public static int hIndex(int[] citations){
        int j=0;
        int res = -1;
        for(int i=citations.length;i>0;i--){
             if(citations[j]>=i){
                res = i;
                break;
             }
             j++;
        }
        return res;
}
```



```
class Solution {
    public int lastStoneWeight(int[] stones) {
        int[] ss = new int[1001];
        for(int stone: stones){
            ss[stone]++;
        }
        int h=1000,first=0,second=0;
        while(true){
            while(h>0){
                if(ss[h]>0){
                    first=h;
                    ss[h]--;
                    break;
                }
                h--;
            }
            int temp = h;
            while(h>0){
                if(ss[h]>0){
                    second=h;
                    ss[h]--;
                    break;
                }
                h--;
            }
            if(second==0)break;
            ss[first-second] +=1;
            h=temp;
            first=0;
            second=0;
        }
        return first;
    }
}
```

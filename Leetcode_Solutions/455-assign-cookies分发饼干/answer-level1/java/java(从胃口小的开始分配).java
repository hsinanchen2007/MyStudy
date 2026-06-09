```
public int findContentChildren(int[] g, int[] s) {
        public int findContentChildren(int[] g, int[] s) {
            Arrays.sort(g);
            Arrays.sort(s);
            int gIndex,sIndex,count;
            gIndex=sIndex=count=0;
            while(gIndex<g.length&&sIndex<s.length){
                if(s[sIndex]>=g[gIndex]){
                    count++;
                    gIndex++;  
                }
                sIndex++;
            }
            return count;
        }
    }
```

```
public int[] shortestSeq(int[] big, int[] small) {
        int len = small.length;
        Map<Integer, Integer> map = new HashMap();
        for(int i = 0; i < len; i++) {
            map.put(small[i], i);
        }
        
        int[] count = new int[len];
        Set<Integer> set = new HashSet();
        for(int s : small) {
            set.add(s);
        }
        
        int[] res = new int[2];
        int min = Integer.MAX_VALUE;
        
        int i = 0;
        int j = 0;
        int size = 0;
        while(j < big.length) {
            int n = big[j++];
            if (set.contains(n)) {
                int index = map.get(n);
                count[index]++;
                if (count[index] == 1) {
                    size++;
                }
            }
            
            while(size >= len) {
                if (j - i < min) {
                    min = j - i;
                    res[0] = i;
                    res[1] = j - 1;
                }
                
                n = big[i++];
                if (set.contains(n)) {
                    int index = map.get(n);
                    count[index]--;
                    if (count[index] == 0) {
                        size--;
                    }
                }
            }
            
        }
        
        if (min == Integer.MAX_VALUE) {
            return new int[0];
        }
        
        return res;
    }
```

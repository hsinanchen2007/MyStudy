```
public int minJumps(int[] arr) {
        int len = arr.length;
        if (len <= 1) {
            return 0;
        }
        
        if (arr[0] == arr[len - 1]) {
            return 1;
        }
        
        if (len > 5 && arr[0] == arr[len - 2]) {
            return 2;
        }
        
        int res = 0;
        Map<Integer, List<Integer>> map = new HashMap();
        for(int i = 0; i < len; i++) {
            int n = arr[i];
            List<Integer> set = map.get(n);
            if (set == null) {
                set = new ArrayList<Integer>();
                map.put(n, set);
            }
            set.add(i);
        }
        
        boolean[] arr1 = new boolean[len];
        arr1[0] = true;
        Queue<Integer> queue = new LinkedList();
        queue.offer(0);
        
        while(!queue.isEmpty()) {
            res++;
            int size = queue.size();
            for(int i = 0; i < size; i++) {
                int n = queue.poll();
                for(int s : map.get(arr[n])) {
                    if (s == len - 1) {
                        return res;
                    }
                    arr1[s] = true;
                }
                
                int next = n + 1;
                if (next < len && !arr1[next]) {
                    if (next == len - 1) {
                        return res;
                    }
                    arr1[next] = true;
                    queue.offer(next);
                }
                
                next = n - 1;
                if (next >= 0 && !arr1[next]) {
                    if (next == len - 1) {
                        return res;
                    }
                    arr1[next] = true;
                    queue.offer(next);
                }
                
                List<Integer> s = map.get(arr[n]);
                for(int t : s) {
                    if (t == n) {
                        continue;
                    }
                    
                    int n1 = t - 1;
                    if (n1 >= 0 && !arr1[n1]) {
                        queue.offer(t);
                        continue;
                    }
                                        
                    int n2 = t + 1;
                    if (n2 < len && !arr1[n2]) {
                        queue.offer(t);
                        continue;
                    }
                }
            }
        }
        
        return -1;
    }
```

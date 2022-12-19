```
static class DSU {
        int[] parent;
        
        DSU(int n) {
            parent = new int[n];
            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        void union(int x, int y) {
            parent[find(x)] = find(y);
        }
    }
    
    public String[] trulyMostPopular(String[] names, String[] synonyms) {
        int len = names.length;
        String[] name2 = new String[len];
        int[] nums = new int[len];
        Map<String, Integer> indexMap = new HashMap();
        
        for(int i = 0; i < len; i++) {
            String str = names[i];
            int index = str.indexOf("(");
            name2[i] = str.substring(0, index);
            nums[i] = Integer.parseInt(str.substring(index + 1, str.length() - 1));
            indexMap.put(name2[i], i);
        }
        
        DSU dsu = new DSU(len);
        for(String str : synonyms) {
            String[] arr = str.substring(1, str.length() - 1).split(",");
            if (arr.length == 0) {
                continue;
            }
            
            Integer index = null;
            for(int i = 0; i < arr.length; i++) {
                index = indexMap.get(arr[0]);
                if (index != null) {
                    break;
                }
            }
            
            if (index != null) {
                for(int i = 0; i < arr.length; i++) {
                    Integer other = indexMap.get(arr[i]);
                    if (other != null && index != other) {
                        dsu.union(index, other);
                    }
                }
            }
        }
        
        Map<Integer, List<String>> map = new HashMap();
        for(int i = 0; i < len; i++) {
            int root = dsu.find(i);
            List<String> list = map.get(root);
            if (list == null) {
                list = new ArrayList<String>();
                map.put(root, list);
            }
            list.add(name2[i]);
            if (root != i) {
                nums[root] += nums[i];
            }
        }
        
        String[] res = new String[map.size()];
        int index = 0;
        for(int key : map.keySet()) {
            int count = nums[key];
            List<String> list = map.get(key);
            Collections.sort(list);
            StringBuilder sb = new StringBuilder();
            sb.append(list.get(0)).append("(").append(count).append(")");
            res[index++] = sb.toString();
        }
        
        return res;
    }
```

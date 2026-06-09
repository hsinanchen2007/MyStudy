```
public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, LinkedList<Integer>> map = new HashMap<>();
        // 将数组元素作为map的key，将元素添加到集合同时中作为map的value存储在map中
        for (int i = 0; i < nums1.length; i++) {
            if (map.containsKey(nums1[i])){
                LinkedList<Integer> list = map.get(nums1[i]);
                list.add(i);
                map.put(nums1[i], list);
            }else {
                LinkedList<Integer> list = new LinkedList<>();
                list.add(i);
                map.put(nums1[i], list);
            }
        }
        // 将符合的元素添加到集合中
        List<Integer> list = new ArrayList<>();
        for (int j = 0; j < nums2.length; j++) {
            if (map.containsKey(nums2[j])){
                LinkedList<Integer> values = map.get(nums2[j]);
                if (values.size() > 0){
                    list.add(nums2[j]);
                    values.remove();
                }
            }
        }
        // 集合转数组
        int[] res = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            res[i] = list.get(i);
        }
        return res;
    }
```

```
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer,Integer> map = new HashMap<>();
        for (int i = 0;i<arr.length;i++){
            if (map.containsKey(arr[i])){
                Integer value = map.get(arr[i])+1;
                map.put(arr[i],value);
            }else{
                map.put(arr[i],1);
            }
        }
        Set<Integer> set = new HashSet<>();
        for (Map.Entry<Integer,Integer> entry : map.entrySet()){
            if(set.contains(entry.getValue())){
                return false;
            }
            set.add(entry.getValue());
        }
        return true;
    }
}
```

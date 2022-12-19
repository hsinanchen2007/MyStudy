```
class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] arr=str.split(" ");
        if(pattern.length()!=arr.length) return false;
        // 将a-dog作为key-value映射到hash表中
        Map<Character,String> hashmap=new HashMap<>();
        int num=0;
        for(int i=0;i<arr.length;i++){
            // 如果键不存在，那就加入到hash表中
            if(!(hashmap.containsKey(pattern.charAt(i)))){
                // 但值得注意的情况是 键不存在，但值存在，这就错了，
                if(hashmap.containsValue(arr[i])) return false;
                hashmap.put(pattern.charAt(i),arr[i]);
            }else{
                // 键存在的情况下，如果该键对应的值不能与当前值匹配的话，那也错了
                if(!hashmap.get(pattern.charAt(i)).equals(arr[i])) return false;
            }
        }
        return true;
    }
}
```

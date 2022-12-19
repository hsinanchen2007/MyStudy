慢的一批，但是能过。。

```
    // Str1_Str2 -- their distances
    Map<String, Integer> cache = new HashMap<>();

    public boolean isOneEditDistance2(String s, String t) {
        return distance(s, t) == 1;
    }

    private int distance(String s, String t) {
        //s must be shorter than t
        if (s.length() > t.length()) {
            String temp = s;
            s = t;
            t = temp;
        }

        String key = s + "-" + t;
        if (cache.containsKey(key)) return cache.get(key);

        if (s.isEmpty()) {
            cache.put(key, t.isEmpty() ? 0 : 1);
            return cache.get(key);
        }

        int lengthDiff = t.length() - s.length();
        if (lengthDiff > 1) {
            cache.put(key, lengthDiff);//return a distance greater than 2 is already enough for this problem
            return lengthDiff;
        } else if(lengthDiff == 1){
            if (s.charAt(0) == t.charAt(0)) {
                return distance(s.substring(1), t.substring(1));
            } else{
                return 1+distance(s,t.substring(1));//delete the first char of t and continue
            }
        } else if(lengthDiff == 0){
            if (s.charAt(0) == t.charAt(0)) {
                return distance(s.substring(1), t.substring(1));
            } else{
                return 1+distance(s.substring(1), t.substring(1));
            }
        } else{ //Never reach because s is shorted than t
            return -1;
        }
    
```

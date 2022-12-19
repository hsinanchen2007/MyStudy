```
class Solution {
    public boolean confusingNumber(int N) {
        String n = N + "";
        for (int i = 0; i < n.length(); i++) {
            String m = "23457";
            if (m.contains(n.substring(i, i + 1))) {
                return false;
            }
        }
        
        for (int j = 0; j < n.length(); j++) {
            String start = n.substring(j, j + 1);
            String end = "";
            if (n.length()-j == n.length()) {
                end += n.substring(n.length()-j-1);
            } else {
                end += n.substring(n.length()-j-1, n.length()-j);
            }
            if ("6".equals(start) && !"9".equals(end)) {
                return true;
            }
            if ("9".equals(start) && !"6".equals(end)) {
                return true;
            }
            if (!"9".equals(start) && !"6".equals(start) && !end.equals(start)) {
                return true;
            }
        }   
        return false;    
    }
}
```

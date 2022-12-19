```
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;
class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> list = new ArrayList<>();
        StringBuilder str = new StringBuilder();
        for (int i=0; i<pattern.length(); i++) {
            str.append(String.valueOf(pattern.charAt(i)));
            str.append("[a-z]*");
        }
        String regex = "[a-z]*" + str.toString() + "$";
        
        Pattern pattern2 = Pattern.compile(regex);

        for (int i=0; i<queries.length;i++) {
            Pattern pattern1 = Pattern.compile(regex);
            list.add(pattern1.matcher(queries[i]).lookingAt());
        }
        return list;
    }
}
```
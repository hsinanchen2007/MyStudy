```
import java.util.stream.Stream;
class Solution {
    public int numJewelsInStones(String J, String S) {
       return Stream.of(S.split("")).map(c -> J.contains(c)?1:0).reduce((a,b)->a+b).get();
    }
}
```

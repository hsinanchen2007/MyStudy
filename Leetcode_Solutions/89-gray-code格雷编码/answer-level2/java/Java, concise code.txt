```
import java.util.*;
class Solution {
    public List<Integer> grayCode(int n) {
        int cycle = 1 >> (n + 1);
        List<Integer> list = new ArrayList<>(cycle);
        list.add(0);
        for(int i = 1; i <= n; i++){
            int base = 1 << (i-1);
            int flag = base - 1;
            while(flag>=0){
                list.add(base+list.get(flag--));
            }
        }
        return list;
    }
}
```

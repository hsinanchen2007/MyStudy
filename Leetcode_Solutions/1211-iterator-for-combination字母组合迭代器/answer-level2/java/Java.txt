```java
import java.util.ArrayList;
import java.util.List;

class CombinationIterator{
    List<List<Character>> res = new ArrayList<>();
    int index = 0;
    public CombinationIterator(String characters, int combinationLength) {
        char[] chars = new char[characters.length()];
        for (int i = 0; i < characters.length(); i++) {
            chars[i] = characters.charAt(i);
        }
        backtrace(res, new ArrayList<>(), chars, 0,combinationLength);
        System.out.println(res);
    }
    
    public String next() {
        StringBuilder sb = new StringBuilder();
        for(char a: res.get(index)){
            sb.append(a);
        }
        index++;
        return sb.toString();
    }

    public boolean hasNext() {
        if (index == res.size()) {
            return false;
        }
        return true;
    }

    public void backtrace(List<List<Character>> res, List<Character> cur, char[] nums, int index, int limit){
        if(cur.size() == limit){
            res.add(new ArrayList<>(cur));
            return;
        }
        for(int i = index; i < nums.length; i++){
            cur.add(nums[i]);
            backtrace(res,cur, nums, i + 1, limit);
            cur.remove(cur.size() - 1);
        }
    }
}
```

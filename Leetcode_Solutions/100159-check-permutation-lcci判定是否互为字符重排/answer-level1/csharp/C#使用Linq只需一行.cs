只要是简单遍历就大胆使用Linq吧，速度比想像中的快
```
public class Solution {
    public bool CheckPermutation(string s1, string s2) {
      return s1.OrderBy(c => c).SequenceEqual(s2.OrderBy(c => c));
    }
}
```

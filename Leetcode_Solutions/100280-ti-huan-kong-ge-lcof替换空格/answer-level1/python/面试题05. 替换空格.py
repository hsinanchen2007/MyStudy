```java []
class Solution {
    public String replaceSpace(String s) {
        String newString = s.replaceAll(" ", "%20");
        return newString;
    }
}
```
```python []
class Solution:
    def replaceSpace(self, s: str) -> str:
        newString = s.replace(' ', '%20')
        return newString
```

```java
class Solution {
    public boolean checkRecord(String s) {
        // 查找A的个数如果>=2 || s是否包含LLL 返回false
        return (s.indexOf('A') != s.lastIndexOf('A') || s.contains("LLL")) ? false: true;
    }
}```
```java
class Solution {
    public String largestNumber(int[] nums) {
        String res = Arrays.stream(nums).mapToObj(String::valueOf).sorted((a, b) -> {
            String s1 = a + b;
            String s2 = b + a;
            return s2.compareTo(s1);
        }).collect(Collectors.joining(""));
        int i;
        for(i=0;i<res.length();i++)
            if(res.charAt(i)!='0')
                break;
        return res.substring(i).length() == 0 ? "0" : res.substring(i);
    }
}
```
如果不用判断0可以一行搞定
```java
class Solution {
    public String largestNumber(int[] nums) {
        return Arrays.stream(nums).mapToObj(String::valueOf).sorted((a, b) -> {
            String s1 = a + b;
            String s2 = b + a;
            return s2.compareTo(s1);
        }).collect(Collectors.joining(""));
    }
}
```
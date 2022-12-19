```java []
class Solution {
    public String largestNumber(int[] nums) {
        List<String> list = new ArrayList<String>();
        Arrays.stream(nums).forEach(e -> list.add(String.valueOf(e)));
        list.sort((o1,o2)->(o2+o1).compareTo(o1+o2));
        StringBuilder res = new StringBuilder();
        list.stream().forEach(s -> res.append(s));
        if(res.toString().indexOf('0')==0) return "0";
        return res.toString();
    }
}
```


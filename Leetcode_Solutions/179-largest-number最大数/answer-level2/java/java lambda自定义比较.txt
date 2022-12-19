

### 代码

```java
class Solution {
 private String[] strings;
    private String string;
    public String largestNumber(int[] nums) {
        strings=new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            strings[i]=Integer.toString(nums[i]);
        }
        Arrays.sort(strings, (x,y)->(y+x).compareTo(x+y));//lambda自定义比较
        string=new String();
        for (String s:strings
             ) {
            string+=s;
        }
        return strings[0].equals("0")?"0":string;
    }
}
```
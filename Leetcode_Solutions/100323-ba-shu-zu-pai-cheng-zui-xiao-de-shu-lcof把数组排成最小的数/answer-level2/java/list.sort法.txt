### 解题思路
精髓：list.sort((o1,o2)->(o1+o2).compareTo(o2+o1));

### 代码

```java
class Solution {
    public String minNumber(int[] nums) {
        ArrayList<String> list = new ArrayList<>();
        for(int num:nums){
            list.add(String.valueOf(num));
        }
        //进行String升序排序,o2为后值,o1为前值
        list.sort((o1,o2)->(o1+o2).compareTo(o2+o1));
        StringBuilder sb = new StringBuilder();
        for(String s : list){
            sb.append(s);
        }
        return String.valueOf(sb);
    }
}
```
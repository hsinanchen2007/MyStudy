### 解题思路
把数组排成最小的数，通过list，进行排序，然后将其按照从小到大的顺序连接起来即可；
### 代码

```java
class Solution {
    public String minNumber(int[] nums) {
        if(nums==null||nums.length==0) return " ";
        List<String> list = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            list.add(String.valueOf(nums[i]));
        }
        list.sort((o1,o2)->(o1+o2).compareTo(o2+o1));
        String s = "";
        for(String str:list){
            s+=str;
        }
        return s;
    }
}
```
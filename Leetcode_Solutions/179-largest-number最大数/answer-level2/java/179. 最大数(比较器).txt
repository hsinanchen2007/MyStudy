### 解题思路
需要注意的是：当都为0时，输出0;
String.valueOf(nums[i])  是整型转字符串
### 代码

```java
class Solution {
    public String largestNumber(int[] nums) {
        int n = nums.length;
        String[] strs = new String[n];
        for(int i = 0; i < n; i++){
            strs[i] = String.valueOf(nums[i]);
        }
        //o2在前是从大到小
        Arrays.sort(strs, new Comparator<String>(){
            @Override
            public int compare(String o1, String o2){
                return (o2 + o1).compareTo(o1 + o2);
            }
        });

        StringBuilder sb = new StringBuilder();
        for(String num : strs){
            sb.append(num);
        }
        String res = sb.toString();
        int index = 0;
        while(index < res.length() && res.charAt(index) == '0'){
            index++;
        }
        if(index == res.length()){
            return "0";
        }
        return res;
     }
}
```
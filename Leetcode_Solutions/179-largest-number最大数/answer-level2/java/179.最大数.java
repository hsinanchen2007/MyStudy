### 解题思路
1.排序
2.连接
3.特殊情况排除
（排序重写是从评论里学的）

### 代码

```java
class Solution {
    public String largestNumber(int[] nums) {
        if(nums == null || nums.length == 0) return "";
        String[] strArr = new String[nums.length];
        for(int i=0;i<strArr.length;i++){
            strArr[i] = String.valueOf(nums[i]);
        }
        Arrays.sort(strArr,new Comparator<String>(){
            @Override
            public int compare(String o1,String o2){
                return (o2+o1).compareTo((o1+o2));
            }
        });
        StringBuilder res = new StringBuilder();
        for(String str :strArr){
            res.append(str);
        }
        String ans = res.toString();
        if(ans.charAt(0)=='0'){
            ans = "0";
        }
        return ans;
    }
}
```
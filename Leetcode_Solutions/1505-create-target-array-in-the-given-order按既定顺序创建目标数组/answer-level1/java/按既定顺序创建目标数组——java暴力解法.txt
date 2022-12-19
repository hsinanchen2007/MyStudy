### 解题思路
此处撰写解题思路
考虑到数组nums要按index插入到数组target
个人认为用字符串会比较方便
首先按题目要求构建字符串str
之后吧字符串转化成目标数组target

### 代码

```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int len = nums.length;

       int[] target = new int[len];
        String str = String.valueOf(nums[0]);
        int str_len = 1;
        for(int i=1;i<len;i++){
            String[] help = str.split(",");
            str_len = help.length;
            str = "";
            for(int j=0;j<index[i];j++){
                str += help[j] + ",";
            }
            str += nums[i] + ",";
            for(int k=index[i];k<str_len;k++){
                str += help[k] + ",";
            }
            str_len = str.length();
            if(str.charAt(str_len-1)==','){
                str=str.substring(0,str_len-1);
            }
        }
        String[] help = str.split(",");
        str_len = help.length;
        for(int i=0;i<str_len;i++){
            target[i] = Integer.valueOf(help[i]);
        }
       return target;
    }
}
```
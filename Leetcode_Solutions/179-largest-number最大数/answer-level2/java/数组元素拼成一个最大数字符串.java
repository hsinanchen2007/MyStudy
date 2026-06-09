### 解题思路
主要是现将整型数组转化为字符串数组，因为字符串可以拼接，比较拼接大小，使用冒泡排序对需要交换位置的子元素字符串进行交换，当数组全为0和空数组时需要单独列出来，其他情况将字符串数组的每个子串拼成整个串

### 代码

```java
class Solution {
    public String largestNumber(int[] nums) {
        if(nums.length < 1) return "";//鲁棒性
        String[] str = new String[nums.length];//创建同样长度的字符串数组
        for(int i = 0; i < nums.length; i++){
            str[i] = String.valueOf(nums[i]);//将整型数组转化为字符串数组
        }
        // String s;
        for(int i = 0; i < str.length; i++){
            for(int j = i + 1; j < str.length; j++){
                if((str[i] + str[j]).compareTo(str[j] + str[i]) < 0){
                    String s = str[i];
                    str[i] = str[j];
                    str[j] = s;
                }
            }
        }
        if(str[0].equals("0")){//数组元素全为0,结果为0不是多个0
            return "0";
        }else{
            return String.join("", str);
        } 
        //String ans = "";
        // for(int i = 0; i < str.length; i++){
        //     ans += str[i];
        // }
        // return ans;
    }
}
```
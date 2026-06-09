### 解题思路
此处撰写解题思路
我太南了，
![image.png](https://pic.leetcode-cn.com/f5aca8472dce8c7f27e666b0b0cdc225434fc1b8f3b5b41aa01ec51b4b11ca45-image.png)

### 代码

```java
class Solution {
    public List<String> printVertically(String s) {

        List<String> str_return = new ArrayList<>();
        //分割字符串
        String[] str = s.split(" ");

        //获取最大的长度单词长度；
        int[] length_arr = new int[str.length];
            for (int i = 0; i <length_arr.length ; i++) {

                length_arr[i] = str[i].length();
            }
            Arrays.sort(length_arr);

            int max_length = length_arr[length_arr.length - 1];



        //创需要返回的竖直字符串数组
        String[] str2 = new String[max_length];


        //有多长就数组有多大
        for(int i = 1; i <= max_length; i++){


            StringBuilder sb = new StringBuilder();
            for(int j = 0; j < str.length; j++){
                //如果遍历到的字符串的长度小于最大字符串的长度（或者当前行数）
                if(str[j].length()  < i){
                    sb.append(" ");
                    //填充空格
                }else{
                
                sb.append(str[j].charAt(i-1));
                
                }
                
            }

            //菜鸟法去除末端空格，找到最后一个非空字符，然后再找这个字符的索引，再切割字符，得到最后一个非空字符前所有的字符
            String str_mid1 = sb.toString();
            String str_mid2 = str_mid1.trim();
            char last_char = str_mid2.charAt(str_mid2.length() - 1);
            int index_last = str_mid1.lastIndexOf(last_char);
            String fin_str = str_mid1.substring(0,index_last+1);


            str_return.add(fin_str);

        }
        return str_return;
        

    }
}
```
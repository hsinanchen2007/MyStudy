```
class Solution {
    public int myAtoi(String str) {
        String newStr = "";
        //去除前空格
        for(int i = 0; i < str.length(); i++){
            if (!(str.charAt(i) == ' ')) {
                newStr = str.substring(i); 
                break;
            } 
        }

        char[] arr = newStr.toCharArray();
        int symbol = 1; //保存结果的符号
        long num = 0;

        for (int i = 0; i < arr.length; i++){
            if(i == 0){
                if (arr[0] == '+' || arr[0] == '-') {
                    symbol = (arr[0] == '+' ? 1 : -1);

                } else if (arr[0] - '0' < 0 || arr[0] - '0' > 9) {
                    return 0;
                } else {
                    num += arr[0] - '0';
                }
            } else {
                //开始进行数字的计算
                if (arr[i] - '0' >= 0 && arr[i] - '0' <= 9) {
                    num = num * 10 + arr[i] - '0';

                    //如果超过int的数值范围，直接返回
                    if (num * symbol > Integer.MAX_VALUE)   return Integer.MAX_VALUE;
                    if (num * symbol < Integer.MIN_VALUE)   return Integer.MIN_VALUE;
                } else {
                    break;
                }

            }
            

        }

        return (int)num * symbol;
    }
}
```
    当然，在判断越界的时候直接把运算放到右侧，用int也可以的

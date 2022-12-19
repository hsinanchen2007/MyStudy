n=1,输出1
n=2,数上次字符串中数值个数，1个1,输出11
n=3,数上次字符串中数值个数，2个1,输出21
n=4,数上次字符串中数值个数，1个2,1个1,输出1211
以此类推，1，11，21，1211，111221，312211，13112221，1113213211
```
class Solution {
   public String countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        String pre = "1";
        for (int i = 2; i <= n; i++) {
            pre = getNext(pre);
        }
        return pre;
    }

    private String getNext(String str){
        str += "0";//只是为了方便后面的判断
        StringBuilder result = new StringBuilder();
        int count = 1;
        for (int i = 1; i < str.length(); i++) {
            if(str.charAt(i) == str.charAt(i - 1)){
                count++;
            }else{
                result.append(count);
                result.append(str.charAt(i - 1));
                count = 1;
            }
        }
        return result.toString();
    }
}
```

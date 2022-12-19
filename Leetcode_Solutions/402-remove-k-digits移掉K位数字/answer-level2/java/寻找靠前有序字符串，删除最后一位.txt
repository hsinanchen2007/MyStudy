迭代删除数，每次找到前面有序的字符串最后一位下标。删除这次找到下标的字符，重新拼接字符串。最后统一处理前缀为0，有可能连续有多个0，需要迭代删除。
```
class Solution {
    public String removeKdigits(String num, int k) {
       int length = num.length();
        if(length == k){
            return "0";
        }
        if(k==0){
            return detele(num);
        }
        for (int j = 0; j < k; j++) {
            int check = check(num, 0);
            num = num.substring(0,check) + num.substring(check+1,num.length());
        }
        return detele(num);
    }

    private static String detele(String result) {
        int length = result.length();
        for (int i = 0; i < length; i++) {
            if(result.startsWith("0")){
                result = result.substring(1,result.length());
            }
        }
        if(result == null || result.equals("")){
            result = "0";
        }
        return result;
    }

    private static int check(String num,int count) {
        if(count == num.length() -1){
            return count;
        }
        if(num.charAt(count) > num.charAt(count + 1)){
            return count;
        }else {
            return check(num,count+1);
        }
    }
}
```

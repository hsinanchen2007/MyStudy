```
class Solution {
    //优先判断参数正负，再将int转换成string类型，再进行倒序，最终将string类型转换为int类型，输出
    public int reverse(int x) {
        int y = x;
        if(y < 0){
            y *= (-1);
        }
        String str = String.valueOf(y);
        char[] ch = str.toCharArray();
        str = "";
        for(int i = ch.length-1;i>=0;i--){
            str += ch[i]; 
        }
        try{
            int result = Integer.parseInt(str,10);
            if(x < 0){
                return result*(-1);
            }else{
                return result;
            }
        }catch(Exception e){
            return 0;
        }
    }
}
```

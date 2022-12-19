```
class Solution {
    public int romanToInt(String s) {
        char[] chars = s.toCharArray();
        int res = 0;
        int i = 0;
        for(i=0;i<chars.length-1;i++){
            if(getStrToInt(chars[i]) >= getStrToInt(chars[i+1])){ // 判断当前位置和当前下一个位置
                res += getStrToInt(chars[i]);  // 小于则是减去
            }else{
                res -= getStrToInt(chars[i]);  // 大于则是加上
            }
        }
        res += getStrToInt(chars[i]);  //最后一位不管是大于还是小于倒数第二位，始终都是加上最后一位
        return res;
    }
    private int getStrToInt(char c){
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return 0;
        }
    }
}
```

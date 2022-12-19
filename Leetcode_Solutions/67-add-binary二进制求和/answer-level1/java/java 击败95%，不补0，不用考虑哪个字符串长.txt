思想：用car计算上一次计算是否有进位
      count计算两个字符串中对应数字相加的结果，如果长度不等导致只剩一个字符串了，也没有影响。
      需要注意的是最后，是否需要对最高位进位。




class Solution {
    public String addBinary(String a, String b) {
        int car = 0;
        StringBuilder build = new StringBuilder();
        for(int i = 1; i <= a.length() || i <= b.length(); i++){
            int count = 0;
            if(i <= a.length() && a.charAt(a.length()-i) == '1') count++;
            if(i <= b.length() && b.charAt(b.length()-i) == '1') count++;
            build.insert(0,(count+car)%2);
            car = ( count + car )/2;
        }
        if(car == 1) build.insert(0,car); //最后是否需要进位，需要做考虑
        return build.toString();
    }
}
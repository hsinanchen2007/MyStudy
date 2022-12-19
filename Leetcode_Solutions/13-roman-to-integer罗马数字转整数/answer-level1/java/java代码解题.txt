### 解题思路
    首先确定两个数组  将可能的罗马数字组合和对应的数字对应起来。  然后判断特殊情况，比如给的字符长度<2，这里面还可以分两种情况，①空字符串和②长度为1。  空字符串返回0，字符串为1，去roman数组里面匹配。
    字符串长度大于3的时候，每次取得roman数组的一个字符，先取得它的长度，到s里面去跟对应长度的子字符串进行匹配，成功的话，result就加上对应的数值。 
    当然  不用考虑溢出，因为罗马数字最大也才3999

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        int result = 0;
        String[] roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int[] nums = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

        if(s.length() < 2) {
            if(s.equals(""))
                result = 0;
            else{
                for(int i = 0; i < 13; i++){
                    if(s.equals(roman[i]))
                        result += nums[i];
                }
            }
        }else{
            int temp = 0;
            //字符串每次计算的起始位置
            int start = 0;
            int end = 0;
            while(temp < 13){
                int length = roman[temp].length();
                //每次的end应该是在start的基础上加上 roman数组取出字符的长度
                end = start + length;
                //当end 大于 s.length时，说明s已经被全部转换为int了
                while(end <= s.length() && s.substring(start, end).equals(roman[temp]) ){
                    result += nums[temp];
                    start += length;
                    end += length;
                }
                temp++;    
            }
        }
        return result;
    }
}
```
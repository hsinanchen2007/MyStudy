![捕获.JPG](https://pic.leetcode-cn.com/f5b46c067481b84756d2ea0879ffcecb23ef76bb9070e734ede501a3eb2bfcbd-%E6%8D%95%E8%8E%B7.JPG)
解决步骤：
    先处理掉前面的空格及符号位，将可能存在的纯数字序列进行处理。
    对于数字的越界问题 我使用了long类型，但是这题可能会出现long类型也越界的情况，
    因此得到一整串数纯数字串(祛除前面的连0串)时，先判断其长度 是否大于10，大于10时坑定越界的。
    之后的判断可采用long类型的val和Integer.MAX_VALUE和Integer.MIN_VALUE比较.
```
class Solution {
    public int myAtoi(String str) {
        //删除前面的空字符串
        int start = 0;
        while(start < str.length() && str.charAt(start) == ' '){
            start++;
        }
        if(start == str.length()){
            return 0;
        }
        long val = 0;
        if(str.charAt(start) == '-' || str.charAt(start) == '+'){
            val = process(str, start + 1);
        }else{
            val = process(str, start);
        }
        if(val == -1){//越界了
            return str.charAt(start) == '-' ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        }
        val = str.charAt(start) == '-' ? -1 * val : val;
        return (int)val;
    }
    //数字判断
    public long process(String str, int start){
        //删除前面的0
        while(start < str.length() && (str.charAt(start) == '0')){
            start++;
        }
        if(start >= str.length() || str.charAt(start) > '9' || str.charAt(start) < '0'){
            return 0;
        }
        long val = 0;
        int end = start;
        while(end + 1 < str.length() && str.charAt(end + 1) >= '0' && str.charAt(end + 1) <= '9'){
            end++;
        }
        //此时[start, end]为纯数字
        if(end - start + 1 > 10){
            return -1;//证明越界了
        }
        while(start <= end){
            val = val * 10 + (str.charAt(start++) - '0');
        }
        if(val > Integer.MAX_VALUE){
            return -1;//越界
        }
        return val;
    }
}
```

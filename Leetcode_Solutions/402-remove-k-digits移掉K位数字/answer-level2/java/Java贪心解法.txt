```
class Solution {
    public String removeKdigits(String num, int k) {
        //每次都移除峰值，共移除k次，返回结果值即可
        while(k>0){
            int index = num.length()-1;
            //找到第一个num[i]>num[i+1]
            for(int i=0; i<num.length()-1; i++)
                if(num.charAt(i)>num.charAt(i+1)){ index = i; break; }
            num = num.substring(0,index).concat(num.substring(index+1));
            //如果字符串一直升序，则index == num.length()-1,则移除index
            k--;
        }
        while(num.length()>0 && num.charAt(0)=='0'){
            num = num.substring(1);
        }
        return ("".equals(num))?"0":num;
    }
}
```

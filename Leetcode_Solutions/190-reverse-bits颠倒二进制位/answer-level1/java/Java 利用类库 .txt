```
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        String binaryString = Integer.toBinaryString(n);//将int转化为二进制字符串
        int length = binaryString.length();
        StringBuilder sb = new StringBuilder();
        //对不够32位的二进制进行补齐
        if(length<32){
           int dis = 32 - length;
           for(int i=0;i<dis;i++){
               sb.append('0');
           }
        }
        sb.append(binaryString);//获取32位的二进制字符串
        String result = sb.reverse().toString();//将二进制字符串反转
        int reverse =Integer.parseUnsignedInt(result,2);//将二进制字符串转化为十进制
        return reverse;
    }
}
```
![QQ截图20200408223507.png](https://pic.leetcode-cn.com/4ca49cfbe99f4ffaf4fd40f94ca4ee41337a21a1fe4855141bb2f111f5695e8a-QQ%E6%88%AA%E5%9B%BE20200408223507.png)



### 解题思路
代码比较简单，就是很难用文字描述
![WechatIMG5.jpeg](https://pic.leetcode-cn.com/7eba9bc5d2c74ee97f43052ebe7876225764d48d99c991ca394e3d2d59d7dbc3-WechatIMG5.jpeg)




### 代码

```java
class Solution {
    public int findNthDigit(int n) {
        long low = 0;
        long high = 0;
        for(int i=1;;i++){
            low = high+1;
            high = (long)Math.pow(10,i-1) * 9*i+low - 1;
            if(n>=low && n<=high){
                long numNo = ((long)n-low)/i;//表示落在区间的第几个数上
                long numIndex = (n-low)%i;//表示落在数字的第几位上
                long num = (int)Math.pow(10,i-1)+numNo;
                return Integer.valueOf(String.valueOf(num).substring((int)numIndex,(int)numIndex+1));
            }
        }
    }
}
```
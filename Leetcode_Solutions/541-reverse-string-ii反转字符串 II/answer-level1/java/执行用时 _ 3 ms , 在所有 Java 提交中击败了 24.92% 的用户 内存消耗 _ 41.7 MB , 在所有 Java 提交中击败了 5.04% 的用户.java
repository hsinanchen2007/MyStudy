### 解题思路
本来是想针对索引下手，但是中间出错实在太多，索性把给定字符串以2*k为一组进行拆分，分别对每一组的字符串进行翻转，最后一组进行判断，如果小于k，则全部翻转，否则翻转前k个字符，并把翻转后的字符串全部相加得到一个新的字符串，避免受到下标的影响和困扰。本解法程序较长，但易于理解。

### 代码

```java
class Solution {
    public String reverseStr(String s, int k) {
        int length = s.length();
        char[] arr = s.toCharArray();
        if(length<2*k && length>=k) {
            char temp = '0';
            for(int i = 0;i<k/2;i++) {
                temp = arr[i];
                arr[i] = arr[k-i-1];
                arr[k-i-1] = temp;
            }
        }
        if(length<k) {
            char temp = '0';
            for(int i = 0;i<length/2;i++) {
                temp = arr[i];
                arr[i] = arr[length-i-1];
                arr[length-i-1] = temp;
            }
        }
        int count = length/(2*k);
        int i = 0;
        String ss = "";
        for(i=0;i<count;i++) {
            char[] brr = s.substring(i*2*k,i*2*k+2*k).toCharArray();
            char temp = '0';
            for(int j=0;j<k/2;j++) {
                temp = brr[j];
                brr[j] = brr[k-j-1];
                brr[k-j-1] = temp;
            }
            ss = ss+new String(brr); 
        }
        if(length-count*2*k<k) {
            char[] brr = s.substring(count*2*k,length).toCharArray();
            char temp = '0';
            for(int j = 0;j<(length-count*2*k)/2;j++) {
                temp = brr[j];
                brr[j] = brr[length-count*2*k-j-1];
                brr[length-count*2*k-j-1] = temp;
            }
            ss = ss+new String(brr);
        }
        if(length-count*2*k>=k && length-count*2*k<2*k) {
            char[] brr = s.substring(count*2*k,length).toCharArray();
            char temp = '0';
            for(int j=0;j<k/2;j++) {
                temp = brr[j];
                brr[j] = brr[k-j-1];
                brr[k-j-1] = temp;
            }
            ss = ss+new String(brr);
        }
        return ss;
    }
}
```
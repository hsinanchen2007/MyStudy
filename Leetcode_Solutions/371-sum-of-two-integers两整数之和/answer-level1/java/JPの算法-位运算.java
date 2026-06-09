![WeChat Image_20191009161537.jpg](https://pic.leetcode-cn.com/803972384a0619a5d94497c117c0036d3ead61739ffa7f3a32c318b83808a09f-WeChat%20Image_20191009161537.jpg)


```
class Solution {
    public int getSum(int a, int b) {
         //进位不为0 (还需要进位则继续)
        while(b!=0){
            //进位(给b)
            int jin = (a&b)<<1;
            //相加位(给a)
            a = a^b;
            b = jin;
        }
        return a;
    }
}
```

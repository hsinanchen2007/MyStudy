```
class Solution {
public static String countAndSay(int n) {
        String str,res;// res 存放最终返回的结果，str存放中间结果，也就是上一轮的结果
        res="1";//初始化第一轮的结果
        for(int i=1;i<n;i++){//遍历n
            str=res;
            res="";
            for(int j=0;j<str.length();){//遍历中间结果的长度
                int c=0,k=j; //c用来记录有多少重复的，k是重复的元素，以k的速度递增，也即是j增加，使得循环能继续
                while(k<str.length()&&str.charAt(k)==str.charAt(j)){
                    k++;
                    c++;
                }
                res+= String.valueOf(c)+str.charAt(j);//存放返回的结果
                j=k;
            }
        }
        return res;
    }
}
```


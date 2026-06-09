用一个数组roman[]将各个Ronam数大到小存起来，再用一个数组n[]将Roman数对应的整数存起来。
描述起来麻烦，看代码很好理解。
对于特殊情况说一下，特殊情况是在判断到小于n[]中元素后才有可能出现，分两种情况：
1. 位于n的偶数下标，观察一下，偶数坐标对应的是：1000，100，10，1。特殊规则的900，90，9分别对应偶数坐标元素*0.9。
2. 位于n的奇数下标，观察一下，奇数坐标对应的是：500，50，5。特殊规则的400，40，4分别对应偶数坐标元素*0.8。
```
class Solution {
    public String intToRoman(int num) {
        String res="",roman="MDCLXVI";
        int[] n={1000,500,100,50,10,5,1};
        int len=roman.length();
        for(int i=num;i>0;)
            for(int j=0;j<len;){
                if(i>=n[j]){
                    res+=roman.charAt(j);
                    i-=n[j];
                }
                else if(j%2==0&&j+2<len&&(i>=(n[j]*0.9))){//特殊情况一
                    res+=String.valueOf(roman.charAt(j+2))+String.valueOf(roman.charAt(j));
                    i-=n[j]*0.9;
                }
                else if(j%2==1&&j+1<len&&(i>=(n[j]*0.8))){//特殊情况二
                    res+=String.valueOf(roman.charAt(j+1))+String.valueOf(roman.charAt(j));
                    i-=n[j]*0.8;
                }
                else j++;
            }
        return res;
    }
}
```

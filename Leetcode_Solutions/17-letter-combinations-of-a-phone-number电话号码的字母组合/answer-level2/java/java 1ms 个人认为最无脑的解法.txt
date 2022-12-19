### 解题思路
java 1ms答案
先计算出一共有多少个(num个)字符串并生成这些空串(StringBuilder),然后遍历数字序列,对于每个数字都遍历一次所有字符串,在字符串末尾添加一个字母.
currnum初始化为num,对于每个数字,currnum/=3或4.当遍历到第j个字符串,j可被currnum除尽时,向字符串末尾添加的字母变为按键的下一个字母(已经是最后一个字母则为第一个字母),这里用p作为指针.
### 代码

```java
class Solution {
    public List<String> letterCombinations(String digits) {
        int len=digits.length();
        List<String> res=new ArrayList<>();
        if(0==len){
            return res;
        }
        String [] strmap={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        int num=1;
        for(int i=0;i<len;i++){
            num*=((digits.toCharArray()[i])=='7'||(digits.toCharArray()[i])=='9')?4:3;
        }
        List<StringBuilder> builders = new ArrayList<>();
        for(int i=0;i<num;i++){
            StringBuilder temp =new StringBuilder();
            builders.add(temp);
        }
        int currnum=num;
        for(int i=0;i<len;i++){
            int ch= digits.charAt(i)-50;
            int currLen;
            if(ch==5||ch==7)
                currLen= 4;
            else
               currLen=3;
            currnum/=currLen;
            int p=0;//指针
            for(int j=0;j<num;j++){
                if((j+1)%currnum==0)
                    if(p<currLen-1){
                        p++;
                    }
                    else{
                        p=0;
                    }
                builders.get(j).append(strmap[ch].charAt(p));
            }
        }
        for(int i=0;i<num;i++){
            res.add(builders.get(i).toString());
        }
        return res;
    }
}
```
### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     public int compress(char[] chars) {
        int len =chars.length;
        //长度为1，直接返回
        if(len==1){
            return 1;
        }
        char c1=chars[0];
        char c2=chars[0];
        //sum，相同字符的个数
        int sum=1;
        //最终返回的长度
        int length=1;
        //返回数组在调整时候的下标
        int index=1;
        for(int i=1;i<len;i++){
            c2=chars[i];
            if(c2==c1){
                sum++;
            }else{
                if(sum!=1){
                    String sumStr=String.valueOf(sum);
                    length+=sumStr.length();
                    char[] cs=sumStr.toCharArray();
                    for(int j=0;j<cs.length;j++){
                        chars[index++]=cs[j];
                    }
                }
                sum=1;
                length++;
                c1=c2;
                chars[index++]=c2;
            }


        }
        //最后的收尾
        if(sum!=1){
            String sumStr=String.valueOf(sum);
            length+=sumStr.length();
            char[] cs=sumStr.toCharArray();
            for(int j=0;j<cs.length;j++){
                chars[index++]=cs[j];
            }
        }

        return length;
    }

}
```
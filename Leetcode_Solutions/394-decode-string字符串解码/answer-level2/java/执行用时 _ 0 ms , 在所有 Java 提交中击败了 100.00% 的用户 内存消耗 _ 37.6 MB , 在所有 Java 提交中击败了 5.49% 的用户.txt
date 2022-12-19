1. 分三部分来拼接字符串， part1:第一个k[encodeString]之前的内容, part2:第一个k[encodeString],part3:第一个k[encodeString]之后的内容.
2. part1 : 用sb来拼接字符串， 对于第一部分来说， 就是indexOf('[') 之前的内容(需要排除数字到tsb,tsb用于获取k值)
3. part2 : 用part1 得到的k值 递归叠加 decodeString(encodeString)
4. part3 : sb拼接 剩余的部分的decodeString;
2

### 代码

```java
class Solution {
    public String decodeString(String s) {
        
        int l = s.indexOf('[');
        if(l==-1){
            return s;
        }
        int lc = 1,rc=0;
        //总体的字符拼接sb
        StringBuilder sb  = new StringBuilder();
        //用于获取k值得tsb
        StringBuilder tsb  = new StringBuilder();

        //分离part1和k值.
        for(int p = 0; p<l;p++){
            char c = s.charAt(p);
            if(c>'9')
                sb.append(c);
            else
                tsb.append(c);
        }
 
        //得到part2的index 范围 l+1, i-1.
        int i = l+1;
        while(rc<lc){
            if(s.charAt(i)=='[')
                lc++;
            if(s.charAt(i)==']')
                rc++;
            i++;
        }
        //叠加获取part2的k[encodeString]
        int k= Integer.parseInt(tsb.toString());
        String ts = decodeString(s.substring(l+1,i-1));
        for(int t=0;t<k;t++){
            sb.append(ts);
        }
        //拼接剩余部分的part3
        sb.append(decodeString(s.substring(i)));
        return sb.toString();
    }
}
```
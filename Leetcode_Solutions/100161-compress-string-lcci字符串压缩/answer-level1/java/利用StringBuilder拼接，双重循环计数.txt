### 解题思路
此处撰写解题思路
![图片.png](https://pic.leetcode-cn.com/b811c5a2be320dfa7ea3340c201af12237e55113c03675120dce94df0cfb8bf9-%E5%9B%BE%E7%89%87.png)

### 代码

```java
class Solution {
    public String compressString(String S) {
        if(null==S||0==S.length()){
            return new String();
        }
        StringBuilder sb = new StringBuilder();
        char[] chs = S.toCharArray();
        char ch = chs[0];
        int count=0;
        for(int i=0; i<chs.length; ){
            ch = chs[i]; 
            for(int j=i;j<chs.length;j++){
                if(ch == chs[j]){
                    count++;
                    i++;
                }else if(ch!=chs[j]){
                    sb.append(ch);
                    sb.append(count);
                    count=0;
                    break;
                }
            }
        }
        sb.append(ch);
        sb.append(count);
        return sb.toString().length()>=S.length()?S:sb.toString();
    }
}
```
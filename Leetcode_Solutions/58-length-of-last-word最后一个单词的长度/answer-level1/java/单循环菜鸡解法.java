### 解题思路
直接上代码.
比较简单

### 代码

```java
class Solution {
           //这里的顺序是倒着来的
        public int lengthOfLastWord(String s) {
            if(s.length()==0){return 0;}
            boolean flag=true;//用来标记在字符串的末尾是否有空格.
            int num=s.length()-1;//最后一个数组下标
            if (s.charAt(num)==' ')flag=false;//发现末尾是否有空格
            for(int i=s.length()-1;i>=0;i--){
                if(s.charAt(i)!=' '&&!flag){//空格处理,移动最后一个数组下标,直到找到第一个非空格元素.(消除末尾空格)
                    flag=true;
                    num=i;
                }
                if (s.charAt(i)==' '&&flag)return num-i==0?1:num-i;//找到第一个在字符串字母之间的空格.(不要太在意个?标识符,这个可能是我多虑了,直接num-i就欧克)
                
            }
            return flag?num+1:0;//为了应对'a '这个情况.因为如果在字符串前面没有空格,则上面的哪个也不好使.
        }

}
```
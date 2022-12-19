class Solution {
```
1. 代码块
    public int lengthOfLastWord(String s) {
            int len=0;   
            //从后往前遍历，不是空格键，长度加1
            for(int i=s.length()-1;i>=0;i--){
                if(s.charAt(i)!=' '){
                    len++;
                }
                //长度不为0，说明已经读取到了字符串
                //再遇空格键，说明已经将整个字符串读取完毕
                if(len>0&&s.charAt(i)==' '){
                    break;
                }
        }       
        return len;
        
    }
}
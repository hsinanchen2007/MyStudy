```
class Solution {
    public boolean isNumber(String s) {
        char[] str=s.trim().toCharArray();
        if(str.length==0) return false;
        int sign=-2,num=-2,dot=-2,e=-2;
        for(int i=0;i<str.length;i++){
            if(str[i]>='0'&&str[i]<='9'){
                num=i;
            }else if(str[i]=='e'||str[i]=='E'){
                if(e!=-2||num==-2) return false;
                if(sign==i-2) return false;
                if(i==str.length-1) return false;
                e=i;
            }else if(str[i]=='+'||str[i]=='-'){
                if(i!=-0&&e!=i-1) return false;
                if(i==str.length-1) return false;
                sign=i;
            }else if(str[i]=='.'){
                if(num!=i-1&&i==str.length-1) return false;
                if(e!=-2||dot!=-2) return false;
                dot=i;
            }else{
                return false;
            }
        }
        return true;
    }
}
```
时间2ms, 击败100%, 内存46M, 主站65题提交只击败6%, 在这提交击败100%, 可能这边提交的人少

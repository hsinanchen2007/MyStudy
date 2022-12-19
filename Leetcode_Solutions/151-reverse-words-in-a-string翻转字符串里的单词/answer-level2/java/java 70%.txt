class Solution {
    public String reverseWords(String s) {
        if(s.length()==0)return s;
        char[] ch = s.toCharArray();
        int l = 0;
        int r = ch.length - 1;
        while(l<r){
            char tmp = ch[l];
            ch[l] = ch[r];
            ch[r] = tmp;
            l++;r--;
        }
        //翻转
        StringBuilder sb = new StringBuilder();
        l = 0;
        r = ch.length - 1;
        while(l<ch.length&&ch[l]==' ')l++;
        if(l==ch.length)return "";
        while(r>l&&ch[r]==' ')r--;
        //去除两端空格
        while(l<=r){
            if(ch[l]==' '){
                sb.append(' ');
                while(l<=r&&ch[l]==' ')l++;
                //如果是空格只添加一个
            }else{
                int j = l+1;
                while(j<=r&&ch[j]!=' ')j++;
                for(int i = j-1;i>=l;i--){
                    sb.append(ch[i]);
                }
                l = j;
                //不是空格就找到下一个空格或者末尾位置倒序添加char
            }
        }
        return sb.toString();
    }
}
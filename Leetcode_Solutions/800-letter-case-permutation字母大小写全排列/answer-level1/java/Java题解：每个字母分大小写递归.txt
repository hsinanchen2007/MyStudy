![微信图片_20191119174334.png](https://pic.leetcode-cn.com/e6fd7c4134a40f863c26eb209a1cee310514326ab5fcbc7814c62a20ff381958-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191119174334.png)
```
class Solution {

    private List<String> list = new ArrayList<>();

    public List<String> letterCasePermutation(String S) {
        letterCase(new StringBuilder(S),0);
        return list;
    }

    //每遇到字母，分成大写和小写来递归，最后字符串到底时把它们一个一个收集起来
    private void letterCase(StringBuilder sb,int index){
        for(int i=index;i<sb.length();i++){
            char k = sb.charAt(i);
            if((k>='a'&&k<='z')||(k>='A'&&k<='Z')){
                //第一次递归
                letterCase(sb,i+1);
                if(k>='a'&&k<='z'){
                    sb.replace(i,i+1,(char)(k-32)+"");
                }else{
                    sb.replace(i,i+1,(char)(k+32)+"");
                }
                //第二次递归
                letterCase(sb,i+1);
                return ;
            }
        }
        list.add(sb.toString());
    }
}
```



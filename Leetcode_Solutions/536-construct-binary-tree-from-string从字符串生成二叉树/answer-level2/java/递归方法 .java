![微信截图_20191022112547.png](https://pic.leetcode-cn.com/27f8b2fc49cc5e939e68d7458eb82c3d6d14f1c3242d1125b7bebd892062e63c-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191022112547.png)
```
public static TreeNode str2tree(String s) {
       if(s==null||s.length()==0){
           return null;
       }
        int num=0;
        int index=0;
        boolean neg=false;
        if(s.charAt(index)=='-'){
            neg=true;
            index++;
        }
        while(index<s.length()&&s.charAt(index)>='0'&&s.charAt(index)<='9'){
            num=num*10+s.charAt(index)-'0';
            index++;
        }
        num=neg?-num:num;
        TreeNode node=new TreeNode(num);
        int mid=getSubstring(s,index);
        if(mid>index){
            node.left=str2tree(s.substring(index+1,mid-1));
        }
        if(mid<s.length()){
            node.right=str2tree(s.substring(mid+1,s.length()-1));
        }
        return node;
    }
    public static int getSubstring(String s,int index){
        if(index==s.length()){
            return index;
        }
        int count=1;
        index++;
        while(index<s.length()&&count!=0){
            if(s.charAt(index)=='('){
                count++;
            }
            if(s.charAt(index)==')'){
                count--;
            }
            index++;
        }
        return index;
    }
```

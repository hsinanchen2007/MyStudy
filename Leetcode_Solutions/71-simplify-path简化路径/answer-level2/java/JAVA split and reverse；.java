### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String simplifyPath(String path) {
        int i =0,j=0;
        int count = 0 ;
        int num = 0 ;

        String [] str = path.split("/");
        if(path.length()==0){
            return "";
        }
        if(str.length==0){
            return "/";
        }
          
        String [] ret = new String [str.length];
        rev(str,str.length);
        
        i=0;
        while(i<str.length){
            //System.out.println("cccc="+count);
            if(str[i].equals(".")){
                i++;
            }
            else if(str[i].equals("..")){
                i++;
                count++;
            }
            else if(str[i].length()!=0 && count==0){
                //System.out.println("ffffff");
                ret[j++]=str[i++];
                num++;
            }
            else if(str[i].length()!=0 && count>0){
                i++;
                count--;
            }
            else{
                //System.out.println(str[i]);
                i++;
            }
        }
          System.out.println("num="+num);
          System.out.println("ret="+ret[0]);
          System.out.println("ret="+ret[1]);
        rev(ret,num);
            System.out.println("ret="+ret[0]);
          System.out.println("ret="+ret[1]);
        String rec="/";

        for( i=0;i<num;i++){
            if(i!=num-1)
            rec+=ret[i]+"/";
            else
            rec+=ret[i];
        }

        return rec;
        
    }

    private void rev(String [] str,int len){

        for(int i=0;i<(len)/2;i++){
            String tmp = "" ;
            tmp = str[i];
            str[i]=str[len-1-i];
            str[len-1-i]=tmp;
        }
    }
}
```
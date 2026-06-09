__# 思路：__
每一次添加一个字母，把之前已经添加过的作为一个整体，再和新添加的字母组合，
新的组合的第一组把之前的组合覆盖(仅用1ms)

__# 代码：__

```java []
class Solution {
    public List<String> letterCombinations(String digits) {
       
        List<String> ans=new ArrayList<>();
        
        for(int i=0;i<digits.length();i++){//对每个digits遍历
            int len=ans.size();
            String subStr=mapping(digits.charAt(i));
            if(len==0){
                for(int j=0;j<subStr.length();j++){
                    ans.add(""+subStr.charAt(j));//第一次不用覆盖，直接加
                }
            }else{
                for(int k=0;k<len;k++){
                    for(int m=1;m<subStr.length();m++){
                        ans.add(ans.get(k)+subStr.charAt(m));//加入除了第一组的其他组合
                    }
                    ans.set(k,(ans.get(k)+subStr.charAt(0)));//用第一组组合覆盖之前的低维组合
                }
            }
        }
        return ans;
    }
    
    public static String mapping(char num){//完成数字到字母的映射
        String str=null;
        switch(num){
            case '2'://2
                str="abc";
                break;
            case '3'://3
                str="def";
                break;
            case '4'://4
                str="ghi";
                break;
            case '5'://5
                str="jkl";
                break;
            case '6'://6
                str="mno";
                break;
            case '7'://7
                str="pqrs";
                break;
            case '8'://8
                str="tuv";
                break;
            case '9'://9
                str="wxyz";
                break;
            default:
                str="";
                break;
        }
        return str;
    } 
}
```


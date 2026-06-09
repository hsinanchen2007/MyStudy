### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        if(n==1){
            return "1";
        }else{
            String preStr=countAndSay(n-1);
            String pointStr=preStr.substring(0,1);
            StringBuilder resultStr=new StringBuilder();
            Integer number=new Integer(0);
            for(int i=0;i<a.length();i++){
                if(preStr.substring(i,i+1).equals(pointStr)){
                    number+=1;

                }else{

                    resultStr.append(number.toString());
                    resultStr.append(pointStr);

                    number=1;
                    pointStr=preStr.substring(i,i+1);
                }

            }
            
            if(number!=0){
                resultStr.append(number.toString());
                resultStr.append(pointStr);
                
            }
            return resultStr.toString();
        }

        
    }
}
```
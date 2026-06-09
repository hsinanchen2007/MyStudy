### 解题思路


### 代码

```java
class Solution {
    public int uniqueMorseRepresentations(String[] words) {

List<String> tempt=new ArrayList();
String[] mcode ={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
int num=0;
for(String a:words){
   String code=new String();
    for(int i=0;i<a.length();i++){
int j =a.charAt(i)-'a';
code=code+mcode[j];
    }
    if(num==0){
tempt.add(code);
num++;
    }else{for(int n=0;n<tempt.size();n++){
        if(code.equals(tempt.get(n))){
break;
}else{if(n==tempt.size()-1){
     tempt.add(code);
    num++;
}
   
}}
    }

}

return num;
    }
}
```
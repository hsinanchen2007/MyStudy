### 解题思路


### 代码

```java
class Solution {
    public boolean judgeCircle(String moves) {
int tempt=0;
int tempt1=0;
for(char a:moves.toCharArray()){

if(a=='U'){
tempt++;
}else{if(a=='D'){
     tempt--;
}   
}
if(a=='L'){
tempt1++;
}else{if(a=='R'){
     tempt1--;
}  
}
}
if(tempt==0&&tempt1==0){
    return true;
}else{
    return false;
}
    }
}
```
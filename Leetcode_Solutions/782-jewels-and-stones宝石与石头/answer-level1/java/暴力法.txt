遍历每块石头
```
public int numJewelsInStones(String J, String S) {
        int flag=0; //标记位
        for(int i=0;i<J.length();i++){
             char c = J.charAt(i);
            for(int j=0;j<S.length();j++){
                if(c==S.charAt(j)){
                    flag++;
                }
            }

        }
        return flag;
        
    }
```

### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numTeams(int[] rating) {
        int flag=0;
        for(int i=0;i<rating.length;i++){
            for(int j=i+1;j<rating.length;j++){
                if(rating[i]>rating[j]){
                    for(int k=j+1;k<rating.length;k++){
                        if(rating[j]>rating[k]){
                            flag++;
                        }else{
                            continue;
                        }
                    }
                }else if(rating[i]<rating[j]){
                    for(int k=j+1;k<rating.length;k++){
                        if(rating[j]<rating[k]){
                            flag++;
                        }else{
                            continue;
                        }
                    }
                }
            }
        }
        return flag;
    }
}
```
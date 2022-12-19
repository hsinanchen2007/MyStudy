### 解题思路
 任何一个数字的出现次数  % X ==0 , (X>=2)


### 代码

```csharp
public class Solution {
    public bool HasGroupsSizeX(int[] deck) {
        if(deck==null || deck.Length <=1){
            return false;
        }
        int[] temp=new int[deck.Length];
        bool r=true;
        for(int i=1;i<deck.Length;i++){
            r=true;
            if(deck.Length % i !=0){
                continue;
            } 
            for(int j=0;j<temp.Length;j++){
                temp[j]=0;
            }
            for(int j=0;j<deck.Length;j++){
                temp[deck[j]]++;
            }
            for(int j=0;j<temp.Length;j++){
                if(temp[j]!=0  &&  temp[j] %( deck.Length / i )>0  ){
                    r=false;
                    break;
                }
            }
            if(r){
               return true; 
            }


        }
        return false;
    }
}
```
### 解题思路
题意可以转换为数组中所有数字的出现次数必然能整除X
用一个HashMap记录数组中所有数字出现的次数，从2到数组长度中寻找X，数组长度必然能整除X，可以卡掉一部分运算

### 代码

```java
import java.util.HashMap;
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if(deck.length<=1){
            return false;
        }
        HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>();
        for(int i=0;i<deck.length;i++){
            if(!hm.containsKey(deck[i])){
                hm.put(deck[i],1);
            }else{
                hm.put(deck[i],hm.get(deck[i])+1);
            }
        }
        for(int i=2;i<=deck.length;i++){
            if(deck.length%i!=0){
				continue;
			}
            boolean flag=true;
            for(Integer v:hm.values()){
                if(v%i!=0){
                    flag=false;
                }
            }
            if(flag){
                return flag;
            }
        }
        return false;
    }
}
```
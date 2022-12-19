### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
       
int len = deck.length;
  if(len==1)
        {
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
 
for(int i = 2; i <= deck.length;i++)
{
if(deck.length % i != 0)
{
continue;
}
Boolean flag = true;
  for(Integer v:hm.values()){
                if(v%i!=0){
                    flag=false;
                }
            }

if(flag == true)
{
return true;
}
}
return false;

    }
}
```
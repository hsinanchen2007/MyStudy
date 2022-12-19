### 解题思路
此处撰写解题思路
本题即为求取数组长度和数组内各数字出现频率知否存在最大公约数。记得使用数组额遍历叠加。

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int len=deck.length;
        int [] count=new int[10000];
        for(int c:deck){
            count[c]++;
        }
        ArrayList<Integer> values=new ArrayList<>();
        for(int i=0;i<10000;i++){
            if(count[i]>0)
               values.add(count[i]);
        }
       search: for(int X=2;X<=len;X++){
            if(len%X==0){
                for(int value:values){
                    if(value%X!=0)
                      continue search;
                }
                return true;
            }
        }
        return false;

       

    }
}
```
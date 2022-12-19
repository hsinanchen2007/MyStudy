### 解题思路
判断条件有点坑

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
            int count=0;
            char[] charList=chars.toCharArray();
            Map<Character,Integer> map =new HashMap<Character,Integer>();
            for(char a:charList){
                int temp=0;
                if(map.containsKey(a)){
                    temp=map.get(a);
                    map.put(a,temp+1);
                }else{
                    map.put(a,1);
                }
            }
            //有了字符及个数的map
            Map<Character,Integer> mapTemp;
            for(String i:words){
                int countTemp=0;
                //每个字符串，对应一个map
                mapTemp =new HashMap<Character,Integer>();
                int tempNum=0;
                for(int j=0;j<i.length();j++){
                    if(mapTemp.containsKey(i.charAt(j))){
                        tempNum=mapTemp.get(i.charAt(j));
                        mapTemp.put(i.charAt(j),tempNum+1);
                    }else{
                        mapTemp.put(i.charAt(j),1);
                    }
                }

                //这一步计算是否该字符串的所有元素均在输入的字符集中存在
                int number0=0;
                int number1=0;
                for(char b:mapTemp.keySet()){
                    if(map.containsKey(b)){
                        number0++;
                    }
                }
                for(char b:mapTemp.keySet()){
                    number1++;
                }

                if(number0==number1){
                //开始执行,mapTemp是当前字符串的map
                    for(char b:mapTemp.keySet()){
                        if(map.containsKey(b)){
                            if(map.get(b)<mapTemp.get(b)){
                                countTemp=0;
                                break;
                            }else{
                                countTemp+=mapTemp.get(b);
                            }
                        }
                    }
                }else{
                    continue;
                }
                    count+=countTemp;
                    mapTemp.clear();
            }
            return count;
    }
}
```
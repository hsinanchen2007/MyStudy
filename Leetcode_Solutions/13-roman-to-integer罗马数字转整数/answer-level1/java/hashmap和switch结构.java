### 解题思路
一开始就想到的是用hashmap，然后就去做了，但是没想到空间复杂度和时间复杂度都很高。之后看了一个题解用switch-case结构做的，复杂度降低了。要好好借鉴一下别人的优秀思路~

### 代码

```java
class Solution {
    public int romanToInt(String s) {
            Map<String,Integer> num=new HashMap<>();
            num.put("I",1);
            num.put("V",5);
            num.put("X",10);
            num.put("L",50);
            num.put("C",100);
            num.put("D",500);
            num.put("M",1000);

            char [] str=s.toCharArray();
            // for(int i=0;i<str.length;i++){
            //     System.out.print(str[i]+" "+num.get(String.valueOf(str[i])));
            // }
            // System.out.println();
            int len=str.length;
            int result=0;

            int i=0;
            while(i<str.length){
                if(i<str.length && i+1<str.length && ((str[i]=='I' && (str[i+1]=='V' || str[i+1]=='X')) ||
                        (str[i]=='X' && (str[i+1]=='L' || str[i+1]=='C')) ||
                        (str[i]=='C' && (str[i+1]=='D' || str[i+1]=='M')))){
                    result+=num.get(String.valueOf(str[i+1]))-num.get(String.valueOf(str[i]));
                    i=i+2;
                    continue;
                }
                  result =result+num.get(String.valueOf(str[i]));
                  i+=1;
            }
            return result;
    }
}
```
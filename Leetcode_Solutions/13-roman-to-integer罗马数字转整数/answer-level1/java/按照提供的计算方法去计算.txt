### 解题思路
按照提供的计算方法去计算
先把每个字符对应的数字记录
然后遍历，当后一个比前面大的时候说明是特殊情况此时就用 后面-前面 然后计算剩下的

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        char[] base = {'M', 'D', 'C', 'L',  'X',  'V', 'I'};
        int[] baseNum = {1000,500,100,50,10,5,1};
        int[] res = new int[s.length()];
        for(int i =0;i<s.length();i++){
            for(int j = 0; j<base.length;j++){
                if(s.charAt(i) == base[j]){
                    res[i] = baseNum[j];
                    break;
                }
            }
        }
        int sum =0;
        for(int i=0;i<s.length();i++){
            //当i不为最后一个时   当前当i比下一个小就是特殊当
            if(i<s.length()-1 && res[i] < res[i+1]){  
                sum+=res[i+1]-res[i];
                i++;
            } else{
                sum+=res[i];
            }
        }
        return sum;
    }
}
```
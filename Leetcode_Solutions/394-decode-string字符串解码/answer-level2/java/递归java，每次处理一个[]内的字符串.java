### 解题思路
先用Map记录每一对[]的位置，用[的位置索引与之相对应的]的位置。

然后处理每一个[]内的字符串，遇到第一个[]先递归处理[]内字符串，然后返回
结果后，将这个结果接n次到本递归的返回值上。

### 代码

```java
class Solution {
    //pos记录与'['相对应的']'的位置
    Map<Integer, Integer> pos = new HashMap<Integer, Integer>();
    
    public String decodeString(String s) {
        Stack<Integer> kpos = new Stack<Integer>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '[') {
                kpos.push(i);
            }
            else if (s.charAt(i) == ']') {
                int l = kpos.pop();
                pos.put(l, i);
            }
        }
        return ds(s, 0, s.length());
    }

    public String ds(String s, int start, int finish) {//递归处理 s[start:finish)
        StringBuilder res = new StringBuilder("");
        for (int i = start; i < finish; i++) {
            
            StringBuilder timesb = new StringBuilder();//次数
            int j;//处理第一个[]前的字符串
            for (j = i; j < finish; j++) {
                if (s.charAt(j) >= '0' && s.charAt(j) <= '9') { //数字
                    timesb.append(s.charAt(j)); 
                }
                else if (s.charAt(j) != '[') { //接收到数字外的
                    res.append(s.charAt(j));    //直接接到结果上
                }
                else {  //'['退出
                    break;
                }
            }
            
            if (timesb.toString().equals("")) { //没有数字，即没有[]，也就没有下一层递归，转换结束
                return res.toString();
            }
            Integer time = Integer.parseInt(timesb.toString()); //转换int
            
            int right = pos.get(j);
            
            String substr = ds(s, j + 1, right);
            //接time个
            for (int k = 0; k < time; k++) {
                res.append(substr);
            }
            i = right; //下个处理移到']'后
        }
        return res.toString();
    }
}
```
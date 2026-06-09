### 解题思路
最开始没有考虑大数，将所有可能的组合都放在一个二维数组中进行计算
![image.png](https://pic.leetcode-cn.com/802796288787e887c502db03e6c0da52d389208c16bd5b1c2de5b9b9d0bc0107-image.png)

之后遇到了大数的问题，把整数值存储更改为字符串存储，并编写了用于大数加法判断的puduan函数

![image.png](https://pic.leetcode-cn.com/69b1f6e4feea38202ff921ffbdd310818aceb342416e59a29fd2fe5cbf30cb2a-image.png)


### 代码

```java
class Solution {
    public boolean isAdditiveNumber(String num) {
        String[][] mem = new String[num.length()][num.length()];
        List<List<List<String>>> dp = new ArrayList<>();
        for(int i = 0; i < num.length(); ++i){
            dp.add(new ArrayList<>());
            for(int j = 0; j < num.length(); ++j){
                dp.get(dp.size() - 1).add(new ArrayList<>());
            }
        }
        for(int i = 0; i < num.length(); ++i){
            for(int j = i; j < num.length(); ++j){
                String temp = num.substring(i, j + 1);
                if(temp.charAt(0) == '0' && i != j){
                    mem[i][j] = "";
                }else{
                    mem[i][j] = num.substring(i, j + 1);
                }
            }
        }

        for(int j = 0; j < num.length(); ++j){
            int ii = j + 1;
            for(int jj = ii; jj < num.length(); ++jj){
                List<String> list = dp.get(ii).get(jj);
                list.add(mem[0][j]);
            }
        }
        for(int i = 1; i < num.length(); ++i){
            for(int j = i; j < num.length(); ++j){
                if(mem[i][j].equals("")) continue;
                int ii = i + (j - i + 1);
                List<String> list = dp.get(i).get(j);
                for(int jj = ii; jj < num.length(); ++jj){
                    for(String iii : list){
//                        if(iii + mem[i][j] == mem[ii][jj]){
                        if(puduan(iii, mem[i][j], mem[ii][jj])){
                            List<String> lll
                                    = dp.get(ii).get(jj);
                            lll.add(mem[i][j]);
                            if(jj == num.length() - 1){
                                return true;
                            }
                            break;
                        }
                    }
                }
            }
        }
        return false;
    }

    public boolean puduan(String a1, String a2, String b1){
        if(a1.equals("") || a2.equals("") || b1.equals("")) return false;
        int carry = 0;
        int lenA1 = a1.length();
        int lenA2 = a2.length();
        int lenB1 = b1.length();
        int maxLen = Math.max(lenA1, lenA2);
        maxLen = Math.max(maxLen, lenB1);
        for(int i = 0; i < maxLen; ++i){
            int aa1 = (lenA1 - 1 - i) >= 0 ? a1.charAt(lenA1 - 1 - i) - '0' : 0;
            int aa2 = (lenA2 - 1 - i) >= 0 ? a2.charAt(lenA2 - 1 - i) - '0' : 0;
            int bb1 = (lenB1 - 1 - i) >= 0 ? b1.charAt(lenB1 - 1 - i) - '0' : 0;
            if(((aa1 + aa2 + carry) % 10) != bb1){
                return false;
            }else{
                carry = (aa1 + aa2 + carry) / 10;
            }
        }
        if(carry != 0) return false;
        return true;
    }
}
```
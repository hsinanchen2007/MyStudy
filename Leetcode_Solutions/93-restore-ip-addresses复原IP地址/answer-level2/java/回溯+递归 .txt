### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public static List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();

        if (s.length() < 4 || s.length() > 12) {
            return res;
        }



        int k = 1;//初始第一层


        String[] c = new String[5];//c记录每层字符串

        reback(1, s, res, 0, c);

        return res;

    }

    public static void reback(int k, String s, List<String> res,int l,String[] c){
        // l---记录前几层字符串的总长度
        if(k>4){
            res.add(c[1] + c[2] + c[3] + c[4]);
        }else{
            for(int i=1;i<4;i++){
                String subString = new String();
                if(l+i<=s.length()){
                    subString = s.substring(l, l + i);
                }

                if(k<4){
                    c[k] = subString + ".";
                }else{
                    c[k] = subString;
                }

                int usedLength = l + i;//更新用过的长度
                int restLength = s.length() - usedLength;
                if (restLength >= (4 - k) && restLength <= 3 * (4 - k) &&
                        isSuitable(subString)){
                    reback(k + 1, s, res, l+i,c);
                }
            }
        }
    }

        public static boolean isSuitable(String s){

        if(s.startsWith("0")&&s.length()>1){
            return false;
        }
        int num = Integer.parseInt(s);
        if(num>=0&&num<=255){
            return true;
        }
        return false;
    }

}

```
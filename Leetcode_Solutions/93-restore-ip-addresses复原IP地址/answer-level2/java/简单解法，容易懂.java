写出递归函数，先设置一个depth作为递归深度，start作为指向字符串的指针，用string数组存储每个ip地址段。

首先讲递归的返回条件：
1.可知ip地址为四段，所以递归深度为4的时候返回，如果s[1].length()+s[2].length()+s[3].length()+s[0].length()== s的长度，说明

```
class Solution {
    List<String> list = new LinkedList<String>();
    public List<String> restoreIpAddresses(String s) {
        String[] s1 = new String[4];
        int len = s.length();
        pro(0,0,s1,len,s);
        return list;
    }
    private void pro(int depth, int start,String[] s,int len, String str){
        if(depth == 4){
            if(s[1].length()+s[2].length()+s[3].length()+s[0].length()== len){
                String res = s[0] + "." + s[1] + "." + s[2] + "." + s[3];
                list.add(res);
            }
            return;
        }
        if(len - start >= 1){
            s[depth] = str.substring(start,start + 1);
            pro(depth+1,start+1,s,len,str);
        }else return;
        if(len - start >= 2){
            int d = Integer.parseInt(str.charAt(start)+"");
            if(d > 0) {
                s[depth] = str.substring(start, start + 2);
                pro(depth + 1, start + 2, s, len, str);
            }
            else return;
        }else return;
        if(len - start >= 3){
            int d = Integer.parseInt(str.substring(start,start+3));
            if(d <= 255&&d > 0){
                s[depth] = str.substring(start,start + 3);
                pro(depth+1,start+3,s,len,str);
            }else return;
        }else return;
    }

}
```

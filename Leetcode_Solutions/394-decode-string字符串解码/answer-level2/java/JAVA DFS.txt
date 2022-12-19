```
class Solution {
    public String decodeString(String s) {
        return dfs(s,0)[0];
    }
    public String[] dfs(String s,int idx){ 
    /*返回类型是二维的字符串数组 
    因为不光要返回字符串、还要返回内部括号遍历结束后的idx */ 
        StringBuilder res=new StringBuilder();
        int num=0;
        for(;idx<s.length();idx++){
            char c=s.charAt(idx);
            if(c>='0'&&c<='9'){ // c是数字字符
                num=10*num+(c-'0'); // ×10用于处理多位连续数字
            }
            else if(c=='['){  // 递归处理内部括号子串
                String []substr=dfs(s,idx+1); 
                for(int i=0;i<num;i++){ // res中添加num个substr
                    while(num>0){ // 添加num个子串
                        res.append(substr[0]);
                        num--;
                    }
                }

                idx=Integer.parseInt(substr[1]);
            }
            else if(c==']'){ // 返回结果
                return new String[] {res.toString(),String.valueOf(idx)}; 
            }
            else{ // c是字母
                res.append(c);
            }

        }
         return new String[] {res.toString(),String.valueOf(idx)};

    }
}
```

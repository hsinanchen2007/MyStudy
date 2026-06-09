### 解题思路
就递龟，就硬递！
![QQ截图20200303161728.png](https://pic.leetcode-cn.com/a380632aa3b4241df5eff2fd27513edfeff6e9f16001805c06e6d011a4a1ebaa-QQ%E6%88%AA%E5%9B%BE20200303161728.png)


### 代码

```java
class Solution {
    public List<String> letterCasePermutation(String S) {

        return get_lower_str(S);
    }

    public ArrayList<String> get_lower_str(String S){
        ArrayList<String> res=new ArrayList<>();
        char[] chars_S=S.toCharArray();
        for(int i=0;i<chars_S.length;i++) {
            if(((int)chars_S[i]>=97&&(int)chars_S[i]<=122)||((int)chars_S[i]>=65&&(int)chars_S[i]<=90)){
                ArrayList<String> temp_res=get_lower_str(S.substring(i+1,chars_S.length));
                for(int j=0;j<temp_res.size();j++){
                    res.add(new String(S.substring(0,i+1)+temp_res.get(j)));
                }
                if((int)chars_S[i]>=97&&(int)chars_S[i]<=122){
                    for(int j=0;j<temp_res.size();j++){
                        res.add(new String(S.substring(0,i)+String.valueOf((char)((int)chars_S[i]-32))+temp_res.get(j)));
                    }
                }else{
                    for(int j=0;j<temp_res.size();j++){
                        res.add(new String(S.substring(0,i)+String.valueOf((char)((int)chars_S[i]+32))+temp_res.get(j)));
                    }
                }
                break;

            }

        }
        if(res.size()==0){//传进来的子字符串再也没有字母了
            res.add(S);
        }

        return res;
    }
}
```
暴力解法。
```
class Solution {
    public String shortestSuperstring(String[] A) {
        String str = "";
        List<String> list = new ArrayList<>();
        for(String s : A){
            list.add(s);
            str += s;
        }
        String[] res = new String[]{str};
        check(list,res,"");
        list.clear();
        return res[0];
    }
    
    private void check(List<String> list,String[] res, String s){
        if(list.isEmpty()){
            if(s.length()< res[0].length()){
                res[0] = s;
            }
            return;
        }
        if(s.equals("")){
            //头两个字符串要选取有重合部分的，若不存在，则表示答案为A中所有字符串直接加起来
            for(int i = 0; i < list.size(); i++){
                for(int j = 0; j < list.size(); j++){
                    if(i==j) continue;
                    String left =  list.get(i);
                    String right = list.get(j);
                    String key = right.substring(0,1);
                    int index = left.indexOf(key,left.length()-right.length());
                    while(index>=0){
                        if(right.startsWith(left.substring(index))){
                            String next = s + left.substring(0,index) + right;
                            if(i < j){
                                list.remove(j);
                                list.remove(i);
                            }else{
                                list.remove(i);
                                list.remove(j);
                            }
                            check(list, res, next);
                            if(i < j){
                                list.add(i, left);
                                list.add(j, right);
                            }else{
                                list.add(j, right);
                                list.add(i, left);
                            }
                            break;
                        }
                        index = left.indexOf(key, index + 1);
                    }
                }
            }
        }else{
            boolean flag = true;//标识，剩余字符串中是否不存在与S末尾有重合部分的字符串
            for(int i = 0; i < list.size(); i++){
                String z = list.get(i);
                if(s.contains(z)){
                    list.remove(i);
                    check(list,res, s);
                    list.add(i,z);
                    flag = false;
                    continue;
                }
                String key = z.substring(0,1);
                int index = s.indexOf(key,s.length() - z.length());
                while(index>=0){
                    if(z.startsWith(s.substring(index))){
                        list.remove(i);
                        check(list,res, s.substring(0,index) + z);
                        list.add(i,z);
                        flag = false;
                        break;
                    }
                    index = s.indexOf(key,index+1);
                }
            } 
            //剩余字符串中不存在与S末尾有重合部分的字符串,故所有字符串都测试一遍
            if(flag){
                for(int i = 0; i < list.size(); i++){
                    String z = list.get(i);
                    list.remove(i);
                    check(list,res, s + z);
                    list.add(i,z);
                }
            }
        }
    }
}
```

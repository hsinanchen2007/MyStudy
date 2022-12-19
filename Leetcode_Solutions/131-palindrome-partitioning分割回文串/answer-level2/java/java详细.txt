[blog](https://blog.csdn.net/zzzfeiyu/article/details/100112362)
-  递归+回溯
- 二维数组标识row = left，col = right 表示当前 pla[left,right]是否回文（不使用二维数组每次调用函数也可以，没测试过效率差异，感觉应该会低一点）
- 起始为0到len之间成立的任一pla[0,r_1],然后继续查找第二段pla[r_1 +1,r_2]、[r_2 +1,r_3]...直到[r_n+1,r_(n+1)]不存在，即n+1越界时保存当前 List<String> list，然后回溯

```
class Solution {
    List<List<String>> ret = new ArrayList<>();
    public List<List<String>> partition(String s) {
       /*
       1、二维数组标识row = left，col = right 表示当前 pla[left,right]是否回文
       2、起始为0到len之间成立的任一pla[0,r_1],然后继续查找第二段pla[r_1 +1,r_2]、[r_2 +1,r_3]....直到[r_n+1,r_(n+1)]不存在，即n+1越界时保存当前 List<String> list，然后回溯
       */
        int len = s.length();
        //pla[left,right]是否回文
        boolean[][] pla = new boolean[len][len];
        for(int i=0 ; i<len ; i++){
            for(int j=0 ; j<len ; j++){
                if(i>j){
                    //不存在这样的子串
                    continue;
                }else if(i==j){
                    pla[i][j] = true;
                }else{
                    pla[i][j] = isPlalindrome(s,i,j);
                }
            }
        }
        getPartition(s,0,pla,new ArrayList<String>());
        return ret;
    }
    
    void getPartition(String s, int index, boolean[][] b, List<String> list){
        if(index==s.length()){
            //index已经越界,保存当前结果，返回
            ret.add(new ArrayList(list));
            return ;
        }
        for(int i=index ; i<s.length() ; i++){
            if(b[index][i]){
                //取[index,i+1)段回文串加入list
                list.add(s.substring(index,i+1));
                //递归查找下一段[i+1,?]
                getPartition(s,i+1,b,list);
                //回溯
                list.remove(list.size()-1);
            }
        }
    }

    boolean isPlalindrome(String s, int l, int r){
        while(l<r){
            if(s.charAt(l)!=s.charAt(r)){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
}
```

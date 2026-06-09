题目中没有要求输出最长字符串具体是什么，所以我们只关心能连成的串的长度
flag用于标志已经出现在结果中的字母
pis:用二进制记录出现过的字母，有事反而很方便简单
修改：更简练明了的写法  2019-12-1
```
class Solution {
    public int dfs(List<String> arr,int index, int flag){
        if(index >= arr.size()){
            return 0;
        }
        int max = 0;
        for(int i = index; i < arr.size(); i++){
            int f = 0;
            String str = arr.get(i);
            //检测字符串本身是否有重复字符
            for(char c : str.toCharArray()){
                if((f & 1 <<(c - 'a')) != 0){
                    f = 0;
                    break;
                }
                f |= 1 <<(c - 'a');
            }
            //本身重复或与已经选择的串重复，跳过
            if(f == 0 || (flag & f) != 0) continue;
            //接着dfs
            max = Math.max(max,str.length() + dfs(arr,i + 1,flag | f));
        }
        return max;
    }
    public int maxLength(List<String> arr) {
        return dfs(arr,0,0);
    }
}
```

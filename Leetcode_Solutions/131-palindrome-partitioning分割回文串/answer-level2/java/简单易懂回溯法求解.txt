### 解题思路
从字符串头部开始，每次截取字符串中存在的回文，通过回溯法进行求解。

### 代码

```java
class Solution {
    public List<List<String>> partition(String s) {
        ArrayList<List<String>> result = new ArrayList<List<String>>();
        if (s.length() == 0) return result;
        dfs(0,s,result,new ArrayList<String>());
        return result;
    }

    public void dfs(int index,String s,List<List<String>> result,ArrayList<String> current){
        //遍历完成
        if (index == s.length()) {
            //添加进结果中（由于java存储机制问题，建立新的数组）
            result.add(new ArrayList<String>(current));
            return;
        }
        //将字符串分割，依次判断是否为回文
        for (int i = index;i <= s.length()-1;i++){
            //判断所选是否为回文
            if (judge(s.substring(index,i+1))) {
                current.add(s.substring(index,i+1));
                //判断剩余字符串是否由多个回文构成
                dfs(i+1,s,result,current);
                //回溯
                current.remove(current.size()-1);
            }
        }
        

    }
    //双指针判断是否为回文
    public boolean judge(String sub){
        int first = 0;
        int second = sub.length()-1;
        while (first < second){
            if (sub.charAt(first) == sub.charAt(second)) {
                first++;
                second--;
            }else return false;
        }
        return true;
    }
}
```
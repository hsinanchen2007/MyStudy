### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private List<String> list=new ArrayList<>();
    private StringBuilder path=new StringBuilder();
    private boolean [] used=new boolean[10];  //字符串长度在1到9之间
    public String[] permutation(String S) {
        dfs(S);
        String [] res=new String[list.size()];
        for(int i=0;i<list.size();i++)
            res[i]=list.get(i);
        return res;
    }

    private void dfs(String S){
        if(path.length()==S.length()){
            list.add(new String(path.toString()));
            return ;
        }
        for(int i=0;i<S.length();i++)
        {
            if(!used[i])
            {
                path.append(S.charAt(i));
                used[i]=true;
                dfs(S);
                used[i]=false;
                path.deleteCharAt(path.length()-1);
            }
        }
    }
}
```